/*
** mobius.c for rt in /home/thieba_r/Documents/IGRAPH/MUL_2014_rtracer
**
** Made by Raphael Thiebault
** Login   <thieba_r@epitech.net>
**
** Started on  Sat May  9 00:17:10 2015 Raphael Thiebault
** Last update Sat Jun  6 16:35:00 2015 Raphael Thiebault
*/

#include	<math.h>
#include	<float.h>
#include	<gsl_poly.h>
#include	<gsl_errno.h>
#include	"modif.h"
#include	"object.h"
#include	"get_k.h"
#include	"calc.h"
#include	"my.h"

static void			set_equ_mobius(double equ[4], t_obj *o,
					       t_pos *e, t_pos *v)
{
  equ[0] = e->x * e->x * e->y * o->dis.x - 2 * e->x * e->x * e->z
    - 2 * e->x * e->z * o->lon.ray + e->y * e->y * e->y * o->dis.y
    - 2 * e->y * e->y * e->z + e->y * e->z * e->z * o->dis.z
    - e->y * o->lon.ray * o->lon.ray;
  equ[1] = e->x * e->x * v->y * o->dis.x - 2 * e->x * e->x * v->z
    + 2 * e->x * e->y * v->x * o->dis.x - 4 * e->x * e->z * v->x
    - 2 * e->x * o->lon.ray * v->z + 3 * e->y * e->y * v->y * o->dis.y
    - 2 * e->y * e->y * v->z - 4 * e->y * e->z * v->y
    + 2 * e->y * e->z * v->z * o->dis.z
    + e->z * e->z * v->y * o->dis.z - 2 * e->z * o->lon.ray * v->x
    - o->lon.ray * o->lon.ray * v->y;
  equ[2] = 2 * e->x * v->x * v->y * o->dis.x - 4 * e->x * v->x * v->z
    + e->y * v->x * v->x * o->dis.x + 3 * e->y * v->y * v->y * o->dis.y
    - 4 * e->y * v->y * v->z + e->y * v->z * v->z * o->dis.z
    - 2 * e->z * v->x * v->x - 2 * e->z * v->y * v->y
    + 2 * e->z * v->y * v->z * o->dis.z - 2 * o->lon.ray * v->x * v->z;
  equ[3] = v->x * v->x * v->y * o->dis.x - 2 * v->x * v->x * v->z
    + v->y * v->y * v->y * o->dis.y - 2 * v->y * v->y * v->z
    + v->y * v->z * v->z * o->dis.z;
}

static int			calc_mobius(t_pos *eye, t_pos *vec,
					    t_obj *o, double roots[6])
{
  double			equ[4];
  gsl_poly_complex_workspace	*w;

  set_equ_mobius(equ, o, eye, vec);
  if (equ[3] == 0.0000)
    return (-1);
  if (!(w = gsl_poly_complex_workspace_alloc(4)))
    return (-1);
  if (gsl_poly_complex_solve(equ, 4, w, roots) != GSL_SUCCESS)
    return (-1);
  gsl_poly_complex_workspace_free(w);
  return (0);
}

void		inter_mobius(t_ray_data *d, t_obj *o, t_k *k)
{
  double	roots[6];
  t_equ		res;

  k->k = -2.0;
  if ((calc_mobius(&EYE, &VEC, o, roots)) == 0)
    {
      res.roots = roots;
      res.nb_roots = 3;
      get_komplex(&res, k, d, o);
    }
  if (k->k >= 0.000000000001)
    d->inter = get_inter(&d->eye_pos_n, *k, &d->v_pos_n);
}

void		norm_mobius(t_ray_data *d, t_pos *norm)
{
  double	cos;

  norm->x = -2 * d->obj->lon.ray * d->inter.z + 2 * d->inter.x * d->inter.y
    - 4 * d->inter.x * d->inter.z;
  norm->y = -d->obj->lon.ray * d->obj->lon.ray + d->inter.x * d->inter.x
    + d->inter.y * (3 * d->inter.y - 4 * d->inter.z) + d->inter.z * d->inter.z;
  norm->z = (d->obj->lon.ray * d->obj->lon.ray - 4 * d->inter.y * d->inter.z
	     + 4 * d->inter.y * d->inter.z) * 0.5 - 0.5 *
    (d->obj->lon.ray + 2 * d->inter.x) * (d->obj->lon.ray + 2 * d->inter.x);
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

void		shdw_mobius(t_dir *lum, double *shadow, t_obj *o, t_lux *lux)
{
  t_equ		res;
  t_dir		real;
  t_k		k;
  double	roots[6];

  real = *lum;
  launch_modif(&real.init, &real.vec, o);
  if (calc_mobius(&real.init, &real.vec, o, roots) == 0)
    {
      res.roots = roots;
      res.nb_roots = 3;
      get_lum_komplex(&res, &k, &real, o);
    }
  if (lux->form == SPHERE && k.k > 0.0 && k.k < 0.99)
    *shadow = 1 - o->cons.tra;
  else if (lux->form == PLAN && k.k > 0.0)
    *shadow = 1 - o->cons.tra;
}
