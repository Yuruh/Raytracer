/*
** video_list.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Tue May 19 00:30:07 2015 Antoine Zanardi
** Last update Wed May 27 12:03:59 2015 Corentin Descamps
*/

#include	<stdlib.h>
#include	"my.h"
#include	"object.h"
#include	"video_list.h"

int		add_top_video(t_video **list)
{
  t_video	*new;

  if ((new = malloc(sizeof(t_video))) == NULL)
    exit(1);
  new->rot_cent.bool = 0;
  new->next = *list;
  *list = new;
  return (0);
}

int		add_bot_video(t_video **list)
{
  t_video	*new;
  t_video	*tmp;

  if ((*list) == NULL)
    return (add_top_video(list));
  tmp = *list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  if ((new = malloc(sizeof(t_video))) == NULL)
    exit(1);
  new->rot_cent.bool = 0;
  new->next = NULL;
  tmp->next = new;
  return (0);
}
