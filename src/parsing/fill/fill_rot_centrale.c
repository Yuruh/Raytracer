/*
** fill_rot_centrale.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed May 20 10:13:07 2015 Antoine Zanardi
** Last update Wed May 27 12:04:39 2015 Corentin Descamps
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
#include	"fill_rot_centrale.h"

void		fill_rot_centrale(char *str, int compt_str, t_video **list)
{
  t_video	*tmp;

  tmp = *list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  pass_label(str, &compt_str);
  tmp->rot_cent.pos.x = get_pos(str, &compt_str);
  pass_num(str, &compt_str);
  tmp->rot_cent.pos.y = get_pos(str, &compt_str);
  pass_num(str, &compt_str);
  tmp->rot_cent.pos.z = get_pos(str, &compt_str);
  pass_num(str, &compt_str);
  pass_spaces(str, &compt_str);
  compt_str++;
  pass_spaces(str, &compt_str);
  tmp->rot_cent.ang.x = D_R(get_pos(str, &compt_str));
  pass_num(str, &compt_str);
  tmp->rot_cent.ang.y = D_R(get_pos(str, &compt_str));
  pass_num(str, &compt_str);
  tmp->rot_cent.ang.z = D_R(get_pos(str, &compt_str));
  pass_num(str, &compt_str);
  tmp->rot_cent.bool = 1;
}
