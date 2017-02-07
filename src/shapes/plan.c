/*
** plan.c for rt in /home/thieba_r/Documents/IGRAPH/MUL_2014_rtracer
**
** Made by Raphael Thiebault
** Login   <thieba_r@epitech.net>
**
** Started on  Sat May  2 17:05:43 2015 Raphael Thiebault
** Last update Sun Jun  7 14:30:54 2015 Raphael Thiebault
*/

#include	<float.h>
#include	<math.h>
#include	"calc.h"
#include	"my.h"
#include	"modif.h"
#include	"get_k.h"

int		is_inter_plan(t_lux *lux, t_dir *lum)
{
  double	k1;
  double	k2;
  t_k		k;
  t_inter	inter;
  t_dir		dir;

  if (lux->lim.bot.x == -DBL_MAX && lux->lim.bot.y == -DBL_MAX &&
      lux->lim.bot.z == -DBL_MAX && lux->lim.top.x == DBL_MAX &&
      lux->lim.top.z == DBL_MAX && lux->lim.top.z == DBL_MAX)
    return (1);
  dir = *lum;
  launch_modif_plan_lum(&dir.init, &dir.vec, &lux->pos, &lux->rot);
  k.k = -1 * dir.init.z / dir.vec.z;
  inter = get_inter(&dir.init, k, &dir.vec);
  if (lux->lim.bot.x == 0.0)
    lux->lim.bot.x = 0.0001;
  k2 = (lux->lim.bot.x * inter.y - lux->lim.bot.y * inter.x)
    / (lux->lim.top.y * lux->lim.bot.x - lux->lim.bot.y * lux->lim.top.x);
  k1 = (inter.x - k2 * lux->lim.top.x) / lux->lim.bot.x;
  if (k.k >= 0 && (k2 > 0 && k2 < 1) && (k1 > 0 && k1 < 1))
    return (1);
  return (0);
}

void		inter_plan(t_ray_data *d, t_obj *o, t_k *k)
{
  double	k1;
  double	k2;

  k->k = -1;
  if (VEC.z != 0.0)
    k->k *= EYE.z / VEC.z;
  k->is_sec = 0;
  d->inter = get_inter(&EYE, *k, &VEC);
  if (o->lim.bot.x == 0.0)
    o->lim.bot.x = 0.0001;
  if (o->lim.bot.x == -DBL_MAX && o->lim.bot.y == -DBL_MAX &&
      o->lim.bot.z == -DBL_MAX && o->lim.top.x == DBL_MAX &&
      o->lim.top.z == DBL_MAX && o->lim.top.z == DBL_MAX)
    {
      if (!(k->k >= 0))
	k->k = -3;
    }
  else
    {
      k2 = (o->lim.bot.x * d->inter.y - o->lim.bot.y * d->inter.x)
	/ (o->lim.top.y * o->lim.bot.x - o->lim.bot.y * o->lim.top.x);
      k1 = (d->inter.x - k2 * o->lim.top.x) / o->lim.bot.x;
      if (!(k->k >= 0 && (k2 > 0 && k2 < 1) && (k1 > 0 && k1 < 1)))
	k->k = -3;
    }
}

t_pos		norm_plan_lumin(t_lux *lux, t_obj *obj)
{
  t_pos		norm;
  t_pos		vec;

  vec.x = lux->pos.x - obj->pos.x;
  vec.y = lux->pos.y - obj->pos.y;
  vec.z = lux->pos.z - obj->pos.z;
  norm.x = 0;
  norm.y = 0;
  norm.z = 1;
  go_derotate(&norm.x, &norm.y, &norm.z, &lux->rot);
  normalise(&norm);
  normalise(&vec);
  if (DOT(vec, norm) < 0)
    {
      norm.x *= -1;
      norm.y *= -1;
      norm.z *= -1;
    }
  return (norm);
}

void		norm_plan(t_ray_data *ray, t_pos *norm)
{
  double	cos;

  norm->x = 0;
  norm->y = 0;
  norm->z = 1;
  go_derotate(&norm->x, &norm->y, &norm->z, &ray->obj->rot);
  normalise(norm);
  cos = DOT(*norm, ray->v_dir_n);
  if (cos > 0)
    {
      norm->x *= -1;
      norm->y *= -1;
      norm->z *= -1;
    }
}

void		shdw_plan(t_dir *lum, double *shadow, t_obj *o, t_lux *lux)
{
  t_dir		real;
  double	k1;
  double	k2;
  t_k		k;
  t_inter	inter;

  real = *lum;
  launch_modif(&real.init, &real.vec, o);
  k.k = -1 * real.init.z / real.vec.z;
  k.is_sec = 0;
  inter = get_inter(&real.init, k, &real.vec);
  if (o->lim.bot.x == 0.0)
    o->lim.bot.x = 0.0001;
  if (o->lim.is_lim == 1)
    {
      k2 = (o->lim.bot.x * inter.y - o->lim.bot.y * inter.x)
	/ (o->lim.top.y * o->lim.bot.x - o->lim.bot.y * o->lim.top.x);
      k1 = (inter.x - k2 * o->lim.top.x) / o->lim.bot.x;
      if (!(k.k >= 0 && (k2 > 0 && k2 < 1) && (k1 > 0 && k1 < 1)))
	k.k = -3;
    }
  if ((lux->form == SPHERE || lux->lim.is_lim == 1) && k.k > 0 && k.k < 0.99)
    *shadow += 1 - o->cons.tra;
  else if (lux->form == PLAN && k.k > 0)
    *shadow += 1 - o->cons.tra;
}
