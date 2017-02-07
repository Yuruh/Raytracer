/*
** recvresult.c for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer/server
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Thu Jun  4 23:53:47 2015 Adrien Vasseur
** Last update Sun Jun  7 21:57:01 2015 Adrien Vasseur
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"my.h"
#include	"network/define_packet.h"
#include	"network/define_server.h"
#include	"network/my_tasks.h"
#include	"network/packets/sendresult.h"
#include	"network/packets/recvresult.h"

static size_t	get_scene_id(char *buff)
{
  t_write_data	data;
  size_t	i;

  i = 0;
  while (i < sizeof(size_t))
    {
      data.m_char[i] = buff[i];
      i++;
    }
  return (data.m_long);
}

static t_scene	*get_scene(t_scene *scene, size_t id)
{
  while (scene != NULL)
    {
      if (scene->id == id)
	return (scene);
      scene = scene->next;
    }
  return (NULL);
}

static int	get_task(t_scene *scene, char *buff)
{
  t_vec2i	*pt;
  t_task	*task;

  pt = (t_vec2i *) (buff + sizeof(size_t));
  task = scene->tasks;
  while (task != NULL)
    {
      if (task->pt.x == pt->x && task->pt.y == pt->y)
	return (free_task(&(scene->tasks), task));
      task = task->next;
    }
  return (EXIT_FAILURE);
}

int		recvresult(t_socket *sender, t_packet *packet,
			   t_scene **scenes)
{
  size_t	scene_id;
  t_scene	*acscene;

  scene_id = get_scene_id(packet->data);
  printf("[INFO] Receiving result in scene %ld\n", scene_id);
  if ((acscene = get_scene(*scenes, scene_id)) != NULL)
    {
      get_task(acscene, packet->data);
      if (acscene->client == NULL)
	return (EXIT_SUCCESS);
      if (sendresult(acscene->client, packet) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      sender->state = WAITING;
      if (acscene->tasks == NULL)
	{
	  acscene->client->connected = 0;
	  close(acscene->client->socket);
	}
      return (EXIT_SUCCESS);
    }
  sender->state = WAITING;
  return (EXIT_FAILURE);
}
