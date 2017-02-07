/*
** check_size.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Mon May  4 14:41:25 2015 Antoine Zanardi
** Last update Thu May 28 17:04:38 2015 Raphael Thiebault
*/

#include	<stdlib.h>
#include	"pass_x.h"
#include	"is_x.h"
#include	"pass_x.h"
#include	"check_basic.h"
#include	"check_size.h"
#include	"error_parsing.h"
#include	"fc_str.h"
#include	"fc_base.h"
#include	"cut_str.h"

static void	correct_percent_size(char *str, int compt_str, int line)
{
  pass_label(str, &compt_str);
  if (is_percent_size(str + compt_str) != 0)
    my_putstr_error('c', line, 'u');
  pass_percent(str, &compt_str);
  pass_spaces(str, &compt_str);
  check_end_line(str, compt_str, line);
}

void		check_size(char *str, int line, int compt_param, int compt_str)
{
  pass_void(str, &compt_str, &line);
  while (str[compt_str] != '\0')
    {
      next_line(str, &compt_str, &line);
      while (my_strncmp_on_s1("</DEF>", str + compt_str) != 0)
	{
	  if (my_strncmp_on_s1("SIZE:", str + compt_str) == 0)
	    {
	      correct_percent_size(str, compt_str, line);
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
