/*
** my_receiver.c for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer/pas_touche_vasseu_g_tests
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Mon May 11 21:35:03 2015 Adrien Vasseur
** Last update Sun Jun  7 20:43:26 2015 Adrien Vasseur
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"network/define_server.h"
#include	"network/define_packet.h"
#include	"network/my_packet.h"
#include	"network/my_receiver.h"

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

int		my_receiver(t_socket *socket, t_scene **scenes)
{
  char		reader[BUFFER_SIZE];
  ssize_t	ret;
  t_packet	packet;
  char		error;

  if ((ret = read(socket->socket, reader, BUFFER_SIZE)) >= 0)
    {
      if (ret == 0)
	return (EXIT_FAILURE);
      if ((socket->buff = add_to_buff(socket->buff, &(socket->buff_size),
				      reader, ret)) == NULL)
	return (EXIT_FAILURE);
      if ((error = new_packet(socket)) == 1)
	{
	  if (recv_packet(socket, &packet) == EXIT_FAILURE)
	    return (EXIT_FAILURE);
	  if (treat_packet(socket, &packet, scenes) == EXIT_FAILURE)
	    return (EXIT_FAILURE);
	}
      if (error == 2)
	return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
