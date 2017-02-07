/*
** inter_box.c for azer in /home/lemper_a/rendu/igraph/MUL_2014_rtracer/src
**
** Made by Antoine LEMPEREUR
** Login   <lemper_a@epitech.net>
**
** Started on  Wed Apr 29 16:13:44 2015 Antoine LEMPEREUR
** Last update Thu May 28 15:26:19 2015 Antoine Zanardi
*/

#include	<math.h>
#include	"my.h"
#include	"object.h"

double		inter_box(t_lim *lim, t_pos *v, t_pos *eye)
{
  t_pos		inv_v;
  t_pos		t1;
  t_pos		t2;
  double	tmax;
  double	tmin;

  inv_v.x = 1.0f / v->x;
  inv_v.y = 1.0f / v->y;
  inv_v.z = 1.0f / v->z;
  t1.x = (lim->bot.x - eye->x) * inv_v.x;
  t1.y = (lim->top.x - eye->x) * inv_v.x;
  t1.z = (lim->bot.y - eye->y) * inv_v.y;
  t2.x = (lim->top.y - eye->y) * inv_v.y;
  t2.y = (lim->bot.z - eye->z) * inv_v.z;
  t2.z = (lim->top.z - eye->z) * inv_v.z;
  tmin = fmax(fmax(fmin(t1.x, t1.y), fmin(t1.z, t2.x)), fmin(t2.y, t2.z));
  tmax = fmin(fmin(fmax(t1.x, t1.y), fmax(t1.z, t2.x)), fmax(t2.y, t2.z));
  if (tmax < 0.0)
    return (-1);
  if (tmin > tmax)
    return (-1);
  return (tmin);
}
