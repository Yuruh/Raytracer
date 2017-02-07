/*
** sphere.c for rtv in /home/lemper_a/rendu/igraph/MUL_2014_rtv1
**
** Made by Antoine LEMPEREUR
** Login   <lemper_a@epitech.net>
**
** Started on  Thu Feb 12 01:55:55 2015 Antoine LEMPEREUR
** Last update Wed Jun  3 15:10:59 2015 Raphael Thiebault
*/

#include	<math.h>
#include	"macro.h"
#include	"sphere.h"
#include	"my.h"
#include	"calc.h"
#include	"modif.h"
#include	"delta.h"
#include	"shadow.h"
#include	"get_k.h"

void		inter_sphere(t_ray_data *d, t_obj *o, t_k *k)
{
  t_pos		equ;
  double	delta;

  equ.x = VEC.x * VEC.x + VEC.y * VEC.y + VEC.z * VEC.z;
  equ.y = 2 * (EYE.x * VEC.x + EYE.y * VEC.y + EYE.z * VEC.z);
  equ.z = EYE.x * EYE.x + EYE.y * EYE.y + EYE.z * EYE.z - RAY * RAY;
  if ((delta = equ.y * equ.y - 4 * equ.x * equ.z) >= 0)
    {
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
  else
    k->k = -2;
}

void		norm_sphere(t_ray_data *d, t_pos *norm)
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

void		shdw_sphere(t_dir *lum, double *shadow, t_obj *o, t_lux *lux)
{
  t_dir		real;
  t_k		k;
  t_pos		equ;

  real = *lum;
  launch_modif(&real.init, &real.vec, o);
  equ.x = real.vec.x * real.vec.x + real.vec.y * real.vec.y
    + real.vec.z * real.vec.z;
  equ.y = 2 * (real.init.x * real.vec.x + real.init.y *
	       real.vec.y + real.init.z * real.vec.z);
  equ.z = real.init.x * real.init.x + real.init.y * real.init.y
    + real.init.z * real.init.z - o->lon.ray * o->lon.ray;
  shdw_lim(&equ, &k, o, &real);
  if (lux->form == SPHERE)
    {
      if (k.k > 0.0 && k.k < 0.99)
	*shadow += 1 - o->cons.tra;
    }
  else if (lux->form == PLAN)
    {
      if (k.k > 0.0)
	*shadow += 1 - o->cons.tra;
    }
}
