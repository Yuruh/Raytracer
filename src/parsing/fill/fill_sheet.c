/*
** fill_sheet.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Tue May 26 13:12:13 2015 Antoine Zanardi
** Last update Thu May 28 15:24:56 2015 Antoine Zanardi
*/

#include	"my.h"
#include	"parsing_rt.h"
#include	"object.h"
#include	"my_getnbr_hexa.h"
#include	"pass_x.h"
#include	"fill_sheet.h"

void		fill_sheet(char *str, int compt_str, t_obj **obj, t_bool *bool)
{
  pass_label(str, &compt_str);
  if (my_getnbr(str + compt_str) == 1)
    (*obj)->cons.sheet = -1;
  else
    (*obj)->cons.sheet = 1;
  bool->sheet++;
}
