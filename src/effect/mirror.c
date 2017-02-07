/*
** mirror.c for azer in /home/lemper_a/rendu/igraph/MUL_2014_rtv1
**
** Made by Antoine LEMPEREUR
** Login   <lemper_a@epitech.net>
**
** Started on  Sat Feb 21 20:10:41 2015 Antoine LEMPEREUR
** Last update Fri May 29 17:20:50 2015 Antoine LEMPEREUR
*/

#include	<math.h>
#include	"get_k.h"
#include	"mirror.h"
#include	"my.h"

int		new_col_refl(t_ray_data *d, int new_col, int obj_type)
{
  int		col;
  int		r;
  int		g;
  int		b;
  int		b2;
  int		g2;
  int		r2;
  double	ref;

  if (obj_type == 0)
    ref = d->obj->cons.ref;
  else
    ref = d->tri->cons.ref;
  b = d->color & 0xFF;
  g = d->color >> 8 & 0xFF;
  r = d->color >> 16 & 0xFF;
  b2 = new_col & 0xFF;
  g2 = new_col >> 8 & 0xFF;
  r2 = new_col >> 16 & 0xFF;
  col = (int)(r * (1 - ref) + r2 * ref);
  col <<= 8;
  col += g * (1 - ref) + g2 * ref;
  col <<= 8;
  col += b * (1 - ref) + b2 * ref;
  return (col);
}

int		refl(t_data *d, t_ray_data *ray, t_pos *norm)
{
  t_dir		dir;
  double	scal;

  scal = DOT(*norm, ray->v_dir_n);
  dir.vec.x = ray->v_dir_n.x - 2 * norm->x * scal;
  dir.vec.y = ray->v_dir_n.y - 2 * norm->y * scal;
  dir.vec.z = ray->v_dir_n.z - 2 * norm->z * scal;
  dir.init.x = ray->inter.x + dir.vec.x;
  dir.init.y = ray->inter.y + dir.vec.y;
  dir.init.z = ray->inter.z + dir.vec.z;
  return (get_pix(d, &dir, ray->ref + 1, NULL).color);
}
