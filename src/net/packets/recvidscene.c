/*
** recvidscene.c for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Mon Jun  1 18:49:54 2015 Adrien Vasseur
** Last update Sun Jun  7 16:34:39 2015 Adrien Vasseur
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"my.h"
#include	"net/define_client.h"
#include	"net/define_packet.h"
#include	"net/packets/asktask.h"
#include	"net/packets/recvidscene.h"

int		recvidscene(t_client *client, t_packet *packet)
{
  t_write_data	data;
  int		i;

  i = 0;
  while (i < 4)
    {
      data.m_char[i] = packet->data[i];
      i++;
    }
  if (client->scenes != NULL)
    client->scenes->id = data.m_int[0];
  printf("[INFO] Scene has id %d\n", data.m_int[0]);
  return (EXIT_SUCCESS);
}
