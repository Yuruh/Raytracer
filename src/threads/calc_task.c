/*
** calc_task.c for rt in /home/thieba_r/Documents/IGRAPH/MUL_2014_rtracer/src/threads
** 
** Made by Raphael Thiebault
** Login   <thieba_r@epitech.net>
** 
** Started on  Sat Jun  6 15:03:12 2015 Raphael Thiebault
** Last update Sat Jun  6 15:14:47 2015 Raphael Thiebault
*/

#include        <stdlib.h>
#include        <pthread.h>
#include        "my.h"
#include        "object.h"
#include        "threads/define_threads.h"
#include        "threads/my_threads.h"
#include        "threads/my_task_list.h"
#include        "go.h"

int		up_in_y(t_vec2i *pos, int y, t_data *data,
			t_my_task **list)
{
  while (pos->y + ZONE_Y <= y)
    {
      pos->y += ZONE_Y;
      my_add_task(list, data, *pos);
    }
  return (pos->y + ZONE_Y);
}

int		up_in_x(t_vec2i *pos, int x, t_data *data,
			t_my_task **list)
{
  while (pos->x + ZONE_X <= x)
    {
      pos->x += ZONE_X;
      my_add_task(list, data, *pos);
    }
  return (pos->x + ZONE_X);
}

int		down_in_y(t_vec2i *pos, int y, t_data *data,
			  t_my_task **list)
{
  while (pos->y >= y)
    {
      pos->y -= ZONE_Y;
      my_add_task(list, data, *pos);
    }
  return (pos->y);
}

int		down_in_x(t_vec2i *pos, int x, t_data *data,
			t_my_task **list)
{
  while (pos->x >= x)
    {
      pos->x -= ZONE_X;
      my_add_task(list, data, *pos);
    }
  return (pos->x);
}
