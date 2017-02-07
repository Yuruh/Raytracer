/*
** fill_specularite.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed May 20 10:49:54 2015 Antoine Zanardi
** Last update Thu May 28 15:14:50 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"my.h"
#include	"pass_x.h"
#include	"fc_str.h"
#include	"fill_percent.h"
#include	"fill_spec.h"
#include	"my_getnbr.h"
#include	"object.h"
#include	"parsing_rt.h"

void		fill_spec(char *str, int compt_str, t_obj **obj, t_bool *bool)
{
  pass_label(str, &compt_str);
  (*obj)->cons.spec = get_percent(str, compt_str);
  bool->spec++;
}

void		fill_rempli(char *str, int compt_str, t_obj **obj, t_bool *bool)
{
  pass_label(str, &compt_str);
  (*obj)->cons.rempli = get_percent(str, compt_str);
  bool->rempli++;
}
