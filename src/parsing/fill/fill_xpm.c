/*
** fill_xpm.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Thu May  7 00:51:18 2015 Antoine Zanardi
** Last update Wed May 27 11:55:56 2015 Corentin Descamps
*/

#include	"my.h"
#include	"object.h"
#include	"parsing_rt.h"
#include	"fc_str.h"
#include	"fc_base.h"
#include	"pass_x.h"
#include	"cut_str.h"
#include	"fill_xpm.h"

void		fill_xpm(char *str, int compt_str, t_obj **obj, t_bool *bool)
{
  pass_label(str, &compt_str);
  pass_spaces(str, &compt_str);
  (*obj)->xpm.xpm = my_getnbr(str + compt_str);
  bool->xpm++;
}

void		fill_video(char *str, int compt_str, t_obj **obj, t_bool *bool)
{
  pass_label(str, &compt_str);
  pass_spaces(str, &compt_str);
  (*obj)->video.id = my_getnbr(str + compt_str);
  bool->video++;
}
