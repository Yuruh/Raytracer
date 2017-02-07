/*
** sendresult.c for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer/server
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Fri Jun  5 00:20:03 2015 Adrien Vasseur
** Last update Sun Jun  7 22:02:46 2015 Adrien Vasseur
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"my.h"
#include	"network/define_packet.h"
#include	"network/define_server.h"
#include	"network/my_packet.h"
#include	"network/packets/sendresult.h"

int		sendresult(t_socket *client, t_packet *packet)
{
  t_packet	pack;

  pack.id.m_char[0] = RECVRESULT_MESSAGE;
  pack.size.m_long = packet->size.m_long;
  pack.data = packet->data;
  printf("[INFO] Uploading %d bytes to RayTracer...\n", pack.size.m_int[0]);
  return (send_packet(client->socket, &pack));
}
