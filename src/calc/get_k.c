/*
** get_k.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Mon Mar 30 16:35:04 2015 Antoine Zanardi
** Last update Mon Jun  1 17:16:03 2015 Antoine LEMPEREUR
*/

#include	<math.h>
#include	"get_k.h"
#include	"object.h"
#include	"triangle.h"
#include	"my.h"
#include	"go.h"
#include	"modif.h"
#include	"windata.h"
#include	"fill_info.h"
#include	"color.h"
#include	"calc.h"
#include	"sphere.h"
#include	"cyl.h"
#include	"cone.h"
#include	"my_lib.h"
#include	"init.h"
#include	"parsing_rt.h"
#include	"go_parsing.h"
#include	"my_lists.h"
#include	"bmp/bmp_exporter.h"
#include	"threads/my_threads.h"
#include	"delta.h"

int		check_lim(double max, t_obj *o, t_ray_data *ray, t_k *k)
{
  k->k = max;
  k->is_sec = 1;
  ray->inter = get_inter(&ray->eye_pos_n, *k, &ray->v_pos_n);
  if (ray->inter.x < o->lim.bot.x || ray->inter.x > o->lim.top.x
      || ray->inter.y < o->lim.bot.y || ray->inter.y > o->lim.top.y
      || ray->inter.z < o->lim.bot.z || ray->inter.z > o->lim.top.z)
    {
      k->k = -1;
      return (1);
    }
  return (0);
}

t_k		pick_k_tri(t_triangle *t, t_dir *dir, t_triangle **s)
{
  t_k		k;
  t_k		actual_k;
  t_triangle	*tmp;

  tmp = t;
  *s = tmp;
  k = get_k_tri(tmp, &dir->vec, &dir->init);
  while (tmp)
    {
      actual_k = get_k_tri(tmp, &dir->vec, &dir->init);
      if ((actual_k.k < k.k || k.k < 0) && actual_k.k > 0)
	{
	  *s = tmp;
	  k = actual_k;
	}
      tmp = tmp->next;
    }
  return (k);
}

t_k		get_k(t_obj *o, t_dir *vec, t_data *d, t_ray_data *ray_data)
{
  t_k		k;

  k.is_sec = 0;
  ray_data->eye_pos_n = vec->init;
  ray_data->v_pos_n = vec->vec;
  launch_modif(&ray_data->eye_pos_n, &ray_data->v_pos_n, o);
  d->do_inter[o->type](ray_data, o, &k);
  return (k);
}
