/*
** fill_complex_obj.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed May 20 14:58:26 2015 Antoine Zanardi
** Last update Mon Jun  1 10:21:40 2015 Antoine Zanardi
*/

#include	"my.h"
#include	"object.h"
#include	"parsing_rt.h"
#include	"fill_ign_obj.h"
#include	"error_parsing.h"
#include	"error_obj.h"
#include	"fill_default.h"
#include	"fill_rolim.h"
#include	"fill_complex_obj.h"

void		fill_cube(t_obj **obj, t_bool *bool)
{
  fill_rolim(obj, bool);
  fill_defaut(obj, bool);
  if (bool->size == 0)
    (*obj)->lon.size = 1.0;
  if (bool->spec == 0)
    (*obj)->cons.spec = 0.0;
  if (bool->circonference == 0)
    (*obj)->lon.circonference = 1;
  if (bool->rempli == 0)
    (*obj)->cons.rempli = 0.5;
  if (bool->angle > 0 || bool->dis > 0 || bool->rayon > 0 ||
      bool->xpm > 0 || bool->lumos > 0 || bool->sheet > 0)
    error_setting(bool);
}

void		fill_dingdong(t_obj **obj, t_bool *bool)
{
  fill_rolim(obj, bool);
  fill_defaut(obj, bool);
  if (bool->size == 0)
    (*obj)->lon.size = 1.0;
  (*obj)->lon.size = 1.0 / (*obj)->lon.size;
  if (bool->spec == 0)
    (*obj)->cons.spec = 0.0;
  if (bool->angle > 0 || bool->dis > 0 || bool->rayon > 0 ||
      bool->xpm > 0 || bool->circonference > 0 || bool->rempli > 0 ||
      bool->lumos > 0 || bool->sheet > 0)
    error_setting(bool);
}

void		fill_star(t_obj **obj, t_bool *bool)
{
  fill_rolim(obj, bool);
  fill_defaut(obj, bool);
  if (bool->size == 0)
    (*obj)->lon.size = 1.0;
  (*obj)->lon.size = 1.0 / (*obj)->lon.size;
  if (bool->spec == 0)
    (*obj)->cons.spec = 0.0;
  if (bool->angle > 0 || bool->dis > 0 || bool->rayon > 0 ||
      bool->xpm > 0 || bool->circonference > 0 || bool->rempli > 0 ||
      bool->lumos > 0 || bool->sheet > 0)
    error_setting(bool);
}

void		fill_moebius(t_obj **obj, t_bool *bool)
{
  fill_rolim(obj, bool);
  fill_defaut(obj, bool);
  if (bool->size == 0)
    (*obj)->lon.size = 1.0;
  (*obj)->lon.size = 1.0 / (*obj)->lon.size;
  if (bool->spec == 0)
    (*obj)->cons.spec = 0.0;
  if (bool->rayon == 0)
    (*obj)->lon.ray = 50.0;
  if (bool->angle > 0 || bool->xpm > 0 ||
      bool->circonference > 0 || bool->rempli > 0 ||
      bool->lumos > 0 || bool->sheet > 0)
    error_setting(bool);
}
