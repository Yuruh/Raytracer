/*
** light.c for tamer in /home/lemper_a/rendu/igraph/MUL_2014_rtv1
**
** Made by Antoine LEMPEREUR
** Login   <lemper_a@epitech.net>
**
** Started on  Wed Feb  4 15:12:35 2015 Antoine LEMPEREUR
** Last update Sun Jun  7 17:01:26 2015 Antoine LEMPEREUR
*/

#include	<math.h>
#include	"my.h"
#include	"trans.h"
#include	"phong.h"
#include	"calc.h"
#include	"color.h"
#include	"modif.h"
#include	"manage_image.h"
#include	"mirror.h"
#include	"fill_info.h"
#include	"light.h"
#include	"shadow.h"
#include	"get_k.h"
#include	"sphere_text.h"
#include	"light_vec.h"

void		launch_modify_col(t_ray_data *ray_data, t_data *d,
				  t_lux_data *l_data, unsigned int *color)
{
  if (ray_data->obj->type == PLAN && ray_data->obj->damier_col != -1
      && damier(&ray_data->inter, ray_data))
    *color += modify_col(ray_data->obj->damier_col, l_data
			, d->nb_light, &ray_data->obj->cons);
  else if (ray_data->obj->type == SPHERE && ray_data->obj->xpm.xpm_path)
    *color += modify_col(sphere_text(ray_data->obj, ray_data->inter), l_data,
			d->nb_light, &ray_data->obj->cons);
  else if (ray_data->obj->type == PLAN && ray_data->obj->xpm.xpm_path)
    *color += modify_col(l_data->col_obj, l_data,
			d->nb_light, &ray_data->obj->cons);
  else if (ray_data->obj->type != OBJ)
    *color += modify_col(ray_data->obj->src_col, l_data
			, d->nb_light, &ray_data->obj->cons);
  else
    {
      if (ray_data->obj->texture.is_texture && ray_data->obj->texture.text_path)
	ray_data->tri->src_col = get_text_col(ray_data);
      *color += modify_col(ray_data->tri->src_col, l_data
			  , d->nb_light, &ray_data->tri->cons);
    }
}

void		set_light(t_lux_data *l_data, double cos,
			     double spec, double shdw)
{
  l_data->cos = cos;
  l_data->spec = spec;
  l_data->shdw = shdw;
}

unsigned int	lumos(t_data *d, t_pos *norm, t_ray_data *ray_data,
		      t_lux_data *l_data)
{
  t_dir		lum;
  t_dir		lum_deux;
  t_lux		*lux;
  unsigned int	color;

  lux = d->lux;
  color = 0;
  while (lux)
    {
      get_light_vec(lux, &lum, ray_data);
      l_data->col = lux->color;
      lum_deux = lum;
      normalise(&lum.vec);
      if (lux->form == SPHERE || is_inter_plan(lux, &lum))
	set_light(l_data, DOT(*norm, lum.vec),
		  specular_ref(norm, ray_data, &lum),
		  get_shadow_value(d, &lum_deux, ray_data->obj, lux));
      else
	set_light(l_data, 0, 0, 1);
      if (l_data->cos < 0.0 || l_data->shdw >= 1)
      	l_data->cos = 0.0;
      launch_modify_col(ray_data, d, l_data, &color);
      lux = lux->next;
    }
  return (color);
}

t_ray_data	*final_color_obj(t_data *d, t_ray_data *ray,
				 t_pos *v, t_pos *eye)
{
  t_pos		norm;
  t_lux_data	l_data;

  if (ray->obj->texture.is_normale)
    norm = get_actual_tri_norm(ray->tri, &ray->v_dir_n);
  else
    norm = ray->tri->t_d.norm;
  ray->inter = get_inter(eye, ray->k, v);
  if (ray->tri->cons.ref > 0 && ray->ref < 8)
    l_data.ref_col = refl(d, ray, &norm);
  else
    l_data.ref_col = 0;
  if (ray->tri->cons.tra > 0)
    l_data.tra_col = get_trans_color(ray, &norm, d);
  else
    l_data.tra_col = 0;
  ray->color = (int)lumos(d, &norm, ray, &l_data);
  return (ray);
}

t_ray_data	*final_color(t_data *d, t_ray_data *ray, t_pos *v, t_pos *eye)
{
  t_pos		norm;
  t_lux_data	l_data;

  ray->v_dir_n = *v;
  normalise(&ray->v_dir_n);
  ray->inter = get_inter(&ray->eye_pos_n, ray->k, &ray->v_pos_n);
  if (ray->obj->type == PLAN && ray->obj->xpm.xpm_path != NULL)
    l_data.col_obj = plan_text(ray->obj, &ray->inter);
  if (ray->obj->type != OBJ)
    {
      d->do_norm[ray->obj->type](ray, &norm);
      ray->inter = get_inter(eye, ray->k, v);
      if (ray->obj->cons.ref > 0 && ray->ref < 8)
	l_data.ref_col = refl(d, ray, &norm);
      else
	l_data.ref_col = 0;
      if (ray->obj->cons.tra > 0)
	l_data.tra_col = get_trans_color(ray, &norm, d);
      else
	l_data.tra_col = 0;
      ray->color = (int)lumos(d, &norm, ray, &l_data);
      return (ray);
    }
  return (final_color_obj(d, ray, v, eye));
}
