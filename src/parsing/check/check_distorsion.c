/*
** check_distorsion.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Fri May  8 14:46:11 2015 Antoine Zanardi
** Last update Mon Jun  1 17:10:45 2015 Antoine Zanardi
*/

#include	"check_basic.h"
#include	"cut_str.h"
#include	"error_parsing.h"
#include	"fc_str.h"
#include	"fc_base.h"
#include	"pass_x.h"
#include	"is_x.h"
#include	"check_pos.h"
#include	"check_distorsion.h"
#include	"my_getnbr.h"

static void	correct_distorsion(char *str, int compt_str, int line)
{
  pass_label(str, &compt_str);
  if (is_num(str + compt_str) != 0)
    my_putstr_error('c', line, 'h');
  if (my_getnbr(str + compt_str) > 100 || my_getnbr(str + compt_str) < -100 ||
      my_getnbr(str + compt_str) == 0)
    my_putstr_error('c', line, 'x');
  pass_num(str, &compt_str);
  pass_spaces(str, &compt_str);
  if (is_num(str + compt_str) != 0)
    my_putstr_error('c', line, 'h');
  if (my_getnbr(str + compt_str) > 100 || my_getnbr(str + compt_str) < -100 ||
      my_getnbr(str + compt_str) == 0)
    my_putstr_error('c', line, 'x');
  pass_num(str, &compt_str);
  pass_spaces(str, &compt_str);
  if (is_num(str + compt_str) != 0)
    my_putstr_error('c', line, 'h');
  if (my_getnbr(str + compt_str) > 100 || my_getnbr(str + compt_str) < -100 ||
      my_getnbr(str + compt_str) == 0)
    my_putstr_error('c', line, 'x');
  pass_num(str, &compt_str);
  pass_spaces(str, &compt_str);
  check_end_line(str, compt_str, line);
}

void		check_distorsion(char *str, int line, int compt_param, int co)
{
  pass_void(str, &co, &line);
  while (str[co] != '\0')
    {
      next_line(str, &co, &line);
      while (my_strncmp_on_s1("</DEF>", str + co) != 0)
	{
	  if (my_strncmp_on_s1("DISTORSION:", str + co) == 0)
	    {
	      correct_distorsion(str, co, line);
	      compt_param++;
	    }
	  next_line(str, &co, &line);
	}
      if (compt_param > 1)
	my_putstr_error('c', line, 'c');
      next_line(str, &co, &line);
      compt_param = 0;
    }
}
