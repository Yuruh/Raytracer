/*
** check_rot_lim.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer/parsing_rt
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed Mar 18 10:32:13 2015 Antoine Zanardi
** Last update Thu May 28 16:37:50 2015 Raphael Thiebault
*/

#include	"my.h"
#include	"check_pos.h"
#include	"fc_str.h"
#include	"error_parsing.h"
#include	"fc_base.h"
#include	"cut_str.h"
#include	"check_rot_lim.h"
#include	"check_basic.h"

void		check_h_lim(char *str, int line, int compt_param, int compt_str)
{
  pass_void(str, &compt_str, &line);
  while (str[compt_str] != '\0')
    {
      next_line(str, &compt_str, &line);
      while (my_strncmp_on_s1("</DEF>", str + compt_str) != 0)
	{
	  if (my_strncmp_on_s1("H_LIM:", str + compt_str) == 0)
	    {
	      correct_pos(str, compt_str, line);
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

void		check_b_lim(char *str, int line, int compt_param, int compt_str)
{
  pass_void(str, &compt_str, &line);
  while (str[compt_str] != '\0')
    {
      next_line(str, &compt_str, &line);
      while (my_strncmp_on_s1("</DEF>", str + compt_str) != 0)
	{
	  if (my_strncmp_on_s1("H_LIM:", str + compt_str) == 0)
	    {
	      correct_pos(str, compt_str, line);
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

void		check_rotate(char *str, int line, int compt_param, int compt_str)
{
  pass_void(str, &compt_str, &line);
  while (str[compt_str] != '\0')
    {
      next_line(str, &compt_str, &line);
      while (my_strncmp_on_s1("</DEF>", str + compt_str) != 0)
	{
	  if (my_strncmp_on_s1("ROTATE:", str + compt_str) == 0)
	    {
	      correct_pos(str, compt_str, line);
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
