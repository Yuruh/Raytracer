/*
** sendscene.c for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer/server
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Wed Jun  3 17:19:34 2015 Adrien Vasseur
** Last update Sun Jun  7 17:46:14 2015 Adrien Vasseur
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"network/define_server.h"
#include	"network/define_packet.h"
#include	"network/my_packet.h"
#include	"network/packets/sendscene.h"

int		sendscene(t_socket *socket, t_scene *scene)
{
  char		id;
  unsigned int	packet_size;

  if (scene != NULL)
    {
      id = NEWSCENE_MESSAGE;
      packet_size = scene->raw_size + sizeof(scene->id);
      printf("[INFO] Uploading %d bytes...\n", packet_size);
      write(socket->socket, &id, sizeof(id));
      write(socket->socket, &packet_size, sizeof(packet_size));
      write(socket->socket, &(scene->id), sizeof(scene->id));
      write(socket->socket, scene->raw, scene->raw_size);
      printf("[INFO] Uploaded!\n");
    }
  return (EXIT_SUCCESS);
}
