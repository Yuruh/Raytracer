/*
** my_lists.c for my_lists in /home/zanard_a/rendu/Librairie/Librairie_off
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed Dec 17 11:19:28 2014 Antoine Zanardi
** Last update Wed Jun  3 13:45:02 2015 Antoine Zanardi
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"my.h"
#include	"my_lists.h"
#include	"object.h"

void		create_lists(t_lux **light, t_obj *obj,
			     t_obj **view, t_obj **only_obj)
{
  t_obj		*tmp;

  tmp = obj;
  while (tmp != NULL)
    {
      if (tmp->type == VIEW)
	add_exist_list(view, tmp);
      else if (tmp->type == LIGHT ||
	       (tmp->type == PLAN && tmp->cons.lumos == 1))
	add_exist_lux(light, tmp);
      else if (tmp->type != IGN)
	add_exist_list(only_obj, tmp);
      tmp = tmp->next;
    }
}

int		add_exist_lux(t_lux **list, t_obj *tmp)
{
  t_lux		*elem;

  if ((elem = malloc(sizeof(t_lux))) == NULL)
    return (0);
  elem->pos = tmp->pos;
  elem->color = tmp->src_col;
  elem->video = tmp->video;
  if (tmp->type == PLAN)
    {
      elem->form = PLAN;
      elem->lim = tmp->lim;
      elem->rot = tmp->rot;
    }
  else
    elem->form = SPHERE;
  elem->next = *list;
  if (*list != NULL)
    (*list)->prev = elem;
  *list = elem;
  return (0);
}

int		add_exist_list(t_obj **list, t_obj *tmp)
{
  t_obj		*elem;

  if ((elem = malloc(sizeof(t_obj))) == NULL)
    return (0);
  elem->type = tmp->type;
  elem->lon = tmp->lon;
  elem->lon.ray = tmp->lon.ray;
  elem->lim = tmp->lim;
  elem->triangle = NULL;
  elem->texture.is_texture = tmp->texture.is_texture;
  elem->texture.is_normale = tmp->texture.is_normale;
  elem->src_col = tmp->src_col;
  elem->damier_col = tmp->damier_col;
  elem->cons = tmp->cons;
  elem->pos = tmp->pos;
  elem->rot = tmp->rot;
  elem->dis = tmp->dis;
  elem->xpm = tmp->xpm;
  elem->video = tmp->video;
  elem->lon.circonference = tmp->lon.circonference;
  elem->xpm.xpm_path = tmp->xpm.xpm_path;
  elem->next = *list;
  *list = elem;
  return (0);
}

int		add_top_list(t_obj **list)
{
  t_obj		*elem;

  if ((elem = malloc(sizeof(t_obj))) == NULL)
    return (0);
  elem->next = *list;
  *list = elem;
  return (0);
}

int		count_lux(t_lux *lux)
{
  int		compt_lux;
  t_lux		*tmp;

  tmp = lux;
  compt_lux = 0;
  while (tmp != NULL)
    {
      compt_lux++;
      tmp = tmp->next;
    }
  return (compt_lux);
}
