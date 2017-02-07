/*
** check_points.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer/parsing
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Thu Mar 26 10:56:49 2015 Antoine Zanardi
** Last update Fri May 29 11:51:06 2015 Raphael Thiebault
*/

#include	<stdlib.h>
#include	"pass_x.h"
#include	"fc_str.h"
#include	"fc_base.h"
#include	"cut_str.h"
#include	"check_points.h"
#include	"check_basic.h"
#include	"error_parsing.h"
#include	"my_free.h"
#include	"is_double.h"

void		correct_point(char *str, int compt_str, int line)
{
  compt_str++;
  pass_spaces(str, &compt_str);
  if (is_double(str + compt_str) == 1)
    my_putstr_error('d', line, 'a');
  pass_double(str, &compt_str);
  pass_spaces(str, &compt_str);
  if (is_double(str + compt_str) == 1)
    my_putstr_error('d', line, 'a');
  pass_double(str, &compt_str);
  pass_spaces(str, &compt_str);
  if (is_double(str + compt_str) == 1)
    my_putstr_error('d', line, 'a');
  pass_double(str, &compt_str);
  check_end_line(str, compt_str, line);
}

void		check_point(char *str)
{
  int		compt_str;
  int		line;

  compt_str = 0;
  line = 1;
  pass_void(str, &compt_str, &line);
  while (str[compt_str] != '\0')
    {
      pass_void(str, &compt_str, &line);
      if (my_strncmp_on_s1("v", str + compt_str) != 0)
	next_line(str, &compt_str, &line);
      else
	{
	  correct_point(str, compt_str, line);
	  next_line(str, &compt_str, &line);
	}
    }
}
