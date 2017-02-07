/*
** check_bool.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Thu Jun  4 10:39:02 2015 Antoine Zanardi
** Last update Thu Jun  4 10:45:24 2015 Antoine Zanardi
*/

#include	"my.h"
#include	"object.h"
#include	"parsing_rt.h"
#include	"check_bool.h"
#include	"fill_default.h"
#include	"fill_ign_obj.h"
#include	"fill_complex_obj.h"
#include	"fill_view_light.h"

static void	check_bool_2(t_obj **obj, t_bool *bool)
{
  if (bool->form == ELLIPSOID)
    fill_ellipsoid(obj, bool);
  else if (bool->form == TORE)
    fill_tore(obj, bool);
  else if (bool->form == CUBE)
    fill_cube(obj, bool);
  else if (bool->form == DD)
    fill_dingdong(obj, bool);
  else if (bool->form == STAR)
    fill_star(obj, bool);
  else if (bool->form == MOBIUS)
    fill_moebius(obj, bool);
}

void		check_bool(t_obj **obj, t_bool *bool)
{
  if (bool->form == LIGHT)
    fill_light(obj, bool);
  else if (bool->form == VIEW)
    fill_view(obj, bool);
  else if (bool->form == SPHERE || bool->form == CYLINDRE)
    fill_sphecy(obj, bool);
  else if (bool->form == CONE)
    fill_cone(obj, bool);
  else if (bool->form == PLAN)
    fill_plan(obj, bool);
  else if (bool->form == IGN)
    fill_ign_obj(obj, bool);
  else if (bool->form == PARABOLOID)
    fill_paraboloid(obj, bool);
  else if (bool->form == HYPERBOLOID)
    fill_hyperboloid(obj, bool);
  else
    check_bool_2(obj, bool);
}
