/*
** fill_xpm_name.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed May  6 22:36:55 2015 Antoine Zanardi
** Last update Thu May 28 18:11:35 2015 Raphael Thiebault
*/

#include	<stdlib.h>
#include	"my.h"
#include	"define.h"
#include	"cut_str.h"
#include	"error_parsing.h"
#include	"fc_str.h"
#include	"fill_xpm_name.h"
#include	"my_getnbr.h"
#include	"pass_x.h"
#include	"is_x.h"

static int	add_xpm_list(t_xpm **list, char *str, unsigned int id)
{
  t_xpm		*elem;

  if ((elem = malloc(sizeof(t_xpm))) == NULL)
    return (0);
  elem->next = *list;
  elem->xpm = str;
  elem->id = id;
  *list = elem;
  return (0);
}

void		fill_xpm_name(char *str, int compt_str, t_xpm **xpm, int line)
{
  unsigned int	id;

  compt_str += 3;
  pass_spaces(str, &compt_str);
  if (is_num_posi(str + compt_str) == 1)
    my_putstr_error('c', line, 'v');
  id = (unsigned int)my_getnbr(str + compt_str);
  pass_num(str, &compt_str);
  pass_spaces(str, &compt_str);
  if (str[compt_str] == '\n' || str[compt_str] == '\0')
    my_putstr_error('c', line, 'r');
  add_xpm_list(xpm, my_strdup(str, compt_str), id);
  while (str[compt_str] != '\0' && str[compt_str] != '\n' &&
	 str[compt_str] != ' ' && str[compt_str] != '\t')
    compt_str++;
  pass_spaces(str, &compt_str);
  if (str[compt_str] != '\n' && str[compt_str] != '\0')
    my_putstr_error('c', line, 'o');
}

void		fill_video_list(char *str, int compt_str, t_xpm **video, int line)
{
  unsigned int	id;

  compt_str += 5;
  pass_spaces(str, &compt_str);
  if (is_num_posi(str + compt_str) == 1)
    my_putstr_error('c', line, 'z');
  id = (unsigned int)my_getnbr(str + compt_str);
  pass_num(str, &compt_str);
  pass_spaces(str, &compt_str);
  if (str[compt_str] == '\n' || str[compt_str] == '\0')
    my_putstr_error('c', line, 'r');
  add_xpm_list(video, my_strdup(str, compt_str), id);
  while (str[compt_str] != '\0' && str[compt_str] != '\n' &&
	 str[compt_str] != ' ' && str[compt_str] != '\t')
    compt_str++;
  pass_spaces(str, &compt_str);
  if (str[compt_str] != '\n' && str[compt_str] != '\0')
    my_putstr_error('c', line, 'o');
}
