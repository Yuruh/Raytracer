/*
** newtask.c for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer/server
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Mon Jun  1 22:49:21 2015 Adrien Vasseur
** Last update Sun Jun  7 22:02:23 2015 Adrien Vasseur
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"network/define_server.h"
#include	"network/define_packet.h"
#include	"network/my_packet.h"
#include	"network/packets/newtask.h"

static t_task	*get_task(t_scene *scene)
{
  t_task	*tmp;
  int		i;

  if (scene == NULL)
    return (NULL);
  if (scene->client == NULL)
    return (NULL);
  tmp = scene->tasks;
  i = 0;
  while (tmp != NULL)
    {
      if (tmp->state == FREE)
	return (tmp);
      tmp = tmp->next;
      i++;
    }
  return (NULL);
}

static t_task	*get_last(t_scene **scenes, t_scene **actual)
{
  t_scene	*tmp;
  t_task	*task_last;
  t_task	*task_back;

  tmp = (*scenes);
  task_last = NULL;
  task_back = NULL;
  (*actual) = NULL;
  while (tmp != NULL)
    {
      if ((task_last = get_task(tmp)) == NULL)
	return (task_back);
      task_back = task_last;
      (*actual) = tmp;
      tmp = tmp->next;
    }
  return (task_back);
}

int		newtask(t_socket *socket, t_scene **scenes)
{
  t_task	*task;
  t_scene	*actual;
  t_packet	pack;

  if ((*scenes) == NULL)
    return (EXIT_SUCCESS);
  actual = NULL;
  task = get_last(scenes, &actual);
  if (task != NULL)
    {
      pack.id.m_int[0] = NEWTASK_MESSAGE;
      pack.size.m_int[0] = sizeof(*task);
      write(socket->socket, &(pack.id.m_char[0]), 1);
      write(socket->socket, &(pack.size.m_char[0]), 4);
      task->state = actual->id;
      write(socket->socket, task, sizeof(*task));
      task->state = GIVEN;
      socket->state = WORKING;
      printf("[INFO] Task sent!\n");
    }
  return (EXIT_SUCCESS);
}
