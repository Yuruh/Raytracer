/*
** fill_obj_tab.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Thu Mar 26 18:04:54 2015 Antoine Zanardi
** Last update Thu Jun  4 14:18:19 2015 Raphael Thiebault
*/

#include	<stdlib.h>
#include	"my.h"
#include	"object.h"
#include	"fill_obj_tab.h"
#include	"fc_base.h"
#include	"fc_str.h"
#include	"cut_str.h"
#include	"error_parsing.h"
#include	"my_free.h"
#include	"pass_x.h"

unsigned int	nb_faces(char *str)
{
  unsigned int	words;
  int		compt_str;

  compt_str = 0;
  words = 0;
  pass_void(str, &compt_str, NULL);
  while (str[compt_str] != '\0')
    {
      pass_void(str, &compt_str, NULL);
      if (my_strncmp_on_s1("f", str + compt_str) != 0)
	next_line(str, &compt_str, NULL);
      else
	{
	  words++;
	  next_line(str, &compt_str, NULL);
	}
    }
  return (words);
}

void		pass_coor(char *str, int *compt_str)
{
  while (str[*compt_str] != ' ' && str[*compt_str] != '\t' &&
	 str[*compt_str] != '\0' && str[*compt_str] != '\n')
    (*compt_str)++;
  pass_spaces(str, compt_str);
}

int		fill_coor(char *str, int co, unsigned int *n, t_pos_data *point)
{
  if ((*n = (unsigned int)my_getnbr(str + co)) > point->lim)
    {
      my_putstr("Point couldn't be found in the tab, end of program.\n");
      exit(1);
    }
  return (0);
}

void		fill_tab(char *str, t_face_data *tri, t_coor *coor)
{
  int		words;
  int		compt_str;

  compt_str = 0;
  words = 0;
  if (!(tri->face = malloc(sizeof(t_face) * (tri->lim = nb_faces(str)))))
    my_putstr_error('b', 0, 0);
  pass_void(str, &compt_str, NULL);
  while (str[compt_str] != '\0')
    {
      pass_void(str, &compt_str, NULL);
      if (my_strncmp_on_s1("f", str + compt_str) != 0)
	next_line(str, &compt_str, NULL);
      else
	{
	  tri->face[words++] = face_in_tab(str, compt_str, coor);
	  next_line(str, &compt_str, NULL);
	}
    }
}
