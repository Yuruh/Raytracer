/*
** helloconnect.c for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer/pas_touche_vasseu_g_tests
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Mon May 11 22:11:03 2015 Adrien Vasseur
** Last update Sun Jun  7 17:14:26 2015 Adrien Vasseur
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"my.h"
#include	"net/define_client.h"
#include	"net/define_packet.h"
#include	"net/packets/helloconnect.h"

int		helloconnect(t_packet *packet)
{
  t_write_data	data;
  int		i;

  i = 0;
  while (i < 4)
    {
      data.m_char[i] = packet->data[i];
      i++;
    }
  if (data.m_int[0] != PROTOCOL)
    {
      fprintf(stderr, "[ERROR] Bad protocol version\n");
      return (EXIT_FAILURE);
    }
  printf("[INFO] Protocol initialized\n");
  return (EXIT_SUCCESS);
}
