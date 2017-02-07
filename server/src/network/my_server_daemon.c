/*
** my_server_daemon.c for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer/pas_touche_vasseu_g_tests/server/src/network
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Thu Mar 26 09:28:22 2015 Adrien Vasseur
** Last update Sun Jun  7 21:53:11 2015 Adrien Vasseur
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<unistd.h>
#include	<pthread.h>
#include	"network/define_server.h"
#include	"network/define_packet.h"
#include	"network/my_fd_readable.h"
#include	"network/my_data_receive.h"
#include	"network/my_add_client.h"
#include	"network/my_receiver.h"
#include	"network/packets/helloconnect.h"
#include	"network/my_server_daemon.h"

static int	read_packet(t_socket *client, t_scene **scenes)
{
  while (has_fd_readable(client) == EXIT_SUCCESS)
    {
      if (my_receiver(client, scenes) == EXIT_FAILURE)
	return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

static void	clean_clients(t_socket **clients, t_scene *scenes)
{
  t_socket	*tmp;
  t_socket	*save;

  tmp = (*clients);
  while (tmp != NULL)
    {
      if (tmp->connected == 0)
	{
	  save = tmp;
	  tmp = tmp->next;
	  my_rem_client(clients, save, scenes);
	}
      else
	tmp = tmp->next;
    }
}

void		*my_daemon(void *ptr)
{
  t_socket	**clients;
  t_socket	*tmp;
  t_scene	*scenes;

  clients = (t_socket **)ptr;
  scenes = NULL;
  printf("[INFO] Daemon started!\n");
  while (g_running == 0)
    {
      tmp = (*clients);
      while (tmp != NULL)
	{
	  if (read_packet(tmp, &scenes) == EXIT_FAILURE)
	    tmp->connected = 0;
	  if (tmp->state == CONNECTING)
	    {
	      helloconnect(tmp->socket);
	      tmp->state = WAITING;
	    }
	  tmp = tmp->next;
	}
      clean_clients(clients, scenes);
    }
  printf("[INFO] Daemon stopped!\n");
  return (ptr);
}
