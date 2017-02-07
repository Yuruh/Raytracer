/*
** my_packet.c for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer/pas_touche_vasseu_g_tests/client
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Mon May 11 13:32:17 2015 Adrien Vasseur
** Last update Sat Jun  6 23:57:07 2015 Adrien Vasseur
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my.h"
#include	"net/define_packet.h"
#include	"net/define_client.h"
#include	"net/packets/helloconnect.h"
#include	"net/packets/asktask.h"
#include	"net/packets/sendscene.h"
#include	"net/packets/recvidscene.h"
#include	"net/packets/newtask.h"
#include	"net/packets/recvscene.h"
#include	"net/packets/recvresult.h"
#include	"net/my_packet.h"

int		new_packet(char *buff, size_t size)
{
  t_write_data	m_size;
  int		i;

  if (size < 5)
    return (EXIT_FAILURE);
  m_size.m_long = 0;
  i = 1;
  while (i < 5)
    {
      m_size.m_char[i - 1] = buff[i];
      i++;
    }
  if (m_size.m_long + 5 > (int) size)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int		treat_packet(t_client *client, t_packet *packet)
{
  if (packet->id.m_int[0] == HELLOCONNECT_MESSAGE)
    {
      if (helloconnect(packet) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      if (client->scenes == NULL)
	return (asktask(client->my_socket));
      return (sendscene(client));
    }
  else if (packet->id.m_int[0] == RECVIDSCENE_MESSAGE)
    return (recvidscene(client, packet));
  else if (packet->id.m_int[0] == NEWTASK_MESSAGE)
    return (newtask(client, packet));
  else if (packet->id.m_int[0] == NEWSCENE_MESSAGE)
    return (recvscene(client, packet));
  else if (packet->id.m_int[0] == RECVRESULT_MESSAGE)
    return (recvresult(client, packet));
  return (EXIT_FAILURE);
}

static int	rem_packet(t_client *client, t_packet *packet)
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

int		recv_packet(t_client *client, t_packet *packet)
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
  if (packet->size.m_int[0] <= 0)
    return (EXIT_FAILURE);
  if ((packet->data = malloc(sizeof(*(packet->data)) *
			     (size_t) packet->size.m_long)) == NULL)
    return (EXIT_FAILURE);
  j = 0;
  while (j < packet->size.m_long)
    {
      packet->data[j] = client->buff[i];
      j++;
      i++;
    }
  return (rem_packet(client, packet));
}

int		send_packet(int fd, t_packet *packet)
{
  if (write(fd, &(packet->id.m_char[0]), 1) != 1)
    return (EXIT_FAILURE);
  if (write(fd, &(packet->size.m_int[0]), 4) != 4)
    return (EXIT_FAILURE);
  if (packet->size.m_long != 0)
    {
      if (write(fd, packet->data, (unsigned int) packet->size.m_long)
	  != packet->size.m_long)
	return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
