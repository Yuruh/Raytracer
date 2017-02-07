/*
** create_tri_list.c for azer in /home/lemper_a/rendu/igraph/MUL_2014_rtracer
**
** Made by Antoine LEMPEREUR
** Login   <lemper_a@epitech.net>
**
** Started on  Thu May 28 13:23:22 2015 Antoine LEMPEREUR
** Last update Sun Jun  7 16:46:41 2015 Antoine LEMPEREUR
*/

#include	"my.h"
#include	"color.h"
#include	"triangle.h"
#include	"get_k.h"
#include	"my_lib.h"

void		create_obj_list(t_obj **o, t_face_data *tri)
{
  t_triangle	*triangle;

  triangle = NULL;
  (*o) = malloc_obj();
  (*o)->type = OBJ;
  (*o)->texture.is_normale = tri->is_normale;
  (*o)->texture.is_texture = tri->is_texture;
  (*o)->texture.img = tri->img;
  (*o)->texture.text_data = tri->text_data;
  (*o)->texture.text_path = tri->text_path;
  (*o)->src_col = RED;
  (*o)->cons.focus = tri->cons.focus;
  get_tri_list(&triangle, tri);
  (*o)->triangle = triangle;
  get_lim_box(tri, &(*o)->lim);
  (*o)->next = NULL;
}

void		fill_tri_list(t_triangle *tmp, t_face_data *f, unsigned int i)
{
  tmp->f = f->face[i];
  if (f->is_normale)
    {
      normalise(&tmp->f.norm1);
      normalise(&tmp->f.norm2);
      normalise(&tmp->f.norm3);
    }
  else
    tmp->t_d.norm = get_norm_tri(&f->face[i].pt1,
				 &f->face[i].pt2, &f->face[i].pt3);
  tmp->cons = f->cons;
  tmp->src_col = f->color;
  tmp->t_d.u = get_vec(&f->face[i].pt1, &f->face[i].pt2);
  tmp->t_d.v = get_vec(&f->face[i].pt1, &f->face[i].pt3);
  tmp->t_d.n = cross(&tmp->t_d.u, &tmp->t_d.v);
  tmp->t_d.uu = DOT(tmp->t_d.u, tmp->t_d.u);
  tmp->t_d.uv = DOT(tmp->t_d.u, tmp->t_d.v);
  tmp->t_d.vv = DOT(tmp->t_d.v, tmp->t_d.v);
  tmp->t_d.d = tmp->t_d.uv * tmp->t_d.uv - tmp->t_d.uu * tmp->t_d.vv;
}

t_triangle	*get_tri_list(t_triangle **tri, t_face_data *f)
{
  unsigned int	i;
  t_triangle	*tmp;

  i = 0;
  while (i < f->lim)
    {
      apply_size(&f->face[i], f->size);
      apply_rot(&f->face[i], &f->rot);
      apply_pos(&f->face[i], &f->pos);
      if (!(tmp = malloc(sizeof(t_triangle))))
        my_exit("Could not alloc\n");
      fill_tri_list(tmp, f, i);
      tmp->next = *tri;
      *tri = tmp;
      i++;
    }
  return (*tri);
}

void		fill_obj_in_obj_list(t_obj *tmp, t_face_data *tri)
{
  t_triangle	*triangle;

  triangle = NULL;
  tmp->type = OBJ;
  tmp->cons = tri->cons;
  tmp->cons.tra = 0;
  tmp->src_col = WHITE;
  tmp->texture.is_normale = tri->is_normale;
  tmp->texture.is_texture = tri->is_texture;
  tmp->texture.img = tri->img;
  tmp->xpm.xpm_img = tri->img;
  tmp->xpm.xpm_path = tri->text_path;
  tmp->texture.text_data = tri->text_data;
  get_tri_list(&triangle, tri);
  tmp->triangle = triangle;
  get_lim_box(tri, &tmp->lim);
}

void		put_tri_in_list(t_obj **o, t_face_data *tri)
{
  t_obj		*tmp;

  if (*o == NULL)
    {
      create_obj_list(o, tri);
      tri = tri->next;
    }
  if (*o != NULL)
    {
      tmp = *o;
      while (tmp->next)
        tmp = tmp->next;
      while (tri)
        {
          tmp->next = malloc_obj();
          tmp = tmp->next;
          fill_obj_in_obj_list(tmp, tri);
          tri = tri->next;
        }
      tmp->next = NULL;
    }
}
