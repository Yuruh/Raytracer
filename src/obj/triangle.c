/*
** triangle.c for rt in /home/lemper_a/rendu/igraph/MUL_2014_rtracer/src
**
** Made by Antoine LEMPEREUR
** Login   <lemper_a@epitech.net>
**
** Started on  Mon Mar 23 16:03:18 2015 Antoine LEMPEREUR
** Last update Mon Jun  1 17:18:28 2015 Corentin Descamps
*/

#include	<stdlib.h>
#include	<math.h>
#include	"my.h"
#include	"object.h"
#include	"color.h"
#include	"calc.h"
#include	"modif.h"
#include	"my_lib.h"
#include	"triangle.h"
#include	"get_k.h"
#include	"vec_func.h"

t_pos		get_actual_tri_norm(t_triangle *tri, t_pos *v)
{
  t_pos		ret;

  if (DOT(tri->f.norm1, *v) < 0)
    inv_vec(&tri->f.norm1);
  if (DOT(tri->f.norm2, *v) < 0)
    inv_vec(&tri->f.norm2);
  if (DOT(tri->f.norm3, *v) < 0)
    inv_vec(&tri->f.norm3);
  ret.x = -1 * (tri->f.norm1.x * tri->t_d.side_3 + tri->f.norm2.x
		* tri->t_d.side_1 + tri->f.norm3.x * tri->t_d.side_2);
  ret.y = -1 * (tri->f.norm1.y * tri->t_d.side_3 + tri->f.norm2.y
		* tri->t_d.side_1 + tri->f.norm3.y * tri->t_d.side_2);
  ret.z = -1 * (tri->f.norm1.z * tri->t_d.side_3 + tri->f.norm2.z
		* tri->t_d.side_1 + tri->f.norm3.z * tri->t_d.side_2);
  normalise(&ret);
  return (ret);
}

t_pos		get_norm_tri(t_pos *p1, t_pos *p2, t_pos *p3)
{
  t_pos		n;

  n.x = -((p2->y - p1->y) * (p3->z - p1->z) - (p2->z - p1->z)
	  * (p3->y - p1->y));
  n.y = -((p2->z - p1->z) * (p3->x - p1->x) - (p2->x - p1->x)
	  * (p3->z - p1->z));
  n.z = -((p2->x - p1->x) * (p3->y - p1->y) - (p2->y - p1->y)
	  * (p3->x - p1->x));
  normalise(&n);
  return (n);
}

void		apply_pos(t_face *f, t_pos *pos)
{
  f->pt1.x += pos->x;
  f->pt1.y += pos->y;
  f->pt1.z += pos->z;
  f->pt2.x += pos->x;
  f->pt2.y += pos->y;
  f->pt2.z += pos->z;
  f->pt3.x += pos->x;
  f->pt3.y += pos->y;
  f->pt3.z += pos->z;
}

void		apply_rot(t_face *f, t_pos *rot)
{
  go_derotate(&f->pt1.x, &f->pt1.y, &f->pt1.z, rot);
  go_derotate(&f->pt2.x, &f->pt2.y, &f->pt2.z, rot);
  go_derotate(&f->pt3.x, &f->pt3.y, &f->pt3.z, rot);
}

void		apply_size(t_face *face, double size)
{
  face->pt1.x *= size;
  face->pt1.y *= size;
  face->pt1.z *= size;
  face->pt2.x *= size;
  face->pt2.y *= size;
  face->pt2.z *= size;
  face->pt3.x *= size;
  face->pt3.y *= size;
  face->pt3.z *= size;
}
