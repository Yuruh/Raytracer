/*
** check_focus.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Sun May  3 17:01:02 2015 Antoine Zanardi
** Last update Thu May 28 17:01:19 2015 Raphael Thiebault
*/

#include	"my.h"
#include	"check_focus.h"
#include	"cut_str.h"
#include	"fc_str.h"
#include	"error_parsing.h"
#include	"fc_base.h"
#include	"pass_x.h"
#include	"check_basic.h"

void		correct_focus(char *str, int compt_str, int line)
{
  compt_str += 6;
  pass_spaces(str, &compt_str);
  if (str[compt_str] != '0' && str[compt_str] != '1')
    my_putstr_error('c', line, 's');
  compt_str++;
  if (str[compt_str] != '\n' && str[compt_str] != '\0' &&
      str[compt_str] != ' ' && str[compt_str] != '\t')
    my_putstr_error('c', line, 's');
  check_end_line(str, compt_str, line);
}

static void	correct_sheet(char *str, int compt_str, int line)
{
  compt_str += 6;
  pass_spaces(str, &compt_str);
  if (str[compt_str] != '1' && str[compt_str] != '2')
    my_putstr_error('c', line, 'B');
  compt_str++;
  if (str[compt_str] != '\n' && str[compt_str] != '\0' &&
      str[compt_str] != ' ' && str[compt_str] != '\t')
    my_putstr_error('c', line, 'B');
  check_end_line(str, compt_str, line);
}

void		check_sheet(char *str, int line, int compt_param, int compt_str)
{
  pass_void(str, &compt_str, &line);
  while (str[compt_str] != '\0')
    {
      next_line(str, &compt_str, &line);
      while (my_strncmp_on_s1("</DEF>", str + compt_str) != 0)
	{
	  if (my_strncmp_on_s1("SHEET:", str + compt_str) == 0)
	    {
	      correct_sheet(str, compt_str, line);
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

void		check_focus(char *str, int line, int compt_param, int compt_str)
{
  pass_void(str, &compt_str, &line);
  while (str[compt_str] != '\0')
    {
      next_line(str, &compt_str, &line);
      while (my_strncmp_on_s1("</DEF>", str + compt_str) != 0)
	{
	  if (my_strncmp_on_s1("FOCUS:", str + compt_str) == 0)
	    {
	      correct_focus(str, compt_str, line);
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

void		check_lumos(char *str, int line, int compt_param, int compt_str)
{
  pass_void(str, &compt_str, &line);
  while (str[compt_str] != '\0')
    {
      next_line(str, &compt_str, &line);
      while (my_strncmp_on_s1("</DEF>", str + compt_str) != 0)
	{
	  if (my_strncmp_on_s1("LUMOS:", str + compt_str) == 0)
	    {
	      correct_focus(str, compt_str, line);
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
