/*
** list.c for rt in /home/descam_d/rendu/IGRAPH/MUL_2014_rtracer/scene_editor
** 
** Made by Corentin Descamps
** Login   <descam_d@epitech.net>
** 
** Started on  Tue May 26 13:37:26 2015 Corentin Descamps
** Last update Sun Jun  7 18:06:03 2015 Corentin Descamps
*/

#include	<stdlib.h>
#include	<gtk/gtk.h>
#include	"data.h"
#include	"menu.h"
#include	"object.h"

extern	t_obj	*g_obj;
extern	t_light	*g_light;

int		add_stack(t_menu **list, const gchar *title,
			  GCallback callback, gpointer data)
{
  t_menu	*elem;

  if (!(elem = malloc(sizeof(t_menu))))
    return (EXIT_FAILURE);
  elem->title = title;
  elem->callback = callback;
  elem->data = data;
  elem->next = *list;
  *list = elem;
  return (EXIT_SUCCESS);
}

void		stack_pos(t_pos *elem, t_pos *tmp)
{
  elem->x = tmp->x;
  elem->y = tmp->y;
  elem->z = tmp->z;
}

int		stack_light(t_light *tmp)
{
  t_light	*elem;

  elem = malloc(sizeof(*elem));
  elem->pos.x = tmp->pos.x;
  elem->pos.y = tmp->pos.y;
  elem->pos.z = tmp->pos.z;
  elem->rgb[0] = tmp->rgb[0];
  elem->rgb[1] = tmp->rgb[1];
  elem->rgb[2] = tmp->rgb[2];
  elem->next = g_light;
  g_light = elem;
  return (EXIT_SUCCESS);
}

int		stack_obj(t_obj *tmp)
{
  t_obj		*elem;

  elem = malloc(sizeof(*elem));
  elem->type = tmp->type;
  stack_pos(&elem->pos, &tmp->pos);
  stack_pos(&elem->rot, &tmp->rot);
  stack_pos(&elem->h_lim, &tmp->h_lim);
  stack_pos(&elem->b_lim, &tmp->b_lim);
  elem->rayon = tmp->rayon;
  elem->bril = tmp->bril;
  elem->spec = tmp->spec;
  elem->trans = tmp->trans;
  elem->ref = tmp->ref;
  elem->rgb[0] = tmp->rgb[0];
  elem->rgb[1] = tmp->rgb[1];
  elem->rgb[2] = tmp->rgb[2];
  elem->next = g_obj;
  g_obj = elem;
  return (EXIT_FAILURE);
}
