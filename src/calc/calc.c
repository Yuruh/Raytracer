/*
** calc.c for rt in /home/lemper_a/rendu/igraph/MUL_2014_rtv1
**
** Made by Antoine LEMPEREUR
** Login   <lemper_a@epitech.net>
**
** Started on  Fri Feb 13 16:11:09 2015 Antoine LEMPEREUR
** Last update Mon Jun  1 16:53:09 2015 Antoine LEMPEREUR
*/

#include	"calc.h"
#include	"my.h"
#include	"modif.h"

t_inter		get_inter_bis(t_ray_data *ray_data)
{
  t_inter	inter;

  inter.x = ray_data->eye_pos_n.x + ray_data->k.k * ray_data->v_pos_n.x;
  inter.y = ray_data->eye_pos_n.y + ray_data->k.k * ray_data->v_pos_n.y;
  inter.z = ray_data->eye_pos_n.z + ray_data->k.k * ray_data->v_pos_n.z;
  inter.is_sec = ray_data->k.is_sec;
  return (inter);
}

t_inter		get_inter(t_pos *pos, t_k k, t_pos *vec)
{
  t_inter	inter;

  inter.x = pos->x + k.k * vec->x;
  inter.y = pos->y + k.k * vec->y;
  inter.z = pos->z + k.k * vec->z;
  inter.is_sec = k.is_sec;
  return (inter);
}

void		go_rotate(double *x, double *y, double *z, t_pos *rot)
{
  rotate_x(y, z, -rot->x);
  rotate_y(x, z, -rot->y);
  rotate_z(x, y, -rot->z);
}

void		go_derotate(double *x, double *y, double *z, t_pos *rot)
{
  rotate_z(x, y, rot->z);
  rotate_y(x, z, rot->y);
  rotate_x(y, z, rot->x);
}

void		launch_modif_plan_lum(t_pos *eye, t_pos *vec, t_pos *pos,
				      t_pos *rot)
{
  mod_pos(eye, pos, '-');
  if (rot->x != 0.0 || rot->y != 0.0 || rot->z != 0.0)
    {
      go_rotate(&eye->x, &eye->y, &eye->z, rot);
      go_rotate(&vec->x, &vec->y, &vec->z, rot);
    }
}
