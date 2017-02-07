/*
** my_client.c for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer/pas_touche_vasseu_g_tests/client/src/network
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Tue Mar 24 00:53:28 2015 Adrien Vasseur
** Last update Sun Jun  7 18:20:30 2015 Adrien Vasseur
*/

#include		<stdlib.h>
#include		<stdio.h>
#include		<unistd.h>
#include		<sys/types.h>
#include		<sys/socket.h>
#include		<netinet/in.h>
#include		<netdb.h>
#include		<arpa/inet.h>
#include		"my.h"
#include		"parse_ip.h"
#include		"net/define_client.h"
#include		"net/define_packet.h"
#include		"net/my_receiver.h"
#include		"net/my_scene.h"
#include		"net/my_client.h"

static int		init_socket(char *server, unsigned short port)
{
  int			my_socket;
  struct sockaddr_in	addr;
  struct protoent	*protocol;

  protocol = getprotobyname("TCP");
  if ((my_socket = socket(AF_INET, SOCK_STREAM, protocol->p_proto)) == -1)
    {
      fprintf(stderr, "Error : unable to create socket\n");
      return (-1);
    }
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = inet_addr(server);
  addr.sin_port = htons(port);
  if (connect(my_socket, (struct sockaddr*)&addr, sizeof(addr)) == -1)
    {
      fprintf(stderr, "Error : unable to connect socket\n");
      return (-1);
    }
  return (my_socket);
}

int			my_client(t_ip *ip, t_data *dat)
{
  t_client		client;

  if (ip->ip == NULL)
    {
      if (ip->port != 0)
	fprintf(stderr, "[ERROR] No ip address set\n");
      return (EXIT_FAILURE);
    }
  client.tasks = NULL;
  client.scenes = NULL;
  if (dat != NULL)
    {
      if (net_add_scene(&(client.scenes), 0, dat) == EXIT_FAILURE)
	return (EXIT_FAILURE);
    }
  if ((client.my_socket = init_socket(ip->ip, ip->port)) == -1)
    return (EXIT_FAILURE);
  printf("[INFO] Successfully connected to the server!\n");
  client.connected = 1;
  my_receiver(&client);
  printf("[INFO] Exiting...\n");
  close(client.my_socket);
  return (EXIT_SUCCESS);
}
