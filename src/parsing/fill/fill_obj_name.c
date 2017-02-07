/*
** fill_obj_name.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Thu Mar 26 13:28:19 2015 Antoine Zanardi
** Last update Thu May 28 18:12:59 2015 Raphael Thiebault
*/

#include	<stdlib.h>
#include	"my.h"
#include	"define.h"
#include	"cut_str.h"
#include	"error_parsing.h"
#include	"fc_str.h"
#include	"fill_obj_name.h"
#include	"my_getnbr.h"
#include	"pass_x.h"
#include	"is_x.h"

int		add_name_list(t_name **list, char *str, unsigned int id)
{
  t_name	*elem;

  if ((elem = malloc(sizeof(t_name))) == NULL)
    return (0);
  elem->next = *list;
  elem->prev = NULL;
  elem->name = str;
  elem->id = id;
  if (*list != NULL)
    (*list)->prev = elem;
  *list = elem;
  return (0);
}

void		fill_obj_name(char *str, int compt_str, t_name **name, int line)
{
  unsigned int	id;

  compt_str += 3;
  pass_spaces(str, &compt_str);
  if (is_num_posi(str + compt_str) == 1)
    my_putstr_error('c', line, 't');
  id = (unsigned int)my_getnbr(str + compt_str);
  pass_num(str, &compt_str);
  pass_spaces(str, &compt_str);
  if (str[compt_str] == '\n' || str[compt_str] == '\0')
    my_putstr_error('c', line, 'r');
  add_name_list(name, my_strdup(str, compt_str), id);
  while (str[compt_str] != '\0' && str[compt_str] != '\n' &&
	 str[compt_str] != ' ' && str[compt_str] != '\t')
    compt_str++;
  pass_spaces(str, &compt_str);
  if (str[compt_str] != '\n' && str[compt_str] != '\0')
    my_putstr_error('c', line, 'o');
}
