/*
** cyl.c for rtv in /home/lemper_a/rendu/igraph/MUL_2014_rtv1
**
** Made by Antoine LEMPEREUR
** Login   <lemper_a@epitech.net>
**
** Started on  Thu Feb 12 10:48:49 2015 Antoine LEMPEREUR
** Last update Fri May 29 17:25:40 2015 Raphael Thiebault
*/

#include	<math.h>
#include	"my.h"
#include	"macro.h"
#include	"cyl.h"
#include	"delta.h"
#include	"calc.h"
#include	"modif.h"
#include	"shadow.h"
#include	"get_k.h"

void		norm_cyl(t_ray_data *d, t_pos *norm)
{
  if (!(d->inter.is_sec))
    {
      norm->x = d->inter.x;
      norm->y = d->inter.y;
      norm->z = 0;
    }
  else
    {
      norm->x = -d->inter.x;
      norm->y = -d->inter.y;
      norm->z = 0;
    }
  go_derotate(&norm->x, &norm->y, &norm->z, &d->obj->rot);
  normalise(norm);
}

void		inter_cyl(t_ray_data *d, t_obj *o, t_k *k)
{
  t_pos		equ;
  double	delta;

  equ.x = VEC.x * VEC.x + VEC.y * VEC.y;
  equ.y = 2 * (EYE.x * VEC.x + EYE.y * VEC.y);
  equ.z = EYE.x * EYE.x + EYE.y * EYE.y - RAY * RAY;
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

void		shdw_cyl(t_dir *lum, double *shadow, t_obj *o, t_lux *lux)
{
  t_dir		real;
  t_k		k;
  t_pos		equ;

  real.init = lum->init;
  real.vec = lum->vec;
  launch_modif(&real.init, &real.vec, o);
  equ.x = real.vec.x * real.vec.x + real.vec.y * real.vec.y;
  equ.y = 2 * (real.init.x * real.vec.x + real.init.y * real.vec.y);
  equ.z = real.init.x * real.init.x + real.init.y * real.init.y -
    o->lon.ray * o->lon.ray;
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
