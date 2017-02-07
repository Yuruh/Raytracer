/*
** ray.c for rt in /home/thieba_r/Documents/IGRAPH/MUL_2014_rtracer
**
** Made by Raphael Thiebault
** Login   <thieba_r@epitech.net>
**
** Started on  Fri May 29 16:40:02 2015 Raphael Thiebault
** Last update Sat Jun  6 14:37:59 2015 Raphael Thiebault
*/

#include	"go.h"
#include	"calc.h"
#include	"image.h"
#include	"my.h"
#include	"triangle.h"
#include	"get_k.h"
#include	"my_lib.h"
#include	"blur.h"
#include	"parsing_rt.h"
#include	"error_obj.h"

static t_dir	save_k(t_ray_data *ray, t_k actual_k,
		       t_triangle *s, t_obj *tmp)
{
  t_dir		save;

  save.init = ray->eye_pos_n;
  save.vec = ray->v_pos_n;
  ray->k = actual_k;
  ray->obj = tmp;
  ray->tri = s;
  return (save);
}

static t_dir	process_k(t_obj *tmp, t_ray_data *ray, t_data *d, t_dir *dir)
{
  t_k		actual_k;
  t_dir		save;
  t_triangle	*s;

  save.init = ray->eye_pos_n;
  save.vec = ray->v_pos_n;
  s = NULL;
  while ((tmp = tmp->next))
    {
      if (tmp->type == OBJ &&
	  ((actual_k.k = inter_box(&tmp->lim, &dir->vec, &dir->init))
	   < ray->k.k || ray->k.k < 0) && actual_k.k > 0.0)
	actual_k = pick_k_tri(tmp->triangle, dir, &s);
      else if (tmp->type != OBJ && tmp != ray->old_obj)
	actual_k = get_k(tmp, dir, d, ray);
      else
	actual_k.k = -1;
      if ((actual_k.k < ray->k.k || ray->k.k < 0) && actual_k.k > 0)
	save = save_k(ray, actual_k, s, tmp);
    }
  return (save);
}

t_ray_data	get_pix(t_data *d, t_dir *dir, int ref, t_obj *old_obj)
{
  t_ray_data	ray_data;
  t_dir		save;
  t_obj		*tmp;

  tmp = d->obj;
  ray_data.obj = tmp;
  ray_data.old_obj = old_obj;
  ray_data.tri = NULL;
  ray_data.ref = ref;
  if (tmp)
    {
      if (tmp->type != OBJ)
	ray_data.k = get_k(tmp, dir, d, &ray_data);
      else
	ray_data.k = pick_k_tri(tmp->triangle, dir, &ray_data.tri);
      save = process_k(tmp, &ray_data, d, dir);
      ray_data.eye_pos_n = save.init;
      ray_data.v_pos_n = save.vec;
      if (ray_data.k.k > 0.0)
	return (*(final_color(d, &ray_data, &dir->vec, &dir->init)));
    }
  ray_data.color = 0;
  return (ray_data);
}
