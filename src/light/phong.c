/*
** phong.c for rt in /home/descam_d/rendu/IGRAPH/MUL_2014_rtracer
**
** Made by Corentin Descamps
** Login   <descam_d@epitech.net>
**
** Started on  Fri May  8 20:22:55 2015 Corentin Descamps
** Last update Mon Jun  1 17:12:22 2015 Corentin Descamps
*/

#include	<math.h>
#include	"my.h"
#include	"light.h"
#include	"get_k.h"
#include	"phong.h"

unsigned int	apply_phong(unsigned int color, unsigned int phong,
			    t_lux_data *l_data)
{
  if (l_data->shdw >= 1)
    return (0);
  if (color + phong < 255)
    return (color + phong);
  else
    return (255);
}

void		rgb_phong(unsigned int *phong, t_lux_data *l_data, t_cons *cons)
{
  phong[0] = (((l_data->col & 0xFF0000) >> 16) * l_data->spec) * cons->spec;
  phong[1] = (((l_data->col & 0x00FF00) >> 8) * l_data->spec) * cons->spec;
  phong[2] = ((l_data->col & 0x0000FF) * l_data->spec) * cons->spec;
}

double		specular_ref(t_pos *norm, t_ray_data *ray_data, t_dir *lum)
{
  double	spec;
  t_pos		r;

  r.x = lum->vec.x - 2 * DOT(*norm, lum->vec) * norm->x;
  r.y = lum->vec.y - 2 * DOT(*norm, lum->vec) * norm->y;
  r.z = lum->vec.z - 2 * DOT(*norm, lum->vec) * norm->z;
  normalise(&r);
  if ((spec = DOT(r, ray_data->v_dir_n)) < 0)
    spec = 0.0;
  spec = pow(spec, 400);
  return (spec);
}
