/*
** fill_percent.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer/parsing_rt
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed Mar 18 19:16:26 2015 Antoine Zanardi
** Last update Thu May 28 15:12:04 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"my.h"
#include	"pass_x.h"
#include	"fc_str.h"
#include	"fill_percent.h"
#include	"my_getnbr.h"
#include	"object.h"
#include	"parsing_rt.h"

double		get_percent(char *str, int compt_str)
{
  double	percent;

  percent = (double)(my_getnbr(str + compt_str)) / 100;
  return (percent);
}

void		fill_trans(char *str, int compt_str, t_obj **obj, t_bool *bool)
{
  pass_label(str, &compt_str);
  (*obj)->cons.tra = get_percent(str, compt_str);
  bool->trans++;
}

void		fill_reflex(char *str, int compt_str, t_obj **obj, t_bool *bool)
{
  pass_label(str, &compt_str);
  (*obj)->cons.ref = get_percent(str, compt_str);
  bool->reflex++;
}

void		fill_bri(char *str, int compt_str, t_obj **obj, t_bool *bool)
{
  pass_label(str, &compt_str);
  (*obj)->cons.bril = get_percent(str, compt_str);
  bool->bri++;
}

void		fill_size(char *str, int compt_str, t_obj **obj, t_bool *bool)
{
  pass_label(str, &compt_str);
  (*obj)->lon.size = get_percent(str, compt_str);
  bool->size++;
}
