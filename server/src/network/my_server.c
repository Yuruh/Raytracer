/*
** my_server.c for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer/pas_touche_vasseu_g_tests/server/src
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Tue Mar 24 00:22:13 2015 Adrien Vasseur
** Last update Sun Jun  7 21:32:50 2015 Adrien Vasseur
*/

#include		<stdlib.h>
#include		<stdio.h>
#include		<unistd.h>
#include		<sys/types.h>
#include		<sys/socket.h>
#include		<netdb.h>
#include		<arpa/inet.h>
#include		<pthread.h>
#include		"network/my_server.h"
#include		"network/define_server.h"
#include		"network/my_server_utils.h"
#include		"network/my_server_daemon.h"
#include		"network/my_fd_readable.h"
#include		"network/my_add_client.h"
#include		"network/my_server.h"

static int		init_socket(t_socket *server, unsigned short port)
{
  struct protoent	*protocol;

  protocol = getprotobyname("TCP");
  if ((server->socket = socket(AF_INET, SOCK_STREAM, protocol->p_proto)) == -1)
    return (my_server_error("Error : unable to create socket\n"));
  server->addr.sin_family = AF_INET;
  server->addr.sin_addr.s_addr = INADDR_ANY;
  server->addr.sin_port = htons(port);
  if (bind(server->socket, (struct sockaddr *)&(server->addr),
	   sizeof(server->addr)) == -1)
    return (my_server_error("Error : unable to bind socket\n"));
  if (listen(server->socket, 1) == -1)
    return (my_server_error("Error : unable to start listen\n"));
  printf("[INFO] Server started on port %d\n", port);
  return (EXIT_SUCCESS);
}

static int		my_init(t_socket **clients, pthread_t *daemon)
{
  g_running = 0;
  (*clients) = NULL;
  if (pthread_create(daemon, NULL, &my_daemon, clients) != 0)
    {
      printf("[ERROR] Unable to start daemon\n");
      return (EXIT_FAILURE);
    }
  else
    printf("[INFO] Server daemon started\n");
  return (EXIT_SUCCESS);
}

static void		my_close(pthread_t *daemon, t_socket **clients,
				 t_socket *server)
{
  printf("[INFO] Stopping server...\n");
  pthread_cancel(*daemon);
  pthread_join(*daemon, NULL);
  close(server->socket);
  my_free_client(clients);
}

int			my_server(unsigned short port)
{
  int			addr_size;
  pthread_t		daemon;
  t_socket		server;
  t_socket		*clients;
  t_socket		*new;

  addr_size = sizeof(struct sockaddr_in);
  if (init_socket(&server, port) == -1)
    return (EXIT_FAILURE);
  if (my_init(&clients, &daemon) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  while (g_running == 0)
    {
      if (has_fd_readable(&server) == EXIT_SUCCESS)
	{
	  if ((new = malloc(sizeof(*new))) == NULL)
	    g_running = 1;
	  else if ((new->socket = accept(server.socket,
					 (struct sockaddr *)&(new->addr),
					 (socklen_t *)&addr_size)) > 0)
	    my_add_client(&clients, new);
	}
    }
  my_close(&daemon, &clients, &server);
  return (EXIT_SUCCESS);
}
