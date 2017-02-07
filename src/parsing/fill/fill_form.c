/*
** fill_form.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer/parsing_rt
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed Mar 18 17:02:52 2015 Antoine Zanardi
** Last update Mon Jun  1 10:40:51 2015 Antoine Zanardi
*/

#include	"my.h"
#include	"object.h"
#include	"fill_form.h"
#include	"parsing_rt.h"
#include	"fc_str.h"
#include	"fc_base.h"
#include	"pass_x.h"
#include	"cut_str.h"

static void	fill_form_2(char *str, int compt_str, t_obj **obj)
{
  if (my_strncmp_on_s1("PARABOLOID", str + compt_str) == 0)
    (*obj)->type = PARABOLOID;
  else if (my_strncmp_on_s1("HYPERBOLOID", str + compt_str) == 0)
    (*obj)->type = HYPERBOLOID;
  else if (my_strncmp_on_s1("ELLIPSOID", str + compt_str) == 0)
    (*obj)->type = ELLIPSOID;
  else if (my_strncmp_on_s1("TORE", str + compt_str) == 0)
    (*obj)->type = TORE;
  else if (my_strncmp_on_s1("CUBE", str + compt_str) == 0)
    (*obj)->type = CUBE;
  else if (my_strncmp_on_s1("DINGDONG", str + compt_str) == 0)
    (*obj)->type = DD;
  else if (my_strncmp_on_s1("STAR", str + compt_str) == 0)
    (*obj)->type = STAR;
  else if (my_strncmp_on_s1("MOBIUS", str + compt_str) == 0)
    (*obj)->type = MOBIUS;
  else
    {
      (*obj)->type = IGN;
      (*obj)->damier_col = my_getnbr(str + compt_str);
    }
}

void		fill_form(char *str, int compt_str, t_obj **obj, t_bool *bool)
{
  pass_label(str, &compt_str);
  pass_spaces(str, &compt_str);
  if (my_strncmp_on_s1("VIEW", str + compt_str) == 0)
    (*obj)->type = VIEW;
  else if (my_strncmp_on_s1("LIGHT", str + compt_str) == 0)
    (*obj)->type = LIGHT;
  else if (my_strncmp_on_s1("SPHERE", str + compt_str) == 0)
    (*obj)->type = SPHERE;
  else if (my_strncmp_on_s1("CONE", str + compt_str) == 0)
    (*obj)->type = CONE;
  else if (my_strncmp_on_s1("PLAN", str + compt_str) == 0)
    (*obj)->type = PLAN;
  else if (my_strncmp_on_s1("CYLINDRE", str + compt_str) == 0)
    (*obj)->type = CYLINDRE;
  else
    fill_form_2(str, compt_str, obj);
  bool->form = (*obj)->type;
}
