/*
** fill_default.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer/parsing_rt
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Thu Mar 19 10:23:58 2015 Antoine Zanardi
** Last update Mon Jun  1 22:49:35 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"my.h"
#include	"object.h"
#include	"error_parsing.h"
#include	"error_obj.h"
#include	"fill_default.h"
#include	"parsing_rt.h"
#include	"fill_rolim.h"

void		fill_rolim(t_obj **obj, t_bool *bool)
{
  rolim_h_lim(bool, obj);
  rolim_b_lim(bool, obj);
  rolim_rot(bool, obj);
  rolim_dis(bool, obj);
}

void		fill_defaut(t_obj **obj, t_bool *bool)
{
  if (bool->video == 0)
    (*obj)->video.id = -1;
  if (bool->color == 0)
    (*obj)->src_col = 16777215;
  if (bool->reflex == 0)
    (*obj)->cons.ref = 0.0;
  if (bool->trans == 0)
    (*obj)->cons.tra = 0.0;
  if (bool->bri == 0)
    (*obj)->cons.bril = 0.0;
  if (bool->focus == 0)
    (*obj)->cons.focus = 1;
}

void		fill_cone(t_obj **obj, t_bool *bool)
{
  fill_rolim(obj, bool);
  fill_defaut(obj, bool);
  if (bool->damier == 0)
    (*obj)->damier_col = -1;
  if (bool->size == 0)
    (*obj)->lon.size = 1.0;
  if (bool->xpm == 0)
    (*obj)->xpm.xpm = -1;
  if (bool->spec == 0)
    (*obj)->cons.spec = 0.0;
  if (bool->rayon > 0 || bool->circonference > 0 ||
      bool->lumos > 0 || bool->sheet > 0 || bool->angle > 0)
    error_setting(bool);
}

void		fill_sphecy(t_obj **obj, t_bool *bool)
{
  fill_rolim(obj, bool);
  fill_defaut(obj, bool);
  if (bool->rayon == 0)
    (*obj)->lon.ray = 50.0;
  if (bool->damier == 0)
    (*obj)->damier_col = -1;
  if (bool->size == 0)
    (*obj)->lon.size = 1.0;
  if (bool->xpm == 0)
    (*obj)->xpm.xpm = -1;
  if (bool->spec == 0)
    (*obj)->cons.spec = 0.0;
  if (bool->angle > 0 || bool->dis > 0 || bool->circonference > 0 ||
      bool->lumos > 0 || bool->sheet > 0)
    error_setting(bool);
}

void		fill_plan(t_obj **obj, t_bool *bool)
{
  fill_rolim(obj, bool);
  fill_defaut(obj, bool);
  if (bool->damier == 0)
    (*obj)->damier_col = -1;
  if (bool->angle == 0)
    (*obj)->lon.ang = 0;
  if (bool->size == 0)
    (*obj)->lon.size = 1.0;
  if (bool->xpm == 0)
    (*obj)->xpm.xpm = -1;
  if (bool->spec == 0)
    (*obj)->cons.spec = 0.0;
  if (bool->lumos == 0)
    (*obj)->cons.lumos = 0;
  if (bool->rayon > 0 || bool->dis > 0 || bool->circonference > 0 ||
      bool->sheet > 0)
    error_setting(bool);
}
