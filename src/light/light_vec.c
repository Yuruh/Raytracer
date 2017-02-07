/*
** light_vec.c for rt in /home/descam_d/rendu/IGRAPH/MUL_2014_rtracer
**
** Made by Corentin Descamps
** Login   <descam_d@epitech.net>
**
** Started on  Thu May 28 13:42:31 2015 Corentin Descamps
** Last update Sun Jun  7 15:47:06 2015 Antoine LEMPEREUR
*/

#include	"my.h"
#include	"manage_image.h"

void		calc_light(t_pos *lum, t_pos *pos, t_inter *inter)
{
  lum->x = pos->x - inter->x;
  lum->y = pos->y - inter->y;
  lum->z = pos->z - inter->z;
}

void		get_light_vec(t_lux *lux, t_dir *lum, t_ray_data *ray_data)
{
  if (lux->form == SPHERE)
    {
      calc_light(&lum->vec, &lux->pos, &ray_data->inter);
      lum->init = lux->pos;
    }
  else if (lux->form == PLAN)
    {
      lum->vec = norm_plan_lumin(lux, ray_data->obj);
      lum->init.x = ray_data->inter.x;
      lum->init.y = ray_data->inter.y;
      lum->init.z = ray_data->inter.z;
    }
}

int		get_text_col(t_ray_data *ray)
{
  t_pos		pa;
  t_pos		pb;
  t_pos		pc;
  t_pos		p;

  pa.x = ray->tri->f.text1.x * ray->tri->t_d.side_3;
  pa.y = ray->tri->f.text1.y * ray->tri->t_d.side_3;
  pb.x = ray->tri->f.text2.x * ray->tri->t_d.side_1;
  pb.y = ray->tri->f.text2.y * ray->tri->t_d.side_1;
  pc.x = ray->tri->f.text3.x * ray->tri->t_d.side_2;
  pc.y = ray->tri->f.text3.y * ray->tri->t_d.side_2;
  p.x = ray->tri->f.text1.x * pa.x + ray->tri->f.text2.x * pb.x
    + ray->tri->f.text3.x * pc.y;
  p.y = ray->tri->f.text1.y * pa.y + ray->tri->f.text2.y * pb.y
    + ray->tri->f.text3.y * pc.y;
  return (get_pixel_text_color
	  (ray->obj, (int)(p.x * ray->obj->texture.img->width) - 1,
	   (int)(p.y * ray->obj->texture.img->height) - 1));
}
