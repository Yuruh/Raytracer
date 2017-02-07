/*
** shadow.c for azer in /home/lemper_a/rendu/igraph/MUL_2014_rtracer
**
** Made by Antoine LEMPEREUR
** Login   <lemper_a@epitech.net>
**
** Started on  Thu May  7 21:34:41 2015 Antoine LEMPEREUR
** Last update Sat Jun  6 17:28:51 2015 Antoine LEMPEREUR
*/

#include	<math.h>
#include	"macro.h"
#include	"calc.h"
#include	"triangle.h"
#include	"my.h"
#include	"get_k.h"
#include	"vec_func.h"
#include	"object.h"
#include	"shadow.h"

void		shdw_lim(t_pos *equ, t_k *k, t_obj *o, t_dir *real)
{
  double	delta;
  t_inter	inter;

  if ((delta = equ->y * equ->y - 4 * equ->x * equ->z) >= 0)
    {
      if ((k->k = MIN((-equ->y - sqrt(delta)) / (2 * equ->x),
                      (-equ->y + sqrt(delta)) / (2 * equ->x))) >= 0)
        {
          inter = get_inter(&real->init, *k, &real->vec);
          if (inter.x < o->lim.bot.x || inter.x > o->lim.top.x
	      || inter.y < o->lim.bot.y || inter.y > o->lim.top.y
	      || inter.z < o->lim.bot.z || inter.z > o->lim.top.z)
	    {
	      k->k = MAX((-equ->y - sqrt(delta)) / (2 * equ->x),
			 (-equ->y + sqrt(delta)) / (2 * equ->x));
	      inter = get_inter(&real->init, *k, &real->vec);
	      if (inter.x < o->lim.bot.x || inter.x > o->lim.top.x
		  || inter.y < o->lim.bot.y || inter.y > o->lim.top.y
		  || inter.z < o->lim.bot.z || inter.z > o->lim.top.z)
		k->k = -1;
	    }
        }
    }
  else
    k->k = -2;
}

void		shadow_obj(double *shdw, t_dir *opos, t_obj *tmp, t_lux *lux)
{
  t_k		k;
  t_triangle	*s;

  k.k = inter_box(&tmp->lim, &opos->vec, &opos->init);
  if (k.k > 0 && k.k < 0.99)
    {
      k = pick_k_tri(tmp->triangle, opos, &s);
      if (lux->form == SPHERE)
	{
	  if (k.k > 0.0 && k.k < 0.99)
	    *shdw += 1 - tmp->triangle->cons.tra;
	}
      else
	if (k.k > 0.0)
	  *shdw += 1 - tmp->triangle->cons.tra;
    }
}

double		get_shadow_value(t_data *d, t_dir *lum, t_obj *obj, t_lux *lux)
{
  double	shadow;
  t_obj		*tmp;
  t_dir		opos;

  opos = *lum;
  if (lux->form == SPHERE)
    inv_vec(&opos.vec);
  shadow = 0;
  tmp = d->obj;
  if (obj->cons.tra != 1.0)
    while (tmp)
      {
	if (tmp->type != OBJ && tmp != obj && tmp->cons.tra != 1.0)
	  d->do_shdw[tmp->type](&opos, &shadow, tmp, lux);
	else if (tmp != obj && tmp->cons.tra != 1.0)
	  shadow_obj(&shadow, &opos, tmp, lux);
	if (shadow >= 1.0)
	  return (shadow);
	tmp = tmp->next;
      }
  return (shadow);
}
