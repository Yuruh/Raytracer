/*
** check_texture.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Tue May  5 15:04:33 2015 Antoine Zanardi
** Last update Thu May 28 21:05:12 2015 Raphael Thiebault
*/

#include	<stdlib.h>
#include	"object.h"
#include	"pass_x.h"
#include	"fc_str.h"
#include	"fc_base.h"
#include	"cut_str.h"
#include	"check_points.h"
#include	"check_basic.h"
#include	"error_parsing.h"
#include	"my_free.h"
#include	"is_double.h"
#include	"check_texture.h"

static void	correct_texture(char *str, int compt_str, int line)
{
  compt_str += 2;
  pass_spaces(str, &compt_str);
  if (is_double(str + compt_str) == 1)
    my_putstr_error('d', line, 'd');
  pass_double(str, &compt_str);
  pass_spaces(str, &compt_str);
  if (is_double(str + compt_str) == 1)
    my_putstr_error('d', line, 'd');
  pass_double(str, &compt_str);
  pass_spaces(str, &compt_str);
  check_end_line(str, compt_str, line);
}

void		check_texture(char *str, t_face_data *elem)
{
  int		compt_str;
  int		line;

  elem->is_texture = 0;
  compt_str = 0;
  line = 1;
  pass_void(str, &compt_str, &line);
  while (str[compt_str] != '\0')
    {
      pass_void(str, &compt_str, &line);
      if (my_strncmp_on_s1("vt", str + compt_str) != 0)
	next_line(str, &compt_str, &line);
      else
	{
	  elem->is_texture = 1;
	  correct_texture(str, compt_str, line);
	  next_line(str, &compt_str, &line);
	}
    }
}
