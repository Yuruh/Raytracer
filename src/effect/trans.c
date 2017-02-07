/*
** trans.c for rt in /home/lemper_a/rendu/igraph/MUL_2014_rtracer
**
** Made by Antoine LEMPEREUR
** Login   <lemper_a@epitech.net>
**
** Started on  Thu Apr  2 23:40:29 2015 Antoine LEMPEREUR
** Last update Fri May 29 17:20:35 2015 Antoine LEMPEREUR
*/

#include	<math.h>
#include	"my.h"
#include	"fill_info.h"
#include	"object.h"
#include	"light.h"
#include	"get_k.h"
#include	"trans.h"

int		get_trans_color(t_ray_data *ray, t_pos *n, t_data *d)
{
  double	scal;
  t_dir		dir;
  double	nn;
  double	common;

  nn = 1 / 1.5;
  scal = DOT(*n, ray->v_dir_n);
  common = nn * scal - sqrt(1 + (nn * nn) * ((scal * scal) - 1));
  dir.init.x = ray->inter.x;
  dir.init.y = ray->inter.y;
  dir.init.z = ray->inter.z;
  dir.vec.x = nn * ray->v_dir_n.x + common * n->x;
  dir.vec.y = nn * ray->v_dir_n.y + common * n->y;
  dir.vec.z = nn * ray->v_dir_n.z + common * n->z;
  normalise(&dir.vec);
  dir.init.x += dir.vec.x;
  dir.init.y += dir.vec.y;
  dir.init.z += dir.vec.z;
  return (get_pix(d, &dir, ray->ref, ray->obj).color);
}

int		new_col_trans(t_ray_data *d, int new_col, int obj_type)
{
  int		r;
  int		g;
  int		b;
  int		c;
  double	tra;

  if (obj_type == 0)
    tra = d->obj->cons.tra;
  else
    tra = d->obj->cons.tra;
  r = d->color >> 16 & 0xFF;
  g = d->color >> 8 & 0xFF;
  b = d->color & 0xFF;
  c = (new_col >> 16 & 0xFF) * tra + r * (1 - tra);
  c <<= 8;
  c += (new_col >> 8 & 0xFF) * tra + g * (1 - tra);
  c <<= 8;
  c += (new_col & 0xFF) * tra + b * (1 - tra);
  return (c);
}
