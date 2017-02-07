/*
** my_scene.c for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer/server
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Sat May 30 18:11:22 2015 Adrien Vasseur
** Last update Sun Jun  7 20:43:51 2015 Adrien Vasseur
*/

#include	<stdlib.h>
#include	"network/define_server.h"
#include	"network/my_tasks.h"

int		add_scene(t_scene **list, char *raw,
			  t_data *data, size_t raw_size)
{
  t_scene	*elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (EXIT_FAILURE);
  elem->id = 1;
  if ((*list) != NULL)
    elem->id = (*list)->id + 1;
  elem->raw = raw;
  elem->raw_size = raw_size;
  elem->data = data;
  elem->tasks = create_tasks(elem->data);
  elem->next = (*list);
  (*list) = elem;
  return (EXIT_SUCCESS);
}

int		free_scene(t_scene **list, t_scene *scene)
{
  t_scene	*tmp;

  tmp = (*list);
  while (tmp != NULL)
    {
      if (tmp == scene)
	{
	  free(tmp->raw);
	  tmp->data = NULL;
	  tmp->tasks = NULL;
	  tmp->client = NULL;
	  return (EXIT_SUCCESS);
	}
      tmp = tmp->next;
    }
  return (EXIT_FAILURE);
}
