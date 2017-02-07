/*
** fill_color.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer/parsing_rt
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed Mar 18 23:28:11 2015 Antoine Zanardi
** Last update Thu May 28 15:13:13 2015 Antoine Zanardi
*/

#include	"my.h"
#include	"parsing_rt.h"
#include	"object.h"
#include	"fill_color.h"
#include	"my_getnbr_hexa.h"
#include	"pass_x.h"

int		get_color(char *str, int compt_str)
{
  compt_str += 2;
  return (my_getnbr_hexa(str + compt_str));
}

void		fill_color(char *str, int compt_str, t_obj **obj, t_bool *bool)
{
  pass_label(str, &compt_str);
  (*obj)->src_col = get_color(str, compt_str);
  bool->color++;
}

void		fill_damier(char *str, int compt_str, t_obj **obj, t_bool *bool)
{
  pass_label(str, &compt_str);
  (*obj)->damier_col = get_color(str, compt_str);
  bool->damier++;
}

void		fill_focus(char *str, int compt_str, t_obj **obj, t_bool *bool)
{
  pass_label(str, &compt_str);
  (*obj)->cons.focus = my_getnbr(str + compt_str);
  bool->focus++;
}

void		fill_lumos(char *str, int compt_str, t_obj **obj, t_bool *bool)
{
  pass_label(str, &compt_str);
  (*obj)->cons.lumos = my_getnbr(str + compt_str);
  bool->lumos++;
}
