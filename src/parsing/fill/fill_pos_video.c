/*
** fill_pos_video.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Tue May 19 00:44:51 2015 Antoine Zanardi
** Last update Wed May 27 11:56:31 2015 Corentin Descamps
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
#include	"fill_pos_video.h"

void		fill_pos_video(char *str, int compt_str, t_video **list)
{
  t_video	*tmp;

  tmp = *list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  pass_label(str, &compt_str);
  tmp->pos.x = get_pos(str, &compt_str);
  pass_num(str, &compt_str);
  tmp->pos.y = get_pos(str, &compt_str);
  pass_num(str, &compt_str);
  tmp->pos.z = get_pos(str, &compt_str);
  pass_num(str, &compt_str);
}

void		fill_rot_video(char *str, int compt_str, t_video **list)
{
  t_video	*tmp;

  tmp = *list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  pass_label(str, &compt_str);
  tmp->rot.x = D_R(get_pos(str, &compt_str));
  pass_num(str, &compt_str);
  tmp->rot.y = D_R(get_pos(str, &compt_str));
  pass_num(str, &compt_str);
  tmp->rot.z = D_R(get_pos(str, &compt_str));
  pass_num(str, &compt_str);
}
