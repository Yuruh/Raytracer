/*
** sendresult.c for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Thu Jun  4 16:25:04 2015 Adrien Vasseur
** Last update Sun Jun  7 00:48:07 2015 Adrien Vasseur
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"my.h"
#include	"net/define_client.h"
#include	"net/define_packet.h"
#include	"net/packets/sendresult.h"

static void	send_header(t_client *client, t_packet *pack, t_task *task)
{
  write(client->my_socket, &(pack->id.m_char[0]), 1);
  write(client->my_socket, &(pack->size.m_char[0]), 4);
  write(client->my_socket, &(task->id), sizeof(task->id));
  write(client->my_socket, &(task->pt), sizeof(task->pt));
  write(client->my_socket, &(task->size), sizeof(task->size));
}

int		sendresult(t_client *client, t_scene *scene, t_task *task)
{
  t_packet	pack;
  int		x;
  int		y;
  int		i;

  pack.id.m_char[0] = SENDRESULT_MESSAGE;
  pack.size.m_int[0] = task->size.y * task->size.x * 4 + sizeof(task->id) +
    sizeof(t_vec2i) * 2 + sizeof(t_blur) * task->size.x * task->size.y;
  printf("[INFO] Sending %d bytes of task result...\n", pack.size.m_int[0]);
  send_header(client, &pack, task);
  y = task->pt.y;
  while (y < task->pt.y + task->size.y)
    {
      x = task->pt.x;
      i = y * scene->data->win.size_line + x * scene->data->win.bpp / 8;
      write(client->my_socket, &(scene->data->win.data[0][i]),
	    scene->data->win.bpp / 8 * task->size.x);
      write(client->my_socket, &(scene->data->blur[y][task->pt.x]),
	    sizeof(t_blur) * task->size.x);
      usleep(10000);
      y++;
    }
  return (EXIT_SUCCESS);
}
