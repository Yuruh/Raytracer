/*
** check_form.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer/parsing_rt
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Tue Mar 17 17:40:24 2015 Antoine Zanardi
** Last update Mon Jun  1 10:38:17 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"define.h"
#include	"check_form.h"
#include	"cut_str.h"
#include	"fc_base.h"
#include	"fc_str.h"
#include	"check_basic.h"
#include	"error_parsing.h"
#include	"pass_x.h"
#include	"is_x.h"

static int	find_in_id_list(char *str, int *compt_str, t_def *def)
{
  unsigned int	id;
  t_name	*tmp;

  if (is_num_posi(str + *compt_str) == 1)
    return (1);
  id = (unsigned int)(my_getnbr(str + (*compt_str)));
  tmp = def->name;
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

void		correct_form(char *str, int compt_str, int line, t_def *def)
{
  compt_str += 5;
  pass_spaces(str, &compt_str);
  if (!(my_strncmp_on_s1("SPHERE", str + compt_str) == 0 ||
	my_strncmp_on_s1("CONE", str + compt_str) == 0 ||
	my_strncmp_on_s1("PLAN", str + compt_str) == 0 ||
	my_strncmp_on_s1("CYLINDRE", str + compt_str) == 0 ||
	my_strncmp_on_s1("VIEW", str + compt_str) == 0 ||
	my_strncmp_on_s1("LIGHT", str + compt_str) == 0 ||
	my_strncmp_on_s1("PARABOLOID", str + compt_str) == 0 ||
	my_strncmp_on_s1("HYPERBOLOID", str + compt_str) == 0 ||
	my_strncmp_on_s1("ELLIPSOID", str + compt_str) == 0 ||
	my_strncmp_on_s1("TORE", str + compt_str) == 0 ||
	my_strncmp_on_s1("CUBE", str + compt_str) == 0 ||
	my_strncmp_on_s1("DINGDONG", str + compt_str) == 0 ||
	my_strncmp_on_s1("STAR", str + compt_str) == 0 ||
	my_strncmp_on_s1("MOBIUS", str + compt_str) == 0 ||
	find_in_id_list(str, &compt_str, def) == 0))
    my_putstr_error('c', line, 'e');
  while (str[compt_str] >= 'A' && str[compt_str] <= 'Z')
    compt_str++;
  check_end_line(str, compt_str, line);
}

void		check_form(char *str, int line, int compt_param, t_def *def)
{
  int		compt_str;

  compt_str = 0;
  pass_void(str, &compt_str, &line);
  while (str[compt_str] != '\0')
    {
      next_line(str, &compt_str, &line);
      while (my_strncmp_on_s1("</DEF>", str + compt_str) != 0)
	{
	  if (my_strncmp_on_s1("FORM:", str + compt_str) == 0)
	    {
	      correct_form(str, compt_str, line, def);
	      compt_param++;
	    }
	  next_line(str, &compt_str, &line);
	}
      if (compt_param > 1)
	my_putstr_error('c', line, 'c');
      if (compt_param == 0)
	my_putstr_error('c', line, 'd');
      next_line(str, &compt_str, &line);
      compt_param = 0;
    }
}
