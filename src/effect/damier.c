/*
** fill_info.c for rtv in /home/lemper_a/rendu/igraph/MUL_2014_rtv1
**
** Made by Antoine LEMPEREUR
** Login   <lemper_a@epitech.net>
**
** Started on  Wed Feb  4 17:32:33 2015 Antoine LEMPEREUR
** Last update Thu Jun  4 13:43:10 2015 Antoine LEMPEREUR
*/

#include	<math.h>
#include	"object.h"
#include       	"my.h"
#include	"fill_info.h"
#include	"calc.h"
#include	"cone.h"
#include	"cyl.h"
#include	"sphere.h"
#include	"modif.h"
#include	"delta.h"
#include	"color.h"
#include	"get_k.h"
#include	"my_lib.h"

int		damier(t_inter *inter, t_ray_data *ray)
{
  int		pos_y;
  int		pos_x;

  if (ray->obj->lim.bot.x == 0.0)
    ray->obj->lim.bot.x = ALMOST_ZERO;
  pos_y = (int)(((-inter->y)) / (ray->obj->lim.bot.x / 8));
  if (inter->y < 0.0)
    pos_y--;
  if (ray->obj->lim.top.y == 0.0)
    ray->obj->lim.top.y = ALMOST_ZERO;
  pos_x = (int)((inter->x) / (ray->obj->lim.top.y / 8));
  if (inter->x < 0.0)
    pos_x--;
  if (ray->obj->lim.top.y == 0.0 || ray->obj->lim.bot.x == 0.0)
    return (1);
  if (pos_y % 2 == 0)
    if (pos_x % 2 == 0)
      return (1);
    else
      return (0);
  else
    if (pos_x % 2 == 0)
      return (0);
    else
      return (1);
}

t_obj		*malloc_obj()
{
  t_obj		*obj;

  if (!(obj = malloc(sizeof(t_obj))))
    my_exit("Could not alloc\n");
  return (obj);
}
