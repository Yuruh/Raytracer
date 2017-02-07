/*
** paraboloid.c for rt in /home/thieba_r/Documents/IGRAPH/MUL_2014_rtracer
**
** Made by Raphael Thiebault
** Login   <thieba_r@epitech.net>
**
** Started on  Thu May  7 20:42:43 2015 Raphael Thiebault
** Last update Wed Jun  3 12:19:52 2015 Raphael Thiebault
*/

#include	<math.h>
#include	"macro.h"
#include	"shadow.h"
#include	"get_k.h"
#include	"modif.h"
#include	"my.h"
#include	"object.h"
#include	"calc.h"

static void	calc_para(t_pos *equ, t_pos *vec, t_pos *eye, t_obj *o)
{
  equ->x = (vec->x * vec->x) * o->dis.x + (vec->y * vec->y) * o->dis.y;
  equ->y = 2 * ((eye->x * vec->x) * o->dis.x + (eye->y * vec->y) * o->dis.y)
    - (o->lon.ray / 100) * vec->z;
  equ->z = (eye->x * eye->x) * o->dis.x + (eye->y * eye->y) * o->dis.y
    - (o->lon.ray / 100) * eye->z;
}

void		inter_para(t_ray_data *d, t_obj *o, t_k *k)
{
  t_pos		equ;
  double	delta;

  calc_para(&equ, &VEC, &EYE, o);
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

void		norm_para(t_ray_data *d, t_pos *norm)
{
  if (!(d->inter.is_sec))
    {
      norm->x = d->inter.x;
      norm->y = d->inter.y;
      norm->z = d->inter.y * (d->obj->lon.ray / 100);
    }
  else
    {
      norm->x = -(d->inter.x);
      norm->y = -(d->inter.y);
      norm->z = -(d->inter.y * (d->obj->lon.ray / 100));
    }
  go_derotate(&norm->x, &norm->y, &norm->z, &d->obj->rot);
  normalise(norm);
}

void		shdw_para(t_dir *lum, double *shadow, t_obj *o, t_lux *lux)
{
  t_dir		real;
  t_k		k;
  t_pos		equ;

  real = *lum;
  launch_modif(&real.init, &real.vec, o);
  calc_para(&equ, &real.vec, &real.init, o);
  shdw_lim(&equ, &k, o, &real);
  if (lux->form == SPHERE && k.k > 0.0 && k.k < 0.99)
    *shadow += 1 - o->cons.tra;
  else if (lux->form == PLAN && k.k > 0.0)
    *shadow += 1 - o->cons.tra;
}
