/*
** check_tab.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer/parsing
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Thu Mar 26 11:53:45 2015 Antoine Zanardi
** Last update Thu May 28 17:24:02 2015 Raphael Thiebault
*/

#include	"my.h"
#include	"correct_tab.h"
#include	"parsing_rt.h"
#include	"object.h"
#include	"check_tab.h"
#include	"error_parsing.h"
#include	"check_basic.h"
#include	"cut_str.h"
#include	"fc_str.h"
#include	"pass_x.h"
#include	"fc_base.h"
#include	"my_free.h"

void		is_num_tab(char *str, int compt_str, int line)
{
  if (!(str[compt_str] >= '1' && str[compt_str] <= '9'))
    my_putstr_error('d', line, 'e');
  while (str[compt_str] != '/' && str[compt_str] != ' ' &&
	 str[compt_str] != '\t' && str[compt_str] != '\n' &&
	 str[compt_str] != '\0' && str[compt_str] != '\r')
    {
      if (!(str[compt_str] >= '0' && str[compt_str] <= '9'))
	my_putstr_error('d', line, 'e');
      compt_str++;
    }
}

static void	mode_check(char *str, int *compt_str, int line, t_face_data *e)
{
  (*compt_str)++;
  if (e->is_texture == 1 && e->is_normale == 1)
    {
      correct_tab_1(str, compt_str, line);
      correct_tab_1(str, compt_str, line);
      correct_tab_1(str, compt_str, line);
    }
  else if (e->is_texture == 0 && e->is_normale == 1)
    {
      correct_tab_2(str, compt_str, line);
      correct_tab_2(str, compt_str, line);
      correct_tab_2(str, compt_str, line);
    }
  else if (e->is_texture == 1 && e->is_normale == 0)
    {
      correct_tab_3(str, compt_str, line);
      correct_tab_3(str, compt_str, line);
      correct_tab_3(str, compt_str, line);
    }
  else if (e->is_texture == 0 && e->is_normale == 0)
    {
      correct_tab_4(str, compt_str, line);
      correct_tab_4(str, compt_str, line);
      correct_tab_4(str, compt_str, line);
    }
}

void		check_tab(char *str, t_face_data *elem)
{
  int		compt_str;
  int		line;

  compt_str = 0;
  line = 1;
  pass_void(str, &compt_str, &line);
  while (str[compt_str] != '\0')
    {
      pass_void(str, &compt_str, &line);
      if (my_strncmp_on_s1("f", str + compt_str) != 0)
	next_line(str, &compt_str, &line);
      else
	{
	  mode_check(str, &compt_str, line, elem);
	  check_end_line(str, compt_str, line);
	  next_line(str, &compt_str, &line);
	}
    }
}
