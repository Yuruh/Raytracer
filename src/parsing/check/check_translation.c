/*
** check_translation.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Mon May 18 23:51:35 2015 Antoine Zanardi
** Last update Thu May 28 17:30:01 2015 Raphael Thiebault
*/

#include	"my.h"
#include	"fc_str.h"
#include	"fc_base.h"
#include	"is_x.h"
#include	"pass_x.h"
#include	"cut_str.h"
#include	"error_parsing.h"
#include	"check_basic.h"
#include	"check_translation.h"

static void	correct_coor_translation(char *str, int *compt_str,
					 char *pos, int line)
{
  if (my_strncmp_on_s1(pos, str + *compt_str) != 0)
    my_putstr_error('e', line, 'f');
  pass_label(str, compt_str);
  if (my_strncmp_on_s1("=", str + *compt_str) != 0)
    my_putstr_error('e', line, 'f');
  (*compt_str)++;
  pass_spaces(str, compt_str);
  if (is_num(str + *compt_str) != 0)
    my_putstr_error('e', line, 'g');
  pass_num(str, compt_str);
  pass_spaces(str, compt_str);
}

static void	correct_translation(char *str, int compt_str, int line)
{
  pass_label(str, &compt_str);
  correct_coor_translation(str, &compt_str, "X", line);
  correct_coor_translation(str, &compt_str, "Y", line);
  correct_coor_translation(str, &compt_str, "Z", line);
  check_end_line(str, compt_str, line);
}

void		check_translation(char *str, int line,
				  int compt_param, int compt_str)
{
  pass_void(str, &compt_str, &line);
  while (str[compt_str] != '\0')
    {
      next_line(str, &compt_str, &line);
      while (my_strncmp_on_s1("</VID>", str + compt_str) != 0)
	{
	  if (my_strncmp_on_s1("POS:", str + compt_str) == 0)
	    {
	      correct_translation(str, compt_str, line);
	      compt_param++;
	    }
	  next_line(str, &compt_str, &line);
	}
      if (compt_param > 1)
	my_putstr_error('e', line, 'd');
      if (compt_param == 0)
	my_putstr_error('e', line, 'k');
      next_line(str, &compt_str, &line);
      compt_param = 0;
    }
}
