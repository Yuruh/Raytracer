/*
** fill_xpm_in_obj.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Thu May  7 11:18:51 2015 Antoine Zanardi
** Last update Mon May 18 23:19:15 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"define.h"
#include	"object.h"
#include	"fill_xpm_in_obj.h"

static char	*find_xpm_path(unsigned int id, t_xpm *xpm)
{
  t_xpm		*tmp;

  tmp = xpm;
  while (tmp != NULL)
    {
      if (tmp->id == id)
	return (tmp->xpm);
      tmp = tmp->next;
    }
  return (NULL);
}

void		fill_xpm_in_obj(t_obj **obj, t_xpm *xpm)
{
  t_obj		*tmp_obj;

  tmp_obj = *obj;
  while (tmp_obj != NULL)
    {
      if ((tmp_obj->type == SPHERE || tmp_obj->type == PLAN) &&
	  tmp_obj->xpm.xpm != -1)
	tmp_obj->xpm.xpm_path = find_xpm_path((unsigned int)tmp_obj->xpm.xpm, xpm);
      tmp_obj = tmp_obj->next;
    }
}
