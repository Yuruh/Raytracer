/*
** fill_points_tab.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Thu Mar 26 15:18:23 2015 Antoine Zanardi
** Last update Thu May 28 19:16:56 2015 Raphael Thiebault
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my.h"
#include	"object.h"
#include	"fill_points_tab.h"
#include	"pass_x.h"
#include	"error_parsing.h"
#include	"cut_str.h"
#include	"fc_str.h"
#include	"fc_base.h"
#include	"my_free.h"

unsigned int	nb_points(char *str)
{
  int		compt_str;
  unsigned int	words;

  compt_str = 0;
  words = 0;
  pass_void(str, &compt_str, NULL);
  while (str[compt_str] != '\0')
    {
      pass_void(str, &compt_str, NULL);
      if (my_strncmp_on_s1("v", str + compt_str) != 0)
	next_line(str, &compt_str, NULL);
      else
	{
	  words++;
	  next_line(str, &compt_str, NULL);
	}
    }
  return (words);
}

t_pos		point_in_tab(char *str, int compt_str)
{
  t_pos		pos;

  compt_str++;
  pass_spaces(str, &compt_str);
  pos.x = atof(str + compt_str);
  pass_double(str, &compt_str);
  pass_spaces(str, &compt_str);
  pos.y = atof(str + compt_str);
  pass_double(str, &compt_str);
  pass_spaces(str, &compt_str);
  pos.z = atof(str + compt_str);
  return (pos);
}

t_pos_data	fill_points_tab(char *str)
{
  int		compt_str;
  int		words;
  t_pos_data	point;

  compt_str = 0;
  words = 0;
  point.lim = nb_points(str);
  if ((point.pos = malloc(sizeof(t_pos) * (point.lim))) == NULL)
    my_putstr_error('b', 0, 0);
  pass_void(str, &compt_str, NULL);
  while (str[compt_str] != '\0')
    {
      pass_void(str, &compt_str, NULL);
      if (my_strncmp_on_s1("v", str + compt_str) != 0)
	next_line(str, &compt_str, NULL);
      else
	{
	  point.pos[words++] = point_in_tab(str, compt_str);
	  next_line(str, &compt_str, NULL);
	}
    }
  return (point);
}
