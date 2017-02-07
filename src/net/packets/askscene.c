/*
** askscene.c for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Wed Jun  3 15:16:48 2015 Adrien Vasseur
** Last update Wed Jun  3 16:41:37 2015 Adrien Vasseur
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"my.h"
#include	"net/define_client.h"
#include	"net/define_packet.h"
#include	"net/my_packet.h"
#include	"net/packets/askscene.h"

int		askscene(int fd, size_t id)
{
  t_packet	pack;
  t_write_data	data;

  pack.id.m_int[0] = ASKSCENE_MESSAGE;
  pack.size.m_long = 8;
  data.m_long = id;
  pack.data = data.m_char;
  printf("[INFO] Requesting new scene : %ld\n", data.m_long);
  return (send_packet(fd, &pack));
}
