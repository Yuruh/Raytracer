/*
** linked_list.c for azer in /home/lemper_a/rendu/igraph/MUL_2014_rtracer
**
** Made by Antoine LEMPEREUR
** Login   <lemper_a@epitech.net>
**
** Started on  Mon May 18 23:24:11 2015 Antoine LEMPEREUR
** Last update Tue May 19 01:37:35 2015 Antoine LEMPEREUR
*/

#include	"my.h"
#include	"object.h"
#include	"my_lib.h"

int		my_put_start_list(t_list_pos **list, t_pos *pos, t_pos *rot)
{
  t_list_pos	*maillon;

  if (!(maillon = malloc(sizeof(*maillon))))
    my_exit("Could not alloc\n");
  if (maillon == NULL)
    return (1);
  maillon->prev = NULL;
  maillon->pos = *pos;
  maillon->rot = *rot;
  maillon->next = *list;
  if (*list)
    (*list)->prev = maillon;
  *list = maillon;
  return (0);
}

int		my_put_end_list(t_list_pos **list, t_pos *pos, t_pos *rot)
{
  t_list_pos	*tmp;

  if (!*list)
    return (my_put_start_list(list, pos, rot));
  tmp = *list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  if (!(tmp->next = malloc(sizeof(*tmp))))
    my_exit("Could not alloc\n");
  if (tmp->next == NULL)
    return (1);
  tmp->next->next = NULL;
  tmp->next->pos = *pos;
  tmp->next->rot = *rot;
  tmp->next->prev = tmp;
  return (0);
}
