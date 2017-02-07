/*
** fill_rayangle.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer/parsing_rt
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed Mar 18 18:29:00 2015 Antoine Zanardi
** Last update Wed May 27 11:54:10 2015 Corentin Descamps
*/

#include	"my.h"
#include	"object.h"
#include	"parsing_rt.h"
#include	"my_getnbr.h"
#include	"pass_x.h"
#include	"fc_str.h"
#include	"fill_rayangle.h"

void		fill_angle(char *str, int compt_str, t_obj **obj, t_bool *bool)
{
  double	angle;

  pass_label(str, &compt_str);
  pass_spaces(str, &compt_str);
  angle = my_getnbr(str + compt_str);
  (*obj)->lon.ang = D_R(angle);
  bool->angle++;
}

void		fill_rayon(char *str, int compt_str, t_obj **obj, t_bool *bool)
{
  pass_label(str, &compt_str);
  pass_spaces(str, &compt_str);
  (*obj)->lon.ray = my_getnbr(str + compt_str);
  bool->rayon++;
}

void		fill_circonference(char *str, int compt_str,
				   t_obj **obj, t_bool *bool)
{
  pass_label(str, &compt_str);
  pass_spaces(str, &compt_str);
  (*obj)->lon.circonference = my_getnbr(str + compt_str);
  bool->circonference++;
}
