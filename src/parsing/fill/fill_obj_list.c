/*
** fill_obj_list.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer/parsing_rt
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed Mar 18 16:28:57 2015 Antoine Zanardi
** Last update Thu Jun  4 10:39:42 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"my.h"
#include	"parsing_rt.h"
#include	"error_parsing.h"
#include	"fill_form.h"
#include	"fill_pos.h"
#include	"fill_rayangle.h"
#include	"fill_obj_list.h"
#include	"fill_percent.h"
#include	"fill_color.h"
#include	"fill_spec.h"
#include	"fill_xpm.h"
#include	"my_lists.h"
#include	"cut_str.h"
#include	"fc_base.h"
#include	"fc_str.h"
#include	"fill_default.h"
#include	"fill_distorsion.h"
#include	"fill_ign_obj.h"
#include	"fill_complex_obj.h"
#include	"fill_sheet.h"
#include	"fill_view_light.h"
#include	"object.h"
#include	"my_free.h"
#include	"check_bool.h"

static int	which_to_fill_3(char *str, int compt, t_obj **obj, t_bool *bool)
{
  if (my_strncmp_on_s1("FOCUS:", str + compt) == 0)
    fill_focus(str, compt, obj, bool);
  else if (my_strncmp_on_s1("SIZE:", str + compt) == 0)
    fill_size(str, compt, obj, bool);
  else if (my_strncmp_on_s1("XPM:", str + compt) == 0)
    fill_xpm(str, compt, obj, bool);
  else if (my_strncmp_on_s1("DISTORSION:", str + compt) == 0)
    fill_dis(str, compt, obj, bool);
  else if (my_strncmp_on_s1("SHEET:", str + compt) == 0)
    fill_sheet(str, compt, obj, bool);
  else
    return (1);
  return (0);
}

int		which_to_fill_2(char *str, int compt, t_obj **obj, t_bool *bool)
{
  if (my_strncmp_on_s1("BRILLANCE:", str + compt) == 0)
    fill_bri(str, compt, obj, bool);
  else if (my_strncmp_on_s1("TRANSPARENCE:", str + compt) == 0)
    fill_trans(str, compt, obj, bool);
  else if (my_strncmp_on_s1("REFLEXION:", str + compt) == 0)
    fill_reflex(str, compt, obj, bool);
  else if (my_strncmp_on_s1("SPECULARITE:", str + compt) == 0)
    fill_spec(str, compt, obj, bool);
  else if (my_strncmp_on_s1("REMPLISSAGE:", str + compt) == 0)
    fill_rempli(str, compt, obj, bool);
  else if (my_strncmp_on_s1("COLOR:", str + compt) == 0)
    fill_color(str, compt, obj, bool);
  else if (my_strncmp_on_s1("DAMIER:", str + compt) == 0)
    fill_damier(str, compt, obj, bool);
  else
    if (which_to_fill_3(str, compt, obj, bool) == 1)
      return (1);
  return (0);
}

int		which_to_fill(char *str, int compt, t_obj **obj, t_bool *bool)
{
  if (my_strncmp_on_s1("FORM:", str + compt) == 0)
    fill_form(str, compt, obj, bool);
  else if (my_strncmp_on_s1("POS:", str + compt) == 0)
    fill_pos(str, compt, obj, bool);
  else if (my_strncmp_on_s1("ROTATE:", str + compt) == 0)
    fill_rot(str, compt, obj, bool);
  else if (my_strncmp_on_s1("H_LIM:", str + compt) == 0)
    fill_h_lim(str, compt, obj, bool);
  else if (my_strncmp_on_s1("B_LIM:", str + compt) == 0)
    fill_b_lim(str, compt, obj, bool);
  else if (my_strncmp_on_s1("RAYON:", str + compt) == 0)
    fill_rayon(str, compt, obj, bool);
  else if (my_strncmp_on_s1("ANGLE:", str + compt) == 0)
    fill_angle(str, compt, obj, bool);
  else if (my_strncmp_on_s1("CIRCONFERENCE:", str + compt) == 0)
    fill_circonference(str, compt, obj, bool);
  else if (my_strncmp_on_s1("VIDEO:", str + compt) == 0)
    fill_video(str, compt, obj, bool);
  else if (my_strncmp_on_s1("LUMOS:", str + compt) == 0)
    fill_lumos(str, compt, obj, bool);
  else
    if (which_to_fill_2(str, compt, obj, bool) == 1)
      return (1);
  return (0);
}

void		fill_obj_list(char *str, t_obj **obj, t_bool *bool, int line)
{
  int		compt_str;

  compt_str = 0;
  pass_void(str, &compt_str, &line);
  while (str[compt_str] != '\0')
    {
      add_top_list(obj);
      init_bool(bool, obj);
      next_line(str, &compt_str, &line);
      while (my_strncmp_on_s1("</DEF>", str + compt_str) != 0)
	{
	  if (which_to_fill(str, compt_str, obj, bool) == 1)
	    my_putstr_error('c', line, 'k');
	  next_line(str, &compt_str, &line);
	}
      check_bool(obj, bool);
      next_line(str, &compt_str, &line);
    }
}
