/*
** recvidscene.c for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer/server
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Sat May 30 19:17:58 2015 Adrien Vasseur
** Last update Sat May 30 19:27:26 2015 Adrien Vasseur
*/

#include	<stdlib.h>
#include	"network/define_packet.h"
#include	"network/define_server.h"
#include	"network/my_packet.h"

int		recvidscene(int fd, size_t id)
{
  t_packet	pack;
  t_write_data	data;

  pack.id.m_int[0] = RECVIDSCENE_MESSAGE;
  pack.size.m_long = sizeof(long);
  data.m_long = id;
  pack.data = data.m_char;
  return (send_packet(fd, &pack));
}
