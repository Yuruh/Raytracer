/*
** check_color.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer/parsing_rt
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed Mar 18 14:26:22 2015 Antoine Zanardi
** Last update Thu May 28 20:27:39 2015 Raphael Thiebault
*/

#include	"check_color.h"
#include	"fc_base.h"
#include	"cut_str.h"
#include	"fc_str.h"
#include	"check_basic.h"
#include	"error_parsing.h"
#include	"is_x.h"
#include	"pass_x.h"
#include	"my_free.h"

void		correct_color(char *str, int compt_str, int line)
{
  pass_label(str, &compt_str);
  if (is_hexa(str + compt_str) != 0)
    my_putstr_error('c', line, 'i');
  compt_str += 8;
  pass_spaces(str, &compt_str);
  check_end_line(str, compt_str, line);
}

void		check_color(char *str, int line, int compt_param, int compt_str)
{
  pass_void(str, &compt_str, &line);
  while (str[compt_str] != '\0')
    {
      next_line(str, &compt_str, &line);
      while (my_strncmp_on_s1("</DEF>", str + compt_str) != 0)
	{
	  if (my_strncmp_on_s1("COLOR:", str + compt_str) == 0)
	    {
	      correct_color(str, compt_str, line);
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

void		check_damier(char *str, int line, int compt_param, int compt_str)
{
  pass_void(str, &compt_str, &line);
  while (str[compt_str] != '\0')
    {
      next_line(str, &compt_str, &line);
      while (my_strncmp_on_s1("</DEF>", str + compt_str) != 0)
	{
	  if (my_strncmp_on_s1("DAMIER:", str + compt_str) == 0)
	    {
	      correct_color(str, compt_str, line);
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
