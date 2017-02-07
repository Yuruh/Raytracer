/*
** my_packet.c for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer/pas_touche_vasseu_g_tests
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Mon May 11 13:40:29 2015 Adrien Vasseur
** Last update Sun Jun  7 20:42:49 2015 Adrien Vasseur
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"network/define_server.h"
#include	"network/define_packet.h"
#include	"network/packets/asktask.h"
#include	"network/packets/recvscene.h"
#include	"network/packets/recvidscene.h"
#include	"network/packets/askscene.h"
#include	"network/packets/recvresult.h"
#include	"network/my_packet.h"

int		new_packet(t_socket *socket)
{
  t_write_data	m_size;
  int		i;

  if (socket->buff_size < 5)
    return (0);
  m_size.m_long = 0;
  i = 1;
  while (i < 5)
    {
      m_size.m_char[i - 1] = socket->buff[i];
      i++;
    }
  if (socket->buff[0] <= 0 || socket->buff[0] > RECVRESULT_MESSAGE
      || m_size.m_long < 0)
    {
      socket->connected = 0;
      write(socket->socket, &("Fuck sake man!\n"), 15);
      close(socket->socket);
      return (2);
    }
  if (m_size.m_int[0] + 5 > (int) socket->buff_size)
    return (0);
  return (1);
}

static int	rem_packet(t_socket *client, t_packet *packet)
{
  size_t	size;
  size_t	i;
  char		*buff;

  size = packet->size.m_long + 5;
  if (size >= client->buff_size)
    {
      free(client->buff);
      client->buff = NULL;
      client->buff_size = 0;
      return (EXIT_SUCCESS);
    }
  if ((buff = malloc(sizeof(*buff) * (client->buff_size - size))) == NULL)
    return (EXIT_FAILURE);
  i = size;
  while (i < client->buff_size)
    {
      buff[i - size] = client->buff[i];
      i++;
    }
  free(client->buff);
  client->buff_size -= size;
  client->buff = buff;
  return (EXIT_SUCCESS);
}

int		recv_packet(t_socket *client, t_packet *packet)
{
  int		i;
  int		j;

  packet->id.m_long = 0;
  packet->size.m_long = 0;
  packet->id.m_char[0] = client->buff[0];
  i = 1;
  while (i - 1 < 4)
    {
      packet->size.m_char[i - 1] = client->buff[i];
      i++;
    }
  if (packet->size.m_long < 0)
    return (EXIT_FAILURE);
  if ((packet->data = malloc(sizeof(*(packet->data)) *
			     (size_t) packet->size.m_long)) == NULL)
    return (EXIT_FAILURE);
  j = 0;
  while (j < packet->size.m_int[0])
    {
      packet->data[j] = client->buff[i];
      j++;
      i++;
    }
  return (rem_packet(client, packet));
}

int		treat_packet(t_socket *socket, t_packet *packet,
			     t_scene **scenes)
{
  if (packet->id.m_long == ASKTASK_MESSAGE)
    return (asktask(socket, scenes));
  if (packet->id.m_long == ASKSCENE_MESSAGE)
    return (askscene(socket, packet, scenes));
  if (packet->id.m_long == SENDSCENE_MESSAGE)
    {
      if (recvscene(socket, packet, scenes) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      return (recvidscene(socket->socket, (*scenes)->id));
    }
  if (packet->id.m_long == SENDRESULT_MESSAGE)
    return (recvresult(socket, packet, scenes));
  return (EXIT_FAILURE);
}

int		send_packet(int fd, t_packet *packet)
{
  if (write(fd, &(packet->id.m_char[0]), 1) != 1)
    return (EXIT_FAILURE);
  if (write(fd, &(packet->size.m_int[0]), 4) != 4)
    return (EXIT_FAILURE);
  if (packet->size.m_int[0] != 0)
    {
      if (write(fd, packet->data, (unsigned int) packet->size.m_long)
	  != packet->size.m_long)
	return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
