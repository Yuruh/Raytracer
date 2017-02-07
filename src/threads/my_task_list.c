/*
** my_task_list.c for rtrace in /home/vasseu_g/rendu/MUL_2014_rtracer
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Tue May  5 16:20:07 2015 Adrien Vasseur
** Last update Sat May 30 18:24:47 2015 Adrien Vasseur
*/

#include	<stdlib.h>
#include	<pthread.h>
#include	"my.h"
#include	"macro.h"
#include	"object.h"
#include	"threads/define_threads.h"
#include	"threads/my_task_list.h"

static void	init_task(t_my_task *elem, t_data *data, t_vec2i pt)
{
  if (pt.x < 0)
    elem->size.x = ZONE_X - ABS(pt.x);
  else if (pt.x + ZONE_X > data->width)
    elem->size.x = data->width - pt.x;
  else
    elem->size.x = ZONE_X;
  if (pt.y < 0)
    elem->size.y = ZONE_Y - ABS(pt.y);
  else if (pt.y + ZONE_Y > data->height)
    elem->size.y = data->height - pt.y;
  else
    elem->size.y = ZONE_Y;
  if (pt.x < 0)
    elem->pt.x = 0;
  else
    elem->pt.x = pt.x;
  if (pt.y < 0)
    elem->pt.y = 0;
  else
    elem->pt.y = pt.y;
  elem->next = NULL;
}

int		my_add_task(t_my_task **list, t_data *data, t_vec2i pt)
{
  t_my_task	*elem;
  t_my_task	*last;

  if (pt.x <= - ZONE_X || pt.y <= - ZONE_Y)
    return (EXIT_SUCCESS);
  if (pt.x >= data->width || pt.y >= data->height)
    return (EXIT_SUCCESS);
  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (EXIT_FAILURE);
  init_task(elem, data, pt);
  if ((*list) == NULL)
    (*list) = elem;
  else
    {
      last = (*list);
      while (last->next != NULL)
	last = last->next;
      last->next = elem;
    }
  return (EXIT_SUCCESS);
}
