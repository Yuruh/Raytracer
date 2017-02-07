/*
** my_calculator.c for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Thu Jun  4 12:18:07 2015 Adrien Vasseur
** Last update Sun Jun  7 00:12:50 2015 Adrien Vasseur
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"my.h"
#include	"go.h"
#include	"net/define_client.h"
#include	"net/define_packet.h"
#include	"net/packets/sendresult.h"
#include	"net/my_calculator.h"

static t_scene	*known_scene(t_task *task, t_scene *scenes)
{
  while (scenes != NULL)
    {
      if (scenes->id == task->id)
	return (scenes);
      scenes = scenes->next;
    }
  return (NULL);
}

int		my_calculator(t_client *client)
{
  t_scene	*scene;
  t_task	*task;

  if ((task = client->tasks) != NULL)
    {
      if ((scene = known_scene(task, client->scenes)) == NULL)
	return (EXIT_FAILURE);
      client->tasks = task->next;
      printf("[INFO] Starting task calculation...\n");
      go(scene->data, task->pt, task->size);
      printf("[INFO] Task calculated!\n");
      return (sendresult(client, scene, task));
    }
  return (EXIT_SUCCESS);
}
