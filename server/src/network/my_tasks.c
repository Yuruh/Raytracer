/*
** my_tasks.c for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer/server
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Sat May 30 18:16:57 2015 Adrien Vasseur
** Last update Sun Jun  7 21:26:00 2015 Adrien Vasseur
*/

#include	<stdlib.h>
#include	"macro.h"
#include	"network/define_server.h"
#include	"network/my_tasks.h"
#include	"network/calc_task.h"

static void	init_task(t_task *elem, t_data *data, t_vec2i pt)
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

int	my_add_task(t_task **list, t_data *data, t_vec2i pt)
{
  t_task	*elem;
  t_task	*last;

  if (pt.x <= - ZONE_X || pt.y <= - ZONE_Y)
    return (EXIT_SUCCESS);
  if (pt.x >= data->width || pt.y >= data->height)
    return (EXIT_SUCCESS);
  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (EXIT_FAILURE);
  elem->state = FREE;
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

static int	initier(t_vec2i *pos, t_vec2i *max, t_vec2i *min,
			  t_data *data)
{
  pos->x = data->width / 2;
  pos->y = data->height / 2 - ZONE_Y;
  min->y = pos->y;
  min->x = pos->x;
  max->y = pos->y + ZONE_Y;
  max->x = pos->x + ZONE_X;
  return (1);
}

t_task		*create_tasks(t_data *data)
{
  t_task	*list;
  t_vec2i	pos;
  t_vec2i	min;
  t_vec2i	max;
  int		running;

  list = NULL;
  running = initier(&pos, &max, &min, data);
  my_add_task(&list, data, pos);
  while (running == 1)
    {
      max.y = up_in_y(&pos, max.y, data, &list);
      min.x = down_in_x(&pos, min.x, data, &list);
      min.y = down_in_y(&pos, min.y, data, &list);
      max.x = up_in_x(&pos, max.x, data, &list);
      if (min.x <= 0 && max.x >= data->width &&
	  min.y <= 0 && max.y >= data->height)
	running = 0;
    }
  return (list);
}

int		free_task(t_task **list, t_task *task)
{
  t_task	*tmp;
  t_task	*last;

  tmp = (*list);
  last = NULL;
  while (tmp != NULL)
    {
      if (tmp == task)
	{
	  if (last == NULL)
	    (*list) = tmp->next;
	  else
	    last->next = tmp->next;
	  free(tmp);
	  return (EXIT_SUCCESS);
	}
      last = tmp;
      tmp = tmp->next;
    }
  return (EXIT_FAILURE);
}
