/*
** asktask.c for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer/server
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Wed May 27 11:30:45 2015 Adrien Vasseur
** Last update Sun Jun  7 21:56:40 2015 Adrien Vasseur
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"network/define_server.h"
#include	"network/define_packet.h"
#include	"network/packets/newtask.h"
#include	"network/packets/asktask.h"

int		asktask(t_socket *socket, t_scene **scenes)
{
  if (socket->state != WORKING)
    {
      socket->state = WAITING;
      return (newtask(socket, scenes));
    }
  return (EXIT_SUCCESS);
}
