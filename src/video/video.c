/*
** video.c for azer in /home/lemper_a/rendu/igraph/MUL_2014_rtracer
**
** Made by Antoine LEMPEREUR
** Login   <lemper_a@epitech.net>
**
** Started on  Mon Jun  1 13:09:00 2015 Antoine LEMPEREUR
** Last update Sat Jun  6 20:30:55 2015 Raphael Thiebault
*/

#include	"my.h"
#include	"modif.h"
#include	"threads/my_threads.h"
#include	"net/my_client.h"

void		get_actual_pos_obj(t_data *d)
{
  t_obj		*tmp;
  int		i;
  t_list_pos	*list;

  tmp = d->obj;
  while (tmp)
    {
      if (tmp->video.id != -1)
	{
	  list = tmp->list_pos;
	  i = -1;
	  while (++i < d->count_img)
	    list = list->next;
	  if (list != NULL)
	    {
	      tmp->pos = list->pos;
	      tmp->rot = list->rot;
	    }
	}
      tmp = tmp->next;
    }
}

void		get_actual_pos_eye(t_data *d)
{
  t_list_pos	*list;
  int		i;

  if (d->video.id != -1)
    {
      list = d->list_pos;
      i = -1;
      while (++i < d->count_img)
	list = list->next;
      d->eye = list->pos;
      d->rot = list->rot;
    }
}

void		no_video(t_data *d, t_ip *ip)
{
  t_obj		*o;

  o = d->obj;
  while (o)
    {
      o->list_pos = NULL;
      o = o->next;
    }
  d->list_pos = NULL;
  if (my_client(ip, d) == EXIT_FAILURE)
    my_threads(d);
  apply_blur(d);
}

void		launch_video(t_data *d, t_ip *ip)
{
  t_obj		*tmp;

  tmp = d->obj;
  while (tmp)
    {
      tmp->list_pos = NULL;
      if (tmp->video.id != -1)
        calc_list_pos(tmp->video.list, &tmp->list_pos, tmp, d->time);
      tmp = tmp->next;
    }
  if (d->video.id != -1)
    calc_list_pos_eye(d->video.list, &d->list_pos, d->time, d);
  while (d->count_img < d->time * IMG_SEC)
    {
      get_actual_pos_obj(d);
      get_actual_pos_eye(d);
      if (my_client(ip, d) == EXIT_FAILURE)
	my_threads(d);
      apply_blur(d);
      d->count_img++;
    }
}
