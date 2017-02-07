/*
** fill_ign_obj.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Mon May  4 01:10:13 2015 Antoine Zanardi
** Last update Thu Jun  4 14:18:39 2015 Raphael Thiebault
*/

#include	"my.h"
#include	"object.h"
#include	"parsing_rt.h"
#include	"fill_ign_obj.h"
#include	"error_parsing.h"
#include	"error_obj.h"
#include	"fill_default.h"
#include	"fill_rolim.h"

void		fill_ign_obj(t_obj **obj, t_bool *bool)
{
  fill_rolim(obj, bool);
  fill_defaut(obj, bool);
  if (bool->size == 0)
    (*obj)->lon.size = 1.0;
  if (bool->spec == 0)
    (*obj)->cons.spec = 0.0;
  if (bool->angle > 0 || bool->damier > 0 || bool->rayon > 0 || bool->dis > 0
      || bool->xpm > 0 || bool->circonference > 0 || bool->rempli > 0
      || bool->lumos > 0 || bool->sheet > 0)
    error_setting(bool);
}

void		fill_paraboloid(t_obj **obj, t_bool *bool)
{
  fill_rolim(obj, bool);
  fill_defaut(obj, bool);
  if (bool->rayon == 0)
    (*obj)->lon.ray = 2.5;
  if (bool->size == 0)
    (*obj)->lon.size = 1.0;
  if (bool->spec == 0)
    (*obj)->cons.spec = 0.0;
  if (bool->sheet == 0)
    (*obj)->cons.sheet = -1;
  if (bool->angle > 0 || bool->circonference > 0 || bool->rempli > 0 ||
      bool->xpm > 0 || bool->lumos > 0)
    error_setting(bool);
}

void		fill_hyperboloid(t_obj **obj, t_bool *bool)
{
  fill_rolim(obj, bool);
  fill_defaut(obj, bool);
  if (bool->rayon == 0)
    (*obj)->lon.ray = 2.5;
  if (bool->size == 0)
    (*obj)->lon.size = 1.0;
  if (bool->spec == 0)
    (*obj)->cons.spec = 0.0;
  if (bool->sheet == 0)
    (*obj)->cons.sheet = -1;
  if (bool->angle > 0 || bool->circonference > 0 || bool->rempli > 0 ||
      bool->xpm > 0 || bool->lumos > 0)
    error_setting(bool);
}

void		fill_ellipsoid(t_obj **obj, t_bool *bool)
{
  fill_rolim(obj, bool);
  fill_defaut(obj, bool);
  if (bool->rayon == 0)
    (*obj)->lon.ray = 2.5;
  if (bool->size == 0)
    (*obj)->lon.size = 1.0;
  if (bool->spec == 0)
    (*obj)->cons.spec = 0.0;
  if (bool->sheet == 0)
    (*obj)->cons.sheet = -1;
  if (bool->angle > 0 || bool->circonference > 0 || bool->rempli > 0 ||
      bool->xpm > 0 || bool->lumos > 0)
    error_setting(bool);
}

void		fill_tore(t_obj **obj, t_bool *bool)
{
  fill_rolim(obj, bool);
  fill_defaut(obj, bool);
  if (bool->rayon == 0)
    (*obj)->lon.ray = 2.5;
  if (bool->size == 0)
    (*obj)->lon.size = 1.0;
  if (bool->spec == 0)
    (*obj)->cons.spec = 0.0;
  if (bool->circonference == 0)
    (*obj)->lon.circonference = 10;
  if (bool->angle > 0 || bool->dis > 0 || bool->rempli > 0 ||
      bool->xpm > 0 || bool->lumos > 0 || bool->sheet > 0)
    error_setting(bool);
}
