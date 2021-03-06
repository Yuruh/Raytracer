/*
** fill_texture_tab.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Thu May  7 16:38:55 2015 Antoine Zanardi
** Last update Thu May 28 18:17:30 2015 Raphael Thiebault
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
#include	"fill_texture_tab.h"

unsigned int	nb_texture(char *str)
{
  int		compt_str;
  unsigned int	words;

  compt_str = 0;
  words = 0;
  pass_void(str, &compt_str, NULL);
  while (str[compt_str] != '\0')
    {
      pass_void(str, &compt_str, NULL);
      if (my_strncmp_on_s1("vt", str + compt_str) != 0)
	next_line(str, &compt_str, NULL);
      else
	{
	  words++;
	  next_line(str, &compt_str, NULL);
	}
    }
  return (words);
}

t_pos		texture_in_tab(char *str, int compt_str)
{
  t_pos		pos;

  compt_str += 2;
  pass_spaces(str, &compt_str);
  pos.x = atof(str + compt_str);
  pass_double(str, &compt_str);
  pass_spaces(str, &compt_str);
  pos.y = atof(str + compt_str);
  pos.z = 0.0;
  return (pos);
}

t_pos_data	fill_texture_tab(char *str)
{
  int		compt_str;
  int		words;
  t_pos_data	point;

  compt_str = 0;
  words = 0;
  point.lim = nb_texture(str);
  if ((point.pos = malloc(sizeof(t_pos) * (point.lim))) == NULL)
    my_putstr_error('b', 0, 0);
  pass_void(str, &compt_str, NULL);
  while (str[compt_str] != '\0')
    {
      pass_void(str, &compt_str, NULL);
      if (my_strncmp_on_s1("vt", str + compt_str) != 0)
	next_line(str, &compt_str, NULL);
      else
	{
	  point.pos[words++] = texture_in_tab(str, compt_str);
	  next_line(str, &compt_str, NULL);
	}
    }
  return (point);
}
