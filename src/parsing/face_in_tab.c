/*
** face_in_tab.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Thu Jun  4 10:47:22 2015 Antoine Zanardi
** Last update Thu Jun  4 14:15:54 2015 Raphael Thiebault
*/

#include	<stdlib.h>
#include	"my.h"
#include	"object.h"
#include	"fill_obj_tab.h"
#include	"face_in_tab.h"
#include	"fc_base.h"
#include	"fc_str.h"
#include	"cut_str.h"
#include	"error_parsing.h"
#include	"my_free.h"
#include	"pass_x.h"

static int	fill_in_tab(t_parse *info, t_pos *text, t_pos *norm,
			    t_coor *tab)
{
  info->i++;
  if (info->str[info->i] != '/')
    {
      fill_coor(info->str, info->i, &info->pos, &(tab->texture));
      text->x = tab->texture.pos[info->pos - 1].x;
      text->y = tab->texture.pos[info->pos - 1].y;
      text->z = tab->texture.pos[info->pos - 1].z;
      pass_num(info->str, &info->i);
    }
  if (info->str[info->i] == '/')
    {
      info->i++;
      fill_coor(info->str, info->i, &info->pos, &(tab->normale));
      norm->x = tab->normale.pos[info->pos - 1].x;
      norm->y = tab->normale.pos[info->pos - 1].y;
      norm->z = tab->normale.pos[info->pos - 1].z;
    }
  return (info->i);
}

static void	fill_in_point(t_parse *info, t_pos *point, t_coor *tab)
{
  fill_coor(info->str, info->i, &info->pos, &(tab->point));
  point->x = tab->point.pos[info->pos - 1].x;
  point->y = tab->point.pos[info->pos - 1].y;
  point->z = tab->point.pos[info->pos - 1].z;
  pass_num(info->str, &info->i);
}

t_face		face_in_tab(char *str, int compt_str, t_coor *tab)
{
  t_face	coor;
  t_parse	info;

  info.str = str;
  info.i = compt_str + 1;
  info.pos = 0;
  pass_spaces(info.str, &info.i);
  fill_in_point(&info, &coor.pt1, tab);
  if (info.str[info.i] == '/')
    info.i = fill_in_tab(&info, &coor.text1, &coor.norm1, tab);
  pass_coor(info.str, &info.i);
  fill_in_point(&info, &coor.pt2, tab);
  if (info.str[info.i] == '/')
    info.i = fill_in_tab(&info, &coor.text2, &coor.norm2, tab);
  pass_coor(info.str, &info.i);
  fill_in_point(&info, &coor.pt3, tab);
  if (info.str[info.i] == '/')
    info.i = fill_in_tab(&info, &coor.text3, &coor.norm3, tab);
  return (coor);
}
