/*
** fill_pos.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer/parsing_rt
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed Mar 18 17:26:53 2015 Antoine Zanardi
** Last update Thu May 28 19:29:18 2015 Raphael Thiebault
*/

#include	<stdlib.h>
#include	"my.h"
#include	"fc_str.h"
#include	"my_getnbr.h"
#include	"object.h"
#include	"fill_pos.h"
#include	"pass_x.h"
#include	"parsing_rt.h"
#include	"error_parsing.h"

double		get_pos(char *str, int *compt_str)
{
  pass_spaces(str, compt_str);
  (*compt_str)++;
  pass_spaces(str, compt_str);
  (*compt_str)++;
  pass_spaces(str, compt_str);
  return (my_getnbr(str + (*compt_str)));
}

void		fill_pos(char *str, int compt_str, t_obj **obj, t_bool *bool)
{
  pass_label(str, &compt_str);
  (*obj)->pos.x = get_pos(str, &compt_str);
  pass_num(str, &compt_str);
  (*obj)->pos.y = get_pos(str, &compt_str);
  pass_num(str, &compt_str);
  (*obj)->pos.z = get_pos(str, &compt_str);
  pass_num(str, &compt_str);
  bool->pos++;
}

void		fill_rot(char *str, int compt_str, t_obj **obj, t_bool *bool)
{
  pass_label(str, &compt_str);
  (*obj)->rot.x = D_R(get_pos(str, &compt_str));
  pass_num(str, &compt_str);
  (*obj)->rot.y = D_R(get_pos(str, &compt_str));
  pass_num(str, &compt_str);
  (*obj)->rot.z = D_R(get_pos(str, &compt_str));
  pass_num(str, &compt_str);
  bool->rot++;
}

void		fill_h_lim(char *str, int compt_str, t_obj **obj, t_bool *bool)
{
  pass_label(str, &compt_str);
  (*obj)->lim.top.x = get_pos(str, &compt_str);
  pass_num(str, &compt_str);
  (*obj)->lim.top.y = get_pos(str, &compt_str);
  pass_num(str, &compt_str);
  (*obj)->lim.top.z = get_pos(str, &compt_str);
  pass_num(str, &compt_str);
  bool->h_lim++;
}

void		fill_b_lim(char *str, int compt_str, t_obj **obj, t_bool *bool)
{
  pass_label(str, &compt_str);
  (*obj)->lim.bot.x = get_pos(str, &compt_str);
  pass_num(str, &compt_str);
  (*obj)->lim.bot.y = get_pos(str, &compt_str);
  pass_num(str, &compt_str);
  (*obj)->lim.bot.z = get_pos(str, &compt_str);
  pass_num(str, &compt_str);
  bool->b_lim++;
}
