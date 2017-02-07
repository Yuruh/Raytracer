/*
** check_rotate_centrale.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed May 20 09:55:24 2015 Antoine Zanardi
** Last update Thu May 28 17:55:35 2015 Raphael Thiebault
*/

#include	"my.h"
#include	"fc_str.h"
#include	"fc_base.h"
#include	"is_x.h"
#include	"pass_x.h"
#include	"cut_str.h"
#include	"error_parsing.h"
#include	"check_basic.h"
#include	"check_rotate_centrale.h"

static void	correct_coor_centrale(char *str, int *compt_str,
					 char *pos, int line)
{
  if (my_strncmp_on_s1(pos, str + *compt_str) != 0)
    my_putstr_error('e', line, 'm');
  pass_label(str, compt_str);
  if (my_strncmp_on_s1("=", str + *compt_str) != 0)
    my_putstr_error('e', line, 'm');
  (*compt_str)++;
  pass_spaces(str, compt_str);
  if (is_num(str + *compt_str) != 0)
    my_putstr_error('e', line, 'g');
  pass_num(str, compt_str);
  pass_spaces(str, compt_str);
}

static void	correct_rotate_centrale(char *str, int compt_str, int line)
{
  pass_label(str, &compt_str);
  correct_coor_centrale(str, &compt_str, "X", line);
  correct_coor_centrale(str, &compt_str, "Y", line);
  correct_coor_centrale(str, &compt_str, "Z", line);
  if (str[compt_str] != '/')
    my_putstr_error('e', line, 'm');
  compt_str++;
  pass_spaces(str, &compt_str);
  correct_coor_centrale(str, &compt_str, "X", line);
  correct_coor_centrale(str, &compt_str, "Y", line);
  correct_coor_centrale(str, &compt_str, "Z", line);
  check_end_line(str, compt_str, line);
}

void		check_rotate_centrale(char *str, int line,
				  int compt_param, int compt_str)
{
  pass_void(str, &compt_str, &line);
  while (str[compt_str] != '\0')
    {
      next_line(str, &compt_str, &line);
      while (my_strncmp_on_s1("</VID>", str + compt_str) != 0)
	{
	  if (my_strncmp_on_s1("ROT_CENT:", str + compt_str) == 0)
	    {
	      correct_rotate_centrale(str, compt_str, line);
	      compt_param++;
	    }
	  next_line(str, &compt_str, &line);
	}
      if (compt_param > 1)
	my_putstr_error('e', line, 'd');
      next_line(str, &compt_str, &line);
      compt_param = 0;
    }
}
