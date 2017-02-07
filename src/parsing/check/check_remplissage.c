/*
** check_remplissage.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed May 20 14:42:12 2015 Antoine Zanardi
** Last update Thu May 28 17:07:46 2015 Raphael Thiebault
*/

#include	"check_percent.h"
#include	"fc_str.h"
#include	"fc_base.h"
#include	"is_x.h"
#include	"pass_x.h"
#include	"cut_str.h"
#include	"check_basic.h"
#include	"error_parsing.h"
#include	"check_remplissage.h"

void		check_remplissage(char *str, int line,
				  int compt_param, int compt_str)
{
  pass_void(str, &compt_str, &line);
  while (str[compt_str] != '\0')
    {
      next_line(str, &compt_str, &line);
      while (my_strncmp_on_s1("</DEF>", str + compt_str) != 0)
	{
	  if (my_strncmp_on_s1("REMPLISSAGE:", str + compt_str) == 0)
	    {
	      correct_percent(str, compt_str, line);
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
