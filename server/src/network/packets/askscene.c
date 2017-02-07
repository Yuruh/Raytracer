/*
** askscene.c for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer/server
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Wed Jun  3 15:48:45 2015 Adrien Vasseur
** Last update Sun Jun  7 17:44:39 2015 Adrien Vasseur
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"network/define_packet.h"
#include	"network/define_server.h"
#include	"network/packets/sendscene.h"
#include	"network/packets/askscene.h"

static t_scene	*find_scene(size_t id, t_scene *scenes)
{
  while (scenes != NULL)
    {
      if (scenes->id == id)
	return (scenes);
      scenes = scenes->next;
    }
  return (NULL);
}

int		askscene(t_socket *socket, t_packet *packet, t_scene **scenes)
{
  t_write_data	data;
  t_scene	*scene;
  ssize_t	i;

  i = 0;
  data.m_long = 0;
  while (i < packet->size.m_long && i < 8)
    {
      data.m_char[i] = packet->data[i];
      i++;
    }
  if ((scene = find_scene(data.m_long, (*scenes))) != NULL)
    return (sendscene(socket, scene));
  return (EXIT_SUCCESS);
}
