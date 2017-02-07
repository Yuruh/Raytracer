/*
** my_free.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Mon Mar 30 11:34:40 2015 Antoine Zanardi
** Last update Thu Apr  2 10:29:14 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"object.h"
#include	"my_free.h"

void		free_str(char *str)
{
  if (str != NULL)
    free(str);
}

void		free_obj_list(t_obj *obj)
{
  t_obj		*tmp;

  tmp = obj;
  while (obj != NULL)
    {
      tmp = tmp->next;
      if (obj != NULL)
	free(obj);
      obj = tmp;
    }
}
