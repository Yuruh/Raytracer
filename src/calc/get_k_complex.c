/*
** sort_k.c for rt in /home/thieba_r/Documents/IGRAPH/MUL_2014_rtracer
**
** Made by Raphael Thiebault
** Login   <thieba_r@epitech.net>
**
** Started on  Tue Jun  2 13:10:49 2015 Raphael Thiebault
** Last update Sat Jun  6 14:37:42 2015 Raphael Thiebault
*/

#include	"calc.h"
#include	"my.h"

static double	lim_komplex(t_k *k, t_obj *o, t_pos *eye_pos, t_pos *vec_pos)
{
  t_inter	inter;

  if (k->is_sec == 0)
    k->is_sec = 1;
  else
    k->is_sec = 0;
  inter = get_inter(eye_pos, *k, vec_pos);
  if (inter.x < o->lim.bot.x || inter.x > o->lim.top.x
      || inter.y < o->lim.bot.y || inter.y > o->lim.top.y
      || inter.z < o->lim.bot.z || inter.z > o->lim.top.z)
    k->k = -1;
  return (k->k);
}

void		get_komplex(t_equ *res, t_k *k, t_ray_data *d, t_obj *o)
{
  double	save;
  int		i;

  k->k = 0.0;
  k->is_sec = 0;
  while (k->k >= 0.0)
    {
      i = -1;
      save = -1;
      while (++i < res->nb_roots)
	if (res->roots[2 * i] > 0.00 && res->roots[2 * i + 1] == 0.00
	    && (res->roots[2 * i] < save || save < 0.0)
	    && k->k < res->roots[2 * i])
	  save = res->roots[2 * i];
      k->k = save;
      if (lim_komplex(k, o, &d->eye_pos_n, &d->v_pos_n) > 0)
	return ;
    }
  if (k->k == 0.0)
    k->k = -1;
}

void		get_lum_komplex(t_equ *res, t_k *k, t_dir *d, t_obj *o)
{
  double	save;
  int		i;

  k->k = 0.0;
  k->is_sec = 0;
  while (k->k >= 0.0)
    {
      i = -1;
      save = -1;
      while (++i < res->nb_roots)
	if (res->roots[2 * i] > 0.0 && res->roots[2 * i + 1] == 0.00
	    && (res->roots[2 * i] < save || save < 0.0)
	    && k->k < res->roots[2 * i])
	  save = res->roots[2 * i];
      k->k = save;
      if (lim_komplex(k, o, &d->init, &d->vec) > 0)
	return ;
    }
  if (k->k == 0.0)
    k->k = -1;
}
