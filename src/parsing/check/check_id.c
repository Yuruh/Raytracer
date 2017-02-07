/*
** check_id.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Mon May  4 03:41:33 2015 Antoine Zanardi
** Last update Wed May 27 11:52:48 2015 Corentin Descamps
*/

#include	<stdlib.h>
#include	"my.h"
#include	"object.h"
#include	"parsing_rt.h"
#include	"check_id.h"
#include	"error_parsing.h"
#include	"error_obj.h"

static void	check_id_def(t_def *def)
{
  t_name	*tmp_static;
  t_name	*tmp_dyna;

  if (def && def->name)
    {
      tmp_static = def->name;
      while (tmp_static->next != NULL)
	{
	  tmp_dyna = tmp_static->next;
	  while (tmp_dyna != NULL)
	    {
	      if (tmp_dyna->id == tmp_static->id)
		error_view('e');
	      tmp_dyna = tmp_dyna->next;
	    }
	  tmp_static = tmp_static->next;
	}
    }
}

static void	check_id_xpm(t_def *def)
{
  t_xpm		*tmp_static;
  t_xpm		*tmp_dyna;

  if (def && def->xpm)
    {
      tmp_static = def->xpm;
      while (tmp_static->next != NULL)
	{
	  tmp_dyna = tmp_static->next;
	  while (tmp_dyna != NULL)
	    {
	      if (tmp_dyna->id == tmp_static->id)
		error_view('f');
	      tmp_dyna = tmp_dyna->next;
	    }
	  tmp_static = tmp_static->next;
	}
    }
}

static void	check_id_video(t_def *def)
{
  t_xpm		*tmp_static;
  t_xpm		*tmp_dyna;

  if (def && def->video)
    {
      tmp_static = def->video;
      while (tmp_static->next != NULL)
	{
	  tmp_dyna = tmp_static->next;
	  while (tmp_dyna != NULL)
	    {
	      if (tmp_dyna->id == tmp_static->id)
		error_view('f');
	      tmp_dyna = tmp_dyna->next;
	    }
	  tmp_static = tmp_static->next;
	}
    }
}

void		check_id(t_def *def)
{
  if (def->name != NULL)
    check_id_def(def);
  if (def->xpm != NULL)
    check_id_xpm(def);
  if (def->video != NULL)
    check_id_video(def);
}
