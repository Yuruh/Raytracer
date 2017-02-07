/*
** my_fd_readable.c for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer/pas_touche_vasseu_g_tests/server
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Mon Mar 30 23:27:39 2015 Adrien Vasseur
** Last update Tue May 12 12:05:48 2015 Adrien Vasseur
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"network/define_server.h"
#include	"network/my_fd_readable.h"

int		has_fd_readable(t_socket *socket)
{
  int		ret;

  FD_ZERO(&(socket->fs));
  FD_SET(socket->socket, &(socket->fs));
  socket->timeout.tv_sec = 0;
  socket->timeout.tv_usec = 100;
  if ((ret = select(socket->socket + 1, &(socket->fs), NULL, NULL,
		    &(socket->timeout))) == -1)
    {
      socket->connected = 0;
      close(socket->socket);
      return (EXIT_FAILURE);
    }
  else if (ret > 0)
    return (EXIT_SUCCESS);
  return (EXIT_FAILURE);
}
