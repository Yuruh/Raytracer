/*
** my_receiver.c for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer/pas_touche_vasseu_g_tests
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Mon May 11 21:35:03 2015 Adrien Vasseur
** Last update Sun Jun  7 19:48:10 2015 Adrien Vasseur
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<string.h>
#include	<errno.h>
#include	"my.h"
#include	"net/define_client.h"
#include	"net/define_packet.h"
#include	"net/my_packet.h"
#include	"net/my_fd_readable.h"
#include	"net/packets/asktask.h"
#include	"net/my_receiver.h"

static char	*add_to_buff(char *buff, size_t *b_size,
			    char *data, ssize_t d_size)
{
  size_t	pos;
  size_t	i;

  pos = (*b_size);
  (*b_size) += d_size;
  if ((buff = realloc(buff, (*b_size))) == NULL)
    return (NULL);
  i = pos;
  while (i < (*b_size))
    {
      buff[i] = data[i - pos];
      i++;
    }
  return (buff);
}

static int	my_treat(t_client *client)
{
  char		reader[NET_BUFFER_SIZE];
  ssize_t	ret;
  t_packet	packet;

  if ((ret = read(client->my_socket, reader, NET_BUFFER_SIZE)) > 0)
    {
      if ((client->buff = add_to_buff(client->buff, &(client->buff_size),
				      reader, ret)) == NULL)
	return (EXIT_FAILURE);
      if (new_packet(client->buff, client->buff_size) == EXIT_SUCCESS)
	{
	  if (recv_packet(client, &packet) == EXIT_FAILURE)
	    return (EXIT_FAILURE);
	  if (treat_packet(client, &packet) == EXIT_FAILURE)
	    return (EXIT_FAILURE);
	}
    }
  else
    {
      client->connected = 0;
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int		my_receiver(t_client *client)
{
  client->buff = NULL;
  client->buff_size = 0;
  while (client->connected == 1)
    {
      while (has_fd_readable(client) == EXIT_SUCCESS)
	{
	  if (my_treat(client) == EXIT_FAILURE)
	    return (EXIT_FAILURE);
	}
      usleep(100000);
      if (client->scenes != NULL && client->scenes->data->has_win != 1)
	asktask(client->my_socket);
    }
  return (EXIT_FAILURE);
}
