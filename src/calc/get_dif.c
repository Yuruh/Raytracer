/*
** get_dif.c for azer in /home/lemper_a/rendu/igraph/MUL_2014_rtracer
**
** Made by Antoine LEMPEREUR
** Login   <lemper_a@epitech.net>
**
** Started on  Fri May  8 16:02:12 2015 Antoine LEMPEREUR
** Last update Tue Jun  2 14:26:49 2015 Raphael Thiebault
*/

#include	"my.h"

void		get_biggest_dif_x(t_face_data *tri, double *x_min, double *x_max)
{
  unsigned int	i;
  double	sv_min;
  double	sv_max;

  i = 0;
  sv_min = tri->face[i].pt1.x;
  sv_max = tri->face[i].pt1.x;
  while (++i < tri->lim)
    {
      if (tri->face[i].pt1.x < sv_min)
        sv_min = tri->face[i].pt1.x;
      if (tri->face[i].pt2.x < sv_min)
        sv_min = tri->face[i].pt2.x;
      if (tri->face[i].pt3.x < sv_min)
        sv_min = tri->face[i].pt3.x;
      if (tri->face[i].pt1.x > sv_max)
        sv_max = tri->face[i].pt1.x;
      if (tri->face[i].pt2.x > sv_max)
        sv_max = tri->face[i].pt2.x;
      if (tri->face[i].pt3.x > sv_max)
        sv_max = tri->face[i].pt3.x;
    }
  *x_min = sv_min;
  *x_max = sv_max;
}

void		get_biggest_dif_y(t_face_data *tri, double *y_min, double *y_max)
{
  unsigned int	i;
  double	sv_min;
  double	sv_max;

  i = 0;
  sv_min = tri->face[i].pt1.y;
  sv_max = tri->face[i].pt1.y;
  while (++i < tri->lim)
    {
      if (tri->face[i].pt1.y < sv_min)
        sv_min = tri->face[i].pt1.y;
      if (tri->face[i].pt2.y < sv_min)
        sv_min = tri->face[i].pt2.y;
      if (tri->face[i].pt3.y < sv_min)
        sv_min = tri->face[i].pt3.y;
      if (tri->face[i].pt1.y > sv_max)
        sv_max = tri->face[i].pt1.y;
      if (tri->face[i].pt2.y > sv_max)
        sv_max = tri->face[i].pt2.y;
      if (tri->face[i].pt3.y > sv_max)
        sv_max = tri->face[i].pt3.y;
    }
  *y_min = sv_min;
  *y_max = sv_max;
}

void		get_biggest_dif_z(t_face_data *tri, double *z_min, double *z_max)
{
  unsigned int	i;
  double	sv_min;
  double	sv_max;

  i = 0;
  sv_min = tri->face[i].pt1.z;
  sv_max = tri->face[i].pt1.z;
  while (++i < tri->lim)
    {
      if (tri->face[i].pt1.z < sv_min)
        sv_min = tri->face[i].pt1.z;
      if (tri->face[i].pt2.z < sv_min)
        sv_min = tri->face[i].pt2.z;
      if (tri->face[i].pt3.z < sv_min)
        sv_min = tri->face[i].pt3.z;
      if (tri->face[i].pt1.z > sv_max)
        sv_max = tri->face[i].pt1.z;
      if (tri->face[i].pt2.z > sv_max)
        sv_max = tri->face[i].pt2.z;
      if (tri->face[i].pt3.z > sv_max)
        sv_max = tri->face[i].pt3.z;
    }
  *z_min = sv_min;
  *z_max = sv_max;
}

void		get_lim_box(t_face_data *tri, t_lim *lim)
{
  get_biggest_dif_x(tri, &lim->bot.x, &lim->top.x);
  get_biggest_dif_y(tri, &lim->bot.y, &lim->top.y);
  get_biggest_dif_z(tri, &lim->bot.z, &lim->top.z);
}
