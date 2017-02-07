/*
** recvscene.c for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer/server
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Fri May 29 10:07:00 2015 Adrien Vasseur
** Last update Sun Jun  7 21:33:15 2015 Adrien Vasseur
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"my.h"
#include	"network/define_packet.h"
#include	"network/define_server.h"
#include	"network/my_scene.h"
#include	"network/my_tasks.h"
#include	"network/packets/newtask.h"
#include	"network/packets/recvscene.h"

static void		*read_data(char *buff, size_t len)
{
  char		*dat;
  size_t	i;

  if ((dat = malloc(len)) == NULL)
    return (NULL);
  i = 0;
  while (i < len)
    {
      dat[i] = buff[i];
      i++;
    }
  return (dat);
}

static void	sendtask_all(t_socket *client, t_socket *actual,
			     t_scene **scenes)
{
  while (client != NULL)
    {
      if (client->state == WAITING && client != actual)
	newtask(client, scenes);
      client = client->next;
    }
}

int		recvscene(t_socket *client, t_packet *packet,
			  t_scene **scenes)
{
  t_data	*data;

  data = read_data(packet->data, sizeof(*data));
  if (data->width <= 0 || data->height <= 0)
    {
      fprintf(stderr, "[ERROR] Bad scene received\n");
      free(packet->data);
      return (EXIT_FAILURE);
    }
  if (add_scene(scenes, packet->data, data, packet->size.m_long)
      == EXIT_FAILURE)
    return (EXIT_FAILURE);
  (*scenes)->client = client;
  sendtask_all(*(client->all), client, scenes);
  return (EXIT_SUCCESS);
}
