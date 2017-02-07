/*
** check_simple_num.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer/parsing_rt
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed Mar 18 10:53:38 2015 Antoine Zanardi
** Last update Thu May 28 16:39:38 2015 Raphael Thiebault
*/

#include	"check_basic.h"
#include	"cut_str.h"
#include	"error_parsing.h"
#include	"fc_str.h"
#include	"fc_base.h"
#include	"pass_x.h"
#include	"is_x.h"
#include	"check_pos.h"
#include	"check_simple_num.h"

void		correct_num(char *str, int compt_str, int line)
{
  pass_label(str, &compt_str);
  if (is_num(str + compt_str) != 0)
    my_putstr_error('c', line, 'h');
  pass_num(str, &compt_str);
  pass_spaces(str, &compt_str);
  check_end_line(str, compt_str, line);
}

void		check_rayon(char *str, int line, int compt_param, int compt_str)
{
  pass_void(str, &compt_str, &line);
  while (str[compt_str] != '\0')
    {
      next_line(str, &compt_str, &line);
      while (my_strncmp_on_s1("</DEF>", str + compt_str) != 0)
	{
	  if (my_strncmp_on_s1("RAYON:", str + compt_str) == 0)
	    {
	      correct_num(str, compt_str, line);
	      compt_param++;
	    }
	  next_line(str, &compt_str, &line);
	}
      if (compt_param > 1)
	my_putstr_error('c', line, 'c');
      next_line(str, &compt_str, &line);
      compt_param = 0;
    }
}

void		check_angle(char *str, int line, int compt_param, int compt_str)
{
  pass_void(str, &compt_str, &line);
  while (str[compt_str] != '\0')
    {
      next_line(str, &compt_str, &line);
      while (my_strncmp_on_s1("</DEF>", str + compt_str) != 0)
	{
	  if (my_strncmp_on_s1("ANGLE:", str + compt_str) == 0)
	    {
	      correct_num(str, compt_str, line);
	      compt_param++;
	    }
	  next_line(str, &compt_str, &line);
	}
      if (compt_param > 1)
	my_putstr_error('c', line, 'c');
      next_line(str, &compt_str, &line);
      compt_param = 0;
    }
}
