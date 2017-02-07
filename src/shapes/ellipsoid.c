/*
** ellipsoide.c for rt in /home/thieba_r/Documents/IGRAPH/MUL_2014_rtracer
**
** Made by Raphael Thiebault
** Login   <thieba_r@epitech.net>
**
** Started on  Fri May  8 15:29:23 2015 Raphael Thiebault
** Last update Wed Jun  3 14:41:17 2015 Raphael Thiebault
*/

#include	<math.h>
#include	"macro.h"
#include	"my.h"
#include	"get_k.h"
#include	"modif.h"
#include	"shadow.h"
#include	"object.h"
#include	"calc.h"

void		inter_elli(t_ray_data *d, t_obj *o, t_k *k)
{
  t_pos		equ;
  double	delta;

  k->k = -1;
  equ.x = (VEC.x * VEC.x) / (o->dis.x * o->dis.x) +
    (VEC.y * VEC.y) / (o->dis.y * o->dis.y) +
    ((VEC.z * VEC.z) / (o->dis.z * o->dis.z));
  equ.y = 2 * ((EYE.x * VEC.x) / (o->dis.x * o->dis.x) +
	       (EYE.y * VEC.y) / (o->dis.y * o->dis.y) +
	       (EYE.z * VEC.z) / (o->dis.z * o->dis.z));
  equ.z = (EYE.x * EYE.x) / (o->dis.x * o->dis.x) +
    (EYE.y * EYE.y) / (o->dis.y * o->dis.y) +
    ((EYE.z * EYE.z) / (o->dis.z * o->dis.z)) - o->lon.ray * o->lon.ray;
  if ((delta = equ.y * equ.y - 4 * equ.x * equ.z) >= 0)
    if ((k->k = MIN((-equ.y - sqrt(delta)) / (2 * equ.x),
		    (-equ.y + sqrt(delta)) / (2 * equ.x))) >= 0)
      {
	d->inter = get_inter(&d->eye_pos_n, *k, &d->v_pos_n);
	if (d->inter.x < o->lim.bot.x || d->inter.x > o->lim.top.x ||
	    d->inter.y < o->lim.bot.y || d->inter.y > o->lim.top.y
	    || d->inter.z < o->lim.bot.z || d->inter.z > o->lim.top.z)
	  check_lim(MAX((-equ.y - sqrt(delta)) / (2 * equ.x),
			(-equ.y + sqrt(delta)) / (2 * equ.x)), o, d, k);
      }
}

void		norm_elli(t_ray_data *d, t_pos *norm)
{
  if (!(d->inter.is_sec))
    {
      norm->x = d->inter.x;
      norm->y = d->inter.y;
      norm->z = d->inter.z;
    }
  else
    {
      norm->x = -(d->inter.x);
      norm->y = -(d->inter.y);
      norm->z = -(d->inter.z);
    }
  go_derotate(&norm->x, &norm->y, &norm->z, &d->obj->rot);
  normalise(norm);
}

void		shdw_elli(t_dir *l, double *shadow, t_obj *o, t_lux *lux)
{
  t_dir		real;
  t_k		k;
  t_pos		equ;

  real = *l;
  launch_modif(&real.init, &real.vec, o);
  equ.x = (real.vec.x * real.vec.x) / (o->dis.x * o->dis.x) +
    (real.vec.y * real.vec.y) / (o->dis.y * o->dis.y) +
    (real.vec.z * real.vec.z) / (o->dis.z * o->dis.z);
  equ.y = 2 * ((real.init.x * real.vec.x) / (o->dis.x * o->dis.x) +
	       (real.init.y * real.vec.y) / (o->dis.y * o->dis.y) +
	       (real.init.z * real.vec.z) / (o->dis.z * o->dis.z));
  equ.z = (real.init.x * real.init.x) / (o->dis.x * o->dis.x) +
    (real.init.y * real.init.y) / (o->dis.y * o->dis.y) +
    (real.init.z * real.init.z) / (o->dis.z * o->dis.z)
    - o->lon.ray * o->lon.ray;
  shdw_lim(&equ, &k, o, &real);
  if (lux->form == SPHERE)
    {
      if (k.k > 0.0 && k.k < 0.99)
	*shadow += 1 - o->cons.tra;
    }
  else if (lux->form == PLAN)
    if (k.k > 0.0)
      *shadow += 1 - o->cons.tra;
}
