/*
** check_normale.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Tue May  5 14:18:40 2015 Antoine Zanardi
** Last update Fri May 29 11:35:42 2015 Raphael Thiebault
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
#include	"check_normale.h"
#include	"is_double.h"

static void	correct_normale(char *str, int compt_str, int line)
{
  compt_str += 2;
  pass_spaces(str, &compt_str);
  if (is_double(str + compt_str) == 1)
    my_putstr_error('d', line, 'c');
  pass_double(str, &compt_str);
  pass_spaces(str, &compt_str);
  if (is_double(str + compt_str) == 1)
    my_putstr_error('d', line, 'c');
  pass_double(str, &compt_str);
  pass_spaces(str, &compt_str);
  if (is_double(str + compt_str) == 1)
    my_putstr_error('d', line, 'c');
  pass_double(str, &compt_str);
  check_end_line(str, compt_str, line);
}

void		check_normal(char *str, t_face_data *elem)
{
  int		compt_str;
  int		line;

  elem->is_normale = 0;
  compt_str = 0;
  line = 1;
  pass_void(str, &compt_str, &line);
  while (str[compt_str] != '\0')
    {
      pass_void(str, &compt_str, &line);
      if (my_strncmp_on_s1("vn", str + compt_str) != 0)
	next_line(str, &compt_str, &line);
      else
	{
	  elem->is_normale = 1;
	  correct_normale(str, compt_str, line);
	  next_line(str, &compt_str, &line);
	}
    }
}
