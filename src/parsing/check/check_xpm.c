/*
** check_xpm.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed May  6 23:42:19 2015 Antoine Zanardi
** Last update Thu May 28 17:25:29 2015 Raphael Thiebault
*/

#include	<stdlib.h>
#include	"define.h"
#include	"check_xpm.h"
#include	"cut_str.h"
#include	"fc_base.h"
#include	"fc_str.h"
#include	"check_basic.h"
#include	"error_parsing.h"
#include	"pass_x.h"
#include	"is_x.h"

static int	find_xpm_list(char *str, int *compt_str, t_def *def)
{
  unsigned int	id;
  t_xpm		*tmp;

  if (is_num_posi(str + *compt_str) == 1)
    return (1);
  id = (unsigned int)(my_getnbr(str + (*compt_str)));
  tmp = def->xpm;
  while (tmp != NULL)
    {
      if (tmp->id == id)
	{
	  pass_num(str, compt_str);
	  return (0);
	}
      tmp = tmp->next;
    }
  return (1);
}

static void	correct_xpm(char *str, int compt_str, int line, t_def *def)
{
  compt_str += 4;
  pass_spaces(str, &compt_str);
  if (find_xpm_list(str, &compt_str, def) == 1)
    my_putstr_error('c', line, 'w');
  check_end_line(str, compt_str, line);
}

void		check_xpm(char *str, int line, int compt_param, t_def *def)
{
  int		compt_str;

  compt_str = 0;
  pass_void(str, &compt_str, &line);
  while (str[compt_str] != '\0')
    {
      next_line(str, &compt_str, &line);
      while (my_strncmp_on_s1("</DEF>", str + compt_str) != 0)
	{
	  if (my_strncmp_on_s1("XPM:", str + compt_str) == 0)
	    {
	      correct_xpm(str, compt_str, line, def);
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
