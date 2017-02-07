/*
** sphere_text.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Sat May  9 20:12:42 2015 Antoine Zanardi
** Last update Thu May 28 15:07:49 2015 Antoine Zanardi
*/

#include	<math.h>
#include	"object.h"
#include	"my.h"
#include	"macro.h"
#include	"get_k.h"
#include	"sphere_text.h"
#include	"trans.h"
#include	"phong.h"
#include	"calc.h"
#include	"color.h"
#include	"modif.h"
#include	"manage_image.h"
#include	"mirror.h"
#include	"fill_info.h"
#include	"light.h"
#include	"shadow.h"

t_pos		cross_product(t_pos *u, t_pos *v)
{
  t_pos		result;

  result.x = (u->y * v->z) - (u->z * v->y);
  result.y = (u->z * v->x) - (u->x * v->z);
  result.z = (u->x * v->y) - (u->y * v->x);
  return (result);
}

int		plan_text(t_obj *obj, t_inter *inter)
{
  t_inter	cpy;
  int		w;
  int		h;
  double	x;
  double	y;

  w = ABS(obj->lim.top.y) + ABS(obj->lim.bot.y);
  h = ABS(obj->lim.top.x) + ABS(obj->lim.bot.x);
  cpy = *inter;
  x = cpy.x / h;
  y = cpy.y / w;
  return (get_pixel_text_color(obj, (int)(y * obj->xpm.xpm_img->width),
			       (int)(x * obj->xpm.xpm_img->height)));
}

static void	calc_vectors(t_obj *obj, t_pos *vn, t_pos *ve)
{
  vn->x = 0;
  vn->y = 0;
  vn->z = -obj->lon.ray;
  go_rotate(&(vn->x), &(vn->y), &(vn->z), &obj->rot);
  ve->x = 0;
  ve->y = obj->lon.ray;
  ve->z = 0;
  go_rotate(&(ve->x), &(ve->y), &(ve->z), &obj->rot);
}

int		sphere_text(t_obj *obj, t_inter point_p)
{
  t_pos		vn;
  t_pos		vp;
  t_pos		ve;
  double	phi;
  double	theta;
  double	x;
  double	y;

  calc_vectors(obj, &vn, &ve);
  vp.x = point_p.x - obj->pos.x;
  vp.y = point_p.y - obj->pos.y;
  vp.z = point_p.z - obj->pos.z;
  normalise(&vn);
  normalise(&ve);
  normalise(&vp);
  phi = acos( - DOT(vn, vp));
  y = phi / M_PI;
  theta = (acos(DOT(vp, ve) / sin(phi))) / (2.0f * M_PI);
  if (DOT(cross_product(&vn, &ve), vp) > 0)
    x = 1 - theta;
  else
    x = theta;
  return (get_pixel_text_color(obj, (int)(x * obj->xpm.xpm_img->width),
			       (int)(y * obj->xpm.xpm_img->height)));
}
