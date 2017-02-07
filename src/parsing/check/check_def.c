/*
** def.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer/parsing_rt
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Tue Mar 17 14:54:12 2015 Antoine Zanardi
** Last update Thu May 28 17:39:02 2015 Raphael Thiebault
*/

#include	"my.h"
#include	"fc_base.h"
#include	"fc_str.h"
#include	"error_parsing.h"
#include	"check_def.h"
#include	"cut_str.h"

void		find_end_def(char *str, int *compt_str, int *line, int *bool)
{
  pass_void(str, compt_str, line);
  if (my_strncmp_on_s1("<DEF>", str + (*compt_str)) == 0)
    my_putstr_error('c', *line, 'a');
  if (my_strncmp_on_s1("</DEF>", str + (*compt_str)) == 0)
    *bool = 1;
  pass_line(str, compt_str, line);
}

void		check_def(char *str, int line, int compt_str, int bool)
{
  while (str[compt_str] != '\0')
    {
      bool = 0;
      pass_void(str, &compt_str, &line);
      if (my_strncmp_on_s1("<DEF>", str + compt_str) != 0)
	my_putstr_error('c', line, 'a');
      next_line(str, &compt_str, &line);
      if (my_strncmp_on_s1("</DEF>", str + compt_str) == 0)
	my_putstr_error('c', line, 'a');
      while (str[compt_str] != '\0' && bool == 0)
	find_end_def(str, &compt_str, &line, &bool);
    }
  if (bool == 0)
    my_putstr_error('c', line, 'a');
}
