/*
** check_balise_vid.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Mon May 18 22:55:08 2015 Antoine Zanardi
** Last update Thu May 28 17:27:48 2015 Raphael Thiebault
*/

#include	"my.h"
#include	"fc_base.h"
#include	"fc_str.h"
#include	"error_parsing.h"
#include	"check_balise_vid.h"
#include	"cut_str.h"

static void	find_end_vid(char *str, int *compt_str, int *line, int *bool)
{
  pass_void(str, compt_str, line);
  if (my_strncmp_on_s1("<VID>", str + *compt_str) == 0)
    my_putstr_error('e', *line, 'a');
  if (my_strncmp_on_s1("</VID>", str + *compt_str) == 0)
    *bool = 1;
  pass_line(str, compt_str, line);
}

void		check_balise_vid(char *str, int line, int compt_str, int bool)
{
  while (str[compt_str] != '\0')
    {
      bool = 0;
      pass_void(str, &compt_str, &line);
      if (my_strncmp_on_s1("<VID>", str + compt_str) != 0)
	my_putstr_error('e', line, 'a');
      next_line(str, &compt_str, &line);
      if (my_strncmp_on_s1("</VID>", str + compt_str) == 0)
	my_putstr_error('e', line, 'a');
      while (str[compt_str] != '\0' && bool == 0)
	find_end_vid(str, &compt_str, &line, &bool);
    }
  if (bool == 0)
    my_putstr_error('e', line, 'a');
}
