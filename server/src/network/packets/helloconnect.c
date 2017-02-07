/*
** helloconnect.c for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer/pas_touche_vasseu_g_tests/server
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Mon May 11 18:02:23 2015 Adrien Vasseur
** Last update Sat May 30 19:26:23 2015 Adrien Vasseur
*/

#include	<stdlib.h>
#include	"network/define_server.h"
#include	"network/define_packet.h"
#include	"network/my_packet.h"
#include	"network/packets/helloconnect.h"

int		helloconnect(int fd)
{
  t_packet	pack;
  t_write_data	data;

  pack.id.m_int[0] = HELLOCONNECT_MESSAGE;
  pack.size.m_long = 4;
  data.m_int[0] = PROTOCOL;
  pack.data = data.m_char;
  return (send_packet(fd, &pack));
}
