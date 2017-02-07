/*
** asktask.c for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer/pas_touche_vasseu_g_tests
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Tue May 12 10:15:52 2015 Adrien Vasseur
** Last update Sun Jun  7 18:57:35 2015 Adrien Vasseur
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"my.h"
#include	"net/define_client.h"
#include	"net/define_packet.h"
#include	"net/my_packet.h"
#include	"net/packets/asktask.h"

int		asktask(int fd)
{
  t_packet	pack;

  pack.id.m_long = ASKTASK_MESSAGE;
  pack.size.m_long = 0;
  printf("[INFO] Requesting new task\n");
  return (send_packet(fd, &pack));
}
