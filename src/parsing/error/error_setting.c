/*
** error_setting.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Tue May 26 13:43:10 2015 Antoine Zanardi
** Last update Wed Jun  3 14:05:06 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"my.h"
#include	"parsing_rt.h"
#include	"error_obj.h"
#include	"fc_base.h"
#include	"error_setting.h"

static void	error_setting_2(t_bool *bool)
{
  if (bool->form == ELLIPSOID)
    my_putstr("an ellipsoid.\n");
  else if (bool->form == PARABOLOID)
    my_putstr("a paraboloid.\n");
  else if (bool->form == TORE)
    my_putstr("a tore.\n");
  else if (bool->form == CUBE)
    my_putstr("a cube.\n");
  else if (bool->form == DD)
    my_putstr("a ding-dong.\n");
  else if (bool->form == STAR)
    my_putstr("a star.\n");
  else if (bool->form == MOBIUS)
    my_putstr("a mobius.\n");
}

int		error_setting(t_bool *bool)
{
  my_putstr("Too much settings set for ");
  if (bool->form == VIEW)
    my_putstr("a view.\n");
  else if (bool->form == LIGHT)
    my_putstr("a light.\n");
  else if (bool->form == SPHERE)
    my_putstr("a sphere.\n");
  else if (bool->form == CONE)
    my_putstr("a cone.\n");
  else if (bool->form == PLAN)
    my_putstr("a plan.\n");
  else if (bool->form == CYLINDRE)
    my_putstr("a cylinder.\n");
  else if (bool->form == IGN)
    my_putstr("a .obj file.\n");
  else if (bool->form == HYPERBOLOID)
    my_putstr("an hyperboloid.\n");
  else
    error_setting_2(bool);
  exit(1);
}
