/*
** vec_func.c for azer in /home/lemper_a/rendu/igraph/MUL_2014_rtracer/src
**
** Made by Antoine LEMPEREUR
** Login   <lemper_a@epitech.net>
**
** Started on  Fri May  8 15:55:39 2015 Antoine LEMPEREUR
** Last update Thu May 28 14:28:22 2015 Raphael Thiebault
*/

#include	<math.h>
#include	"my.h"
#include	"vec_func.h"

t_pos		get_vec(t_pos *a, t_pos *b)
{
  t_pos		ret;

  ret.x = b->x - a->x;
  ret.y = b->y - a->y;
  ret.z = b->z - a->z;
  return (ret);
}

t_pos		cross(t_pos *v, t_pos *w)
{
  t_pos		c;

  c.x = w->z * v->y - v->z * w->y;
  c.y = w->x * v->z - v->x * w->z;
  c.z = w->y * v->x - v->y * w->x;
  return (c);
}

void		inv_vec(t_pos *vec)
{
  vec->x *= -1;
  vec->y *= -1;
  vec->z *= -1;
}

void		normalise(t_pos *pos)
{
  double	n;

  n = sqrt(pos->x * pos->x + pos->y * pos->y + pos->z * pos->z);
  pos->x /= n;
  pos->y /= n;
  pos->z /= n;
}
