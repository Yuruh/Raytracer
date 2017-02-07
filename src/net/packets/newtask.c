/*
** newtask.c for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Tue Jun  2 00:01:16 2015 Adrien Vasseur
** Last update Sun Jun  7 00:16:56 2015 Adrien Vasseur
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"my.h"
#include	"go.h"
#include	"net/define_client.h"
#include	"net/define_packet.h"
#include	"net/my_packet.h"
#include	"net/packets/asktask.h"
#include	"net/packets/askscene.h"
#include	"net/my_calculator.h"
#include	"net/packets/newtask.h"

int		newtask(t_client *client, t_packet *packet)
{
  t_task	*data;

  data = (t_task *) packet->data;
  data->next = client->tasks;
  client->tasks = data;
  printf("[INFO] New task received!\n");
  if (my_calculator(client) == EXIT_FAILURE)
    return (askscene(client->my_socket, data->id));
  usleep(100000);
  return (asktask(client->my_socket));
}
