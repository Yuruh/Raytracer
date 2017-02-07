/*
** tore.c for rt in /home/thieba_r/Documents/IGRAPH/MUL_2014_rtracer
**
** Made by Raphael Thiebault
** Login   <thieba_r@epitech.net>
**
** Started on  Sat May  9 00:17:10 2015 Raphael Thiebault
** Last update Sat Jun  6 16:35:12 2015 Raphael Thiebault
*/

#include	<math.h>
#include	<float.h>
#include	<gsl_poly.h>
#include	<gsl_errno.h>
#include	"shadow.h"
#include	"modif.h"
#include	"object.h"
#include	"get_k.h"
#include	"calc.h"
#include	"my.h"

static int			calc_star(t_pos *e, t_pos *v,
					  double r, double rt[8])
{
  double			equ[5];
  gsl_poly_complex_workspace	*w;

  equ[4] = -2 * pow(v->x, 4) - v->y * v->y * r * v->z * v->z;
  equ[3] = -8 * e->x * v->x * v->x * v->x - 2 * e->y * v->y * v->z * v->z
    * r - 2 * e->z * v->y * v->y * v->z * r;
  equ[2] = -12 * e->x * e->x * v->x * v->x - e->y * e->y * v->z * v->z * r
    - 4 * e->y * e->z * v->y * v->z * r - e->z * e->z * v->y * v->y * r
    + 6 * v->x * v->x;
  equ[1] = -8 * e->x * e->x * e->x * v->x + 12 * e->x * v->x
    - 2 * e->y * e->y * e->z * v->z * r - 2 * e->y * e->z * e->z * v->y * r;
  equ[0] = -2 * pow(e->x, 4) + 6 * e->x * e->x - e->y * e->y * e->z * e->z * r;
  if (equ[4] == 0.0000 || !(w = gsl_poly_complex_workspace_alloc(5)) ||
      gsl_poly_complex_solve(equ, 5, w, rt) != GSL_SUCCESS)
    return (-1);
  gsl_poly_complex_workspace_free(w);
  return (0);
}

void		inter_stellar(t_ray_data *d, t_obj *o, t_k *k)
{
  t_equ		res;
  double	roots[8];

  k->k = -2;
  if (calc_star(&EYE, &VEC, o->lon.size, roots) == 0)
    {
      res.roots = roots;
      res.nb_roots = 4;
      get_komplex(&res, k, d, o);
    }
  if (k->k >= 0.000000001)
    d->inter = get_inter(&d->eye_pos_n, *k, &d->v_pos_n);
}

void		norm_star(t_ray_data *d, t_pos *norm)
{
  norm->x = -12 * d->inter.x + 8 * d->inter.x * d->inter.x * d->inter.x;
  norm->y = 2 * d->inter.y;
  norm->z = 2 * d->inter.z * d->obj->lon.size;
  if (!d->inter.is_sec)
    {
      norm->x *= -1;
      norm->y *= -1;
      norm->z *= -1;
    }
  go_derotate(&norm->x, &norm->y, &norm->z, &d->obj->rot);
  normalise(norm);
}

void		shdw_star(t_dir *lum, double *shadow, t_obj *o, t_lux *lux)
{
  t_equ		res;
  t_dir		real;
  t_k		k;
  double	roots[8];

  real = *lum;
  launch_modif(&real.init, &real.vec, o);
  k.k = -2;
  if (calc_star(&real.init, &real.vec, o->lon.size, roots) == 0)
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
