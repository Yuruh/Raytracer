/*
** hyperboloid.c for rt in /home/thieba_r/Documents/IGRAPH/MUL_2014_rtracer
**
** Made by Raphael Thiebault
** Login   <thieba_r@epitech.net>
**
** Started on  Fri May  8 00:54:37 2015 Raphael Thiebault
** Last update Thu Jun  4 17:53:08 2015 Raphael Thiebault
*/

#include	<math.h>
#include	"my.h"
#include	"macro.h"
#include	"object.h"
#include	"shadow.h"
#include	"modif.h"
#include	"calc.h"
#include	"get_k.h"

static void	calc_hyper(t_pos *equ, t_pos *eye, t_pos *vec, t_obj *o)
{
  equ->x = (vec->x * vec->x) / (o->dis.x * o->dis.x) + (vec->y * vec->y) /
    (o->dis.y * o->dis.y) - (((o->lon.ray / 100) * (vec->z * vec->z))
			     /  (o->dis.z * o->dis.z));
  equ->y = (2 * eye->x * vec->x) / (o->dis.x * o->dis.x)
    + (2 * eye->y * vec->y) / (o->dis.y * o->dis.y) -
    ((2 * (o->lon.ray / 100) * vec->z * eye->z) / (o->dis.z * o->dis.z));
  equ->z = (eye->x * eye->x) / (o->dis.x * o->dis.x) + (eye->y * eye->y) /
    (o->dis.y * o->dis.y) - ((o->lon.ray / 100) * (eye->z * eye->z)
			     / (o->dis.z * o->dis.z)) + o->cons.sheet;
}

void		inter_hyper(t_ray_data *d, t_obj *o, t_k *k)
{
  t_pos		equ;
  double	delta;

  k->k = -1;
  calc_hyper(&equ, &EYE, &VEC, o);
  if ((delta = equ.y * equ.y - 4 * equ.x * equ.z) >= 0)
    if ((k->k = MIN((-equ.y - sqrt(delta)) / (2 * equ.x),
		    (-equ.y + sqrt(delta)) / (2 * equ.x))) >= 0)
      {
	d->inter = get_inter(&d->eye_pos_n, *k, &d->v_pos_n);
	if (d->inter.x < o->lim.bot.x || d->inter.x > o->lim.top.x
	    || d->inter.y < o->lim.bot.y || d->inter.y > o->lim.top.y
	    || d->inter.z < o->lim.bot.z || d->inter.z > o->lim.top.z)
	  check_lim(MAX((-equ.y - sqrt(delta)) / (2 * equ.x),
			(-equ.y + sqrt(delta)) / (2 * equ.x)), o, d, k);
      }
}

void		norm_hyper(t_ray_data *d, t_pos *norm)
{
  double	cos;

  norm->x = (2 * d->inter.x) / (d->obj->dis.x * d->obj->dis.x);
  norm->y = (2 * d->inter.y) / (d->obj->dis.y * d->obj->dis.y);
  norm->z = -((2 * d->inter.z) / (d->obj->dis.z * d->obj->dis.z)
	      * (d->obj->lon.ray / 100));
  if (!d->inter.is_sec)
    {
      norm->x *= -1;
      norm->y *= -1;
      norm->z *= -1;
    }
  go_derotate(&norm->x, &norm->y, &norm->z, &d->obj->rot);
  normalise(norm);
  cos = DOT(*norm, d->v_dir_n);
  if (cos > 0)
    {
      norm->x *= -1;
      norm->y *= -1;
      norm->z *= -1;
    }
}

void		shdw_hyper(t_dir *lum, double *shadow, t_obj *o, t_lux *lux)
{
  t_dir		real;
  t_k		k;
  t_pos		equ;

  real = *lum;
  launch_modif(&real.init, &real.vec, o);
  calc_hyper(&equ, &real.init, &real.vec, o);
  shdw_lim(&equ, &k, o, &real);
  if (lux->form == SPHERE && k.k > 0.0 && k.k < 0.99)
    *shadow += 1 - o->cons.tra;
  else if (lux->form == PLAN && k.k > 0.0)
    *shadow += 1 - o->cons.tra;
}
