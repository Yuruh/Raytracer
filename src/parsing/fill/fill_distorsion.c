/*
** fill_distorsion.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Fri May  8 15:22:33 2015 Antoine Zanardi
** Last update Tue Jun  2 09:40:39 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"macro.h"
#include	"my.h"
#include	"pass_x.h"
#include	"fc_str.h"
#include	"fill_percent.h"
#include	"my_getnbr.h"
#include	"object.h"
#include	"parsing_rt.h"
#include	"fill_distorsion.h"

void		fill_dis(char *str, int compt_str, t_obj **obj, t_bool *bool)
{
  pass_label(str, &compt_str);
  (*obj)->dis.x = my_getnbr(str + compt_str);
  pass_num(str, &compt_str);
  pass_spaces(str, &compt_str);
  (*obj)->dis.y = my_getnbr(str + compt_str);
  pass_num(str, &compt_str);
  pass_spaces(str, &compt_str);
  (*obj)->dis.z = my_getnbr(str + compt_str);
  bool->dis++;
}
