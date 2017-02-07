/*
** tore.c for rt in /home/thieba_r/Documents/IGRAPH/MUL_2014_rtracer
**
** Made by Raphael Thiebault
** Login   <thieba_r@epitech.net>
**
** Started on  Sat May  9 00:17:10 2015 Raphael Thiebault
** Last update Sat Jun  6 16:36:07 2015 Raphael Thiebault
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

static int			calc_tore(t_pos *eye, t_pos *vec,
					  t_obj *o, double roots[8])
{
  double			d;
  double			all;
  double			ray_sum;
  double			equ[5];
  double			circ;
  double			ray;
  gsl_poly_complex_workspace	*w;

  circ = o->lon.circonference * o->lon.circonference;
  ray = o->lon.ray * o->lon.ray;
  d = DOT(*vec, *vec);
  all = DOT(*vec, *eye);
  ray_sum = DOT(*eye, *eye) - ray - circ;
  if ((equ[4] = d * d) == 0.0000)
    return (1);
  equ[3] = 4 * d * all;
  equ[2] = 4 * all * all + 2 * d * ray_sum + 4 * circ * vec->z * vec->z;
  equ[1] = 4 * all * ray_sum + 8 * circ * vec->z * eye->z;
  equ[0] = ray_sum * ray_sum + 4 * circ * eye->z * eye->z - 4 * circ * ray;
  if (!(w = gsl_poly_complex_workspace_alloc(5)))
    return (1);
  if (gsl_poly_complex_solve(equ, 5, w, roots) != GSL_SUCCESS)
    return (1);
  gsl_poly_complex_workspace_free(w);
  return (0);
}

void		inter_tore(t_ray_data *d, t_obj *o, t_k *k)
{
  t_equ		res;
  double	roots[8];

  k->k = -2;
  if (calc_tore(&EYE, &VEC, o, roots) == 0)
    {
      res.roots = roots;
      res.nb_roots = 4;
      get_komplex(&res, k, d, o);
    }
  if (k->k >= 0.000000000001)
    d->inter = get_inter(&d->eye_pos_n, *k, &d->v_pos_n);
}

void		norm_tore(t_ray_data *d, t_pos *norm)
{
  double	ray_sum;
  double	circ;
  double	ray;

  circ = d->obj->lon.circonference * d->obj->lon.circonference;
  ray = d->obj->lon.ray * d->obj->lon.ray;
  ray_sum = d->inter.x * d->inter.x + d->inter.y * d->inter.y
    + d->inter.z * d->inter.z - circ - ray;
  norm->x = 4 * d->inter.x * ray_sum;
  norm->y = 4 * d->inter.y * ray_sum;
  norm->z = 4 * d->inter.z * ray_sum + 8 * circ * d->inter.z;
  if (!d->inter.is_sec)
    {
      norm->x *= -1;
      norm->y *= -1;
      norm->z *= -1;
    }
  go_derotate(&norm->x, &norm->y, &norm->z, &d->obj->rot);
  normalise(norm);
}

void		shdw_tore(t_dir *lum, double *shadow, t_obj *o, t_lux *lux)
{
  t_equ		res;
  t_dir		real;
  t_k		k;
  double	roots[8];

  real = *lum;
  launch_modif(&real.init, &real.vec, o);
  if (calc_tore(&real.init, &real.vec, o, roots) == 0)
    {
      res.roots = roots;
      res.nb_roots = 4;
      get_lum_komplex(&res, &k, &real, o);
    }
  if (lux->form == SPHERE && k.k > 0.0 && k.k < 0.99)
    *shadow = 1 - o->cons.tra;
  else if (lux->form == PLAN && k.k > 0.0)
    *shadow = 1 - o->cons.tra;
}
