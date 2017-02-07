/*
** dingdong.c for dingdong in /home/thieba_r/Documents/IGRAPH/MUL_2014_rtracer
**
** Made by Raphael Thiebault
** Login   <thieba_r@epitech.net>
**
** Started on  Wed May 20 16:28:10 2015 Raphael Thiebault
** Last update Sat Jun  6 17:56:44 2015 Raphael Thiebault
*/

#include	<math.h>
#include	<gsl_poly.h>
#include	<gsl_errno.h>
#include	"shadow.h"
#include	"modif.h"
#include	"object.h"
#include	"get_k.h"
#include	"calc.h"
#include	"my.h"

static double			calc_dingdong(double roots[6],
					      t_pos *e, t_pos *v, double r)
{
  double			equ[4];
  gsl_poly_complex_workspace	*w;

  if (r == 0.000 || v->z == 0.000)
    return (-1);
  equ[3] = r * v->z * v->z * v->z;
  equ[2] = v->x * v->x + v->y * v->y - v->z * v->z +
    r * 3 * e->z * v->z * v->z;
  equ[1] = 2 * (v->x * e->x + v->y * e->y - v->z * e->z)
    + r * 3 * e->z * e->z * v->z;
  equ[0] = e->x * e->x + e->y * e->y + r * e->z * e->z * e->z - e->z * e->z;
  if (!(w = gsl_poly_complex_workspace_alloc(4)))
    return (-2);
  if (gsl_poly_complex_solve(equ, 4, w, roots) != GSL_SUCCESS)
    return (-2);
  gsl_poly_complex_workspace_free(w);
  return (0);
}

void		inter_dingdong(t_ray_data *d, t_obj *o, t_k *k)
{
  t_equ		res;
  double	roots[6];

  k->k = -2;
  if (calc_dingdong(roots, &EYE, &VEC, o->lon.size) == 0)
    {
      res.roots = roots;
      res.nb_roots = 3;
      get_komplex(&res, k, d, o);
    }
  if (k->k >= 0.000000000001)
    d->inter = get_inter(&d->eye_pos_n, *k, &d->v_pos_n);
}

void		norm_dingdong(t_ray_data *d, t_pos *norm)
{
  norm->x = d->inter.x;
  norm->y = d->inter.y;
  norm->z = d->obj->lon.size * 3 * d->inter.z * d->inter.z - d->inter.z;
  if (!d->inter.is_sec)
    {
      norm->x *= -1;
      norm->y *= -1;
      norm->z *= -1;
    }
  go_derotate(&norm->x, &norm->y, &norm->z, &d->obj->rot);
  normalise(norm);
}

void		shdw_dingdong(t_dir *lum, double *shadow, t_obj *o, t_lux *lux)
{
  t_equ		res;
  t_dir		real;
  t_k		k;
  double	roots[6];

  k.k = -2.0;
  real = *lum;
  launch_modif(&real.init, &real.vec, o);
  if (calc_dingdong(roots, &real.init, &real.vec, o->lon.size) == 0)
    {
      res.roots = roots;
      res.nb_roots = 2;
      get_lum_komplex(&res, &k, &real, o);
    }
  if (lux->form == SPHERE && k.k > 0.0 && k.k < 0.99)
    *shadow = 1 - o->cons.tra;
  else if (lux->form == PLAN && k.k > 0.0)
    *shadow = 1 - o->cons.tra;
}
