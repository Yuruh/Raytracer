/*
** check_circonference.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Sun May 10 18:46:16 2015 Antoine Zanardi
** Last update Thu May 28 17:06:54 2015 Raphael Thiebault
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
#include	"check_circonference.h"

void		check_circonference(char *str, int line,
				    int compt_param, int compt_str)
{
  pass_void(str, &compt_str, &line);
  while (str[compt_str] != '\0')
    {
      next_line(str, &compt_str, &line);
      while (my_strncmp_on_s1("</DEF>", str + compt_str) != 0)
	{
	  if (my_strncmp_on_s1("CIRCONFERENCE:",
			       str + compt_str) == 0)
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
