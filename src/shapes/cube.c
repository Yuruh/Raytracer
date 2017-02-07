/*
** tore.c for rt in /home/thieba_r/Documents/IGRAPH/MUL_2014_rtracer
**
** Made by Raphael Thiebault
** Login   <thieba_r@epitech.net>
**
** Started on  Sat May  9 00:17:10 2015 Raphael Thiebault
** Last update Sat Jun  6 16:35:26 2015 Raphael Thiebault
*/

#include	<math.h>
#include	<gsl_poly.h>
#include	<gsl_errno.h>
#include	"modif.h"
#include	"object.h"
#include	"get_k.h"
#include	"calc.h"
#include	"my.h"

static void	fill_prepa(t_pos *v3, t_pos *v2, t_pos *from)
{
  v3->x = from->x * from->x * from->x;
  v3->y = from->y * from->y * from->y;
  v3->z = from->z * from->z * from->z;
  v2->x = from->x * from->x;
  v2->y = from->y * from->y;
  v2->z = from->z * from->z;
}

static int			calc_cube(t_pos *e, t_pos *v,
					  t_obj *o, double roots[8])
{
  double			r;
  t_pos				v3;
  t_pos				v2;
  t_pos				e3;
  t_pos				e2;
  double			equ[5];
  gsl_poly_complex_workspace	*w;

  fill_prepa(&v3, &v2, v);
  fill_prepa(&e3, &e2, e);
  r = o->lon.circonference * o->lon.circonference;
  equ[4] = pow(v->x, 4) + pow(v->y, 4) + pow(v->z, 4);
  equ[3] = 4 * (v3.x * e->x + v3.y * e->y + v3.z * e->z);
  equ[2] = 6 * (v2.x * e2.x + v2.y * e2.y + v2.z * e2.z)
    - (9.95 + o->cons.rempli / 10) * r * (v2.x + v2.y + v2.z);
  equ[1] = 4 * (e3.x * v->x + e3.y * v->y + e3.z * v->z) - 20 * r *
    (v->x * e->x + v->y * e->y + v->z * e->z);
  equ[0] = pow(e->x, 4) + pow(e->y, 4) + pow(e->z, 4)
    - 10 * r * (e2.x + e2.y + e2.z) + 40 * r * r;
  if (equ[4] == 0.0000 || !(w = gsl_poly_complex_workspace_alloc(5)))
    return (1);
  if (gsl_poly_complex_solve(equ, 5, w, roots) != GSL_SUCCESS)
    return (1);
  gsl_poly_complex_workspace_free(w);
  return (0);
}

void		inter_cube(t_ray_data *d, t_obj *o, t_k *k)
{
  t_equ		res;
  double	roots[8];

  k->k = -2.0;
  if (calc_cube(&EYE, &VEC, o, roots) == 0)
    {
      res.roots = roots;
      res.nb_roots = 4;
      get_komplex(&res, k, d, o);
    }
  if (k->k >= 0.000000000001)
    d->inter = get_inter(&d->eye_pos_n, *k, &d->v_pos_n);
}

void		norm_cube(t_ray_data *d, t_pos *norm)
{
  norm->x = 4 * pow(d->inter.x, 3) - 20 * d->inter.x
    * d->obj->lon.circonference * d->obj->lon.circonference;
  norm->y = 4 * pow(d->inter.y, 3) - 20 * d->inter.y
    * d->obj->lon.circonference * d->obj->lon.circonference;
  norm->z = 4 * pow(d->inter.z, 3) - 20 * d->inter.z
    * d->obj->lon.circonference * d->obj->lon.circonference;
  if (!d->inter.is_sec)
    {
      norm->x *= -1;
      norm->y *= -1;
      norm->z *= -1;
    }
  go_derotate(&norm->x, &norm->y, &norm->z, &d->obj->rot);
  normalise(norm);
}

void		shdw_cube(t_dir *lum, double *shadow, t_obj *o, t_lux *lux)
{
  t_equ		res;
  t_dir		real;
  t_k		k;
  double	roots[8];

  real = *lum;
  launch_modif(&real.init, &real.vec, o);
  if (calc_cube(&real.init, &real.vec, o, roots) == 0)
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
