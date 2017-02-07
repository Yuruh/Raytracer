/*
** cone.c for rt in /home/lemper_a/rendu/igraph/MUL_2014_rtv1
**
** Made by Antoine LEMPEREUR
** Login   <lemper_a@epitech.net>
**
** Started on  Sat Feb 14 00:20:48 2015 Antoine LEMPEREUR
** Last update Thu Jun  4 16:55:51 2015 Raphael Thiebault
*/

#include	<math.h>
#include	"macro.h"
#include	"cone.h"
#include	"calc.h"
#include	"delta.h"
#include	"my.h"
#include	"shadow.h"
#include	"modif.h"
#include	"get_k.h"
#include	"parsing_rt.h"

static void	calc_cone(t_pos *equ, t_pos *vec, t_pos *eye, t_obj *o)
{
  equ->x = vec->x * vec->x * (o->dis.x / 10)
    + vec->y * vec->y * (o->dis.y / 10)
    - vec->z * vec->z * (o->dis.z / 10);
  equ->y = 2 * vec->x * eye->x * (o->dis.x / 10)
    + 2 * vec->y * eye->y * (o->dis.y / 10)
    - 2 * vec->z * eye->z * (o->dis.z / 10);
  equ->z = eye->x * eye->x * (o->dis.x / 10)
    + eye->y * eye->y * (o->dis.y / 10)
    - eye->z * eye->z * (o->dis.z / 10);
}

void		inter_cone(t_ray_data *d, t_obj *o, t_k *k)
{
  t_pos		equ;
  double	delta;

  calc_cone(&equ, &VEC, &EYE, o);
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

void		norm_cone(t_ray_data *d, t_pos *norm)
{
  if (!(d->inter.is_sec))
    {
      norm->x = 2 * d->inter.x * (d->obj->dis.x / 10);
      norm->y = 2 * d->inter.y * (d->obj->dis.y / 10);
      norm->z = -(2 * d->inter.z * (d->obj->dis.z / 10));
    }
  else
    {
      norm->x = -(2 * d->inter.x * (d->obj->dis.x / 10));
      norm->y = -(2 * d->inter.y * (d->obj->dis.y / 10));
      norm->z = 2 * d->inter.z * (d->obj->dis.z / 10);
    }
  go_derotate(&norm->x, &norm->y, &norm->z, &d->obj->rot);
  normalise(norm);
}

void		shdw_cone(t_dir *lum, double *shadow, t_obj *o, t_lux *lux)
{
  t_dir		real;
  t_k		k;
  t_pos		equ;

  real.init = lum->init;
  real.vec = lum->vec;
  launch_modif(&real.init, &real.vec, o);
  calc_cone(&equ, &real.vec, &real.init, o);
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
