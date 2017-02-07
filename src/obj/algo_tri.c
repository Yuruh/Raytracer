/*
** algo_tri.c for azer in /home/lemper_a/rendu/igraph/MUL_2014_rtracer
**
** Made by Antoine LEMPEREUR
** Login   <lemper_a@epitech.net>
**
** Started on  Mon Jun  1 16:54:58 2015 Antoine LEMPEREUR
** Last update Mon Jun  1 17:16:35 2015 Antoine LEMPEREUR
*/

#include	"my.h"
#include	"image.h"
#include	"get_k.h"
#include	"vec_func.h"
#include	"calc.h"

t_k		inter_tri(t_triangle *t, t_pos *i, t_k k)
{
  t_pos		w;
  double	wu;
  double	wv;
  double	s;
  double	a;

  w = get_vec(&t->f.pt1, i);
  wu = DOT(w, t->t_d.u);
  wv = DOT(w, t->t_d.v);
  s = (t->t_d.uv * wv - t->t_d.vv * wu) / t->t_d.d;
  if (s < 0.0 || s > 1.0)
    {
      k.k = -1;
      return (k);
    }
  a = (t->t_d.uv * wu - t->t_d.uu * wv) / t->t_d.d;
  if (a < 0.0 || (s + a) > 1.0)
    {
      k.k = -1;
      return (k);
    }
  t->t_d.side_1 = s;
  t->t_d.side_2 = a;
  t->t_d.side_3 = 1 - t->t_d.side_2 - t->t_d.side_1;
  return (k);
}

t_k		get_k_tri(t_triangle *t, t_pos *vec, t_pos *eye)
{
  double	b;
  t_inter	inter;
  t_pos		i;
  t_pos		w0;
  t_k		k;
  t_pos		vecc;
  double	aa;

  vecc = *vec;
  k.is_sec = 0;
  k.k = -1;
  if (t->t_d.n.x == 0.0 && t->t_d.n.y == 0.0 && t->t_d.n.z == 0.0)
    return (k);
  if ((b = DOT(t->t_d.n, vecc)) < ALMOST_ZERO)
    return (k);
  w0 = get_vec(&t->f.pt1, eye);
  aa = -(DOT(t->t_d.n, w0));
  if ((k.k = aa / b) < ALMOST_ZERO)
    return (k);
  inter = get_inter(eye, k, &vecc);
  i.x = inter.x;
  i.y = inter.y;
  i.z = inter.z;
  return (inter_tri(t, &i, k));
}
