/*
** my_threads.c for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer/src
**
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
**
** Started on  Fri Mar 27 13:56:27 2015 Adrien Vasseur
** Last update Sat Jun  6 15:18:24 2015 Raphael Thiebault
*/

#include	<stdlib.h>
#include	<pthread.h>
#include	"my.h"
#include	"object.h"
#include	"threads/define_threads.h"
#include	"threads/my_threads.h"
#include	"threads/my_task_list.h"
#include	"go.h"

static int	init_task(t_vec2i *pos, t_vec2i *max, t_vec2i *min,
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

static void	calc_task(t_data *data, t_my_task **list)
{
  t_vec2i	pos;
  t_vec2i	min;
  t_vec2i	max;
  int		running;

  running = init_task(&pos, &max, &min, data);
  my_add_task(list, data, pos);
  while (running == 1)
    {
      max.y = up_in_y(&pos, max.y, data, list);
      min.x = down_in_x(&pos, min.x, data, list);
      min.y = down_in_y(&pos, min.y, data, list);
      max.x = up_in_x(&pos, max.x, data, list);
      if (min.x <= 0 && max.x >= data->width &&
	  min.y <= 0 && max.y >= data->height)
	running = 0;
    }
}

void		*my_process(void *ptr)
{
  t_my_thread	*thread;
  t_my_task	*tmp;

  thread = (t_my_thread *) ptr;
  while (*(thread->list))
    {
      tmp = *(thread->list);
      *(thread->list) = tmp->next;
      go(thread->data, tmp->pt, tmp->size);
    }
  return (ptr);
}

void		my_threads(t_data *data)
{
  t_my_task	*list;
  pthread_t	all_threads[NBR_THREAD - 1];
  t_my_thread	*acc_thread;
  unsigned int	i;

  list = NULL;
  calc_task(data, &list);
  i = 0;
  while (i < NBR_THREAD)
    {
      acc_thread = malloc(sizeof(*acc_thread));
      acc_thread->uid_pthread = all_threads[i];
      acc_thread->uid = i;
      acc_thread->data = data;
      acc_thread->list = &list;
      pthread_create(&(all_threads[i]), NULL, &my_process, acc_thread);
      i++;
    }
  i = 0;
  while (i < NBR_THREAD)
    pthread_join(all_threads[i++], NULL);
}
