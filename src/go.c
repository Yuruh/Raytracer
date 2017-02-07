/*
** go.c for rt in /home/lemper_a/rendu/igraph/MUL_2014_rtv1
**
** Made by Antoine LEMPEREUR
** Login   <lemper_a@epitech.net>
**
** Started on  Tue Mar 10 15:41:37 2015 Antoine LEMPEREUR
** Last update Thu Jun  4 14:03:57 2015 Adrien Vasseur
*/

#include	<math.h>
#include	<pthread.h>
#include	<stdlib.h>
#include	"go.h"
#include	"calc.h"
#include	"image.h"
#include	"my.h"
#include	"triangle.h"
#include	"get_k.h"
#include	"my_lib.h"
#include	"blur.h"
#include	"parsing_rt.h"
#include	"error_obj.h"

static void	process_ray(t_data *d, t_dir *dir, double tmp_i, double tmp_j)
{
  dir->vec.x = W / 2 / tan(25 * M_PI / 180);
  dir->vec.y = W / 2 - tmp_i;
  dir->vec.z = H / 2 - tmp_j;
  if (d->rot.x != 0.0 || d->rot.y != 0.0 || d->rot.z != 0.0)
    go_derotate(&dir->vec.x, &dir->vec.y, &dir->vec.z, &d->rot);
  dir->init = d->eye;
}

int		anti_aliasing(t_data *d, double i, double j, int *c)
{
  int		k;
  t_ray_data	ray;
  double	tmp_i;
  double	tmp_j;
  t_dir		dir;

  ray.tri = NULL;
  tmp_j = j;
  k = 0;
  while (k < d->a_a * d->a_a)
    {
      tmp_i = i;
      while (tmp_i < i + 1)
	{
	  process_ray(d, &dir, tmp_i, tmp_j);
	  ray = get_pix(d, &dir, 0, NULL);
	  c[k++] = ray.color;
	  tmp_i += (1.0 / d->a_a);
	}
      tmp_j += (1.0 / d->a_a);
    }
  set_blur(d, &ray, (int)i, (int)j);
  return (mix(c, d->a_a * d->a_a));
}

void		load_xpm(t_data *d, t_obj **obj)
{
  t_obj		*t;
  int		buff;

  t = *obj;
  while (t != NULL)
    {
      if ((t->type == SPHERE || t->type == PLAN) && t->xpm.xpm_path != NULL)
	{
	  t->xpm.xpm_img = malloc(sizeof(t_img));
	  if (!(t->xpm.xpm_img =
		mlx_xpm_file_to_image(d->win.mlx, t->xpm.xpm_path,
				      &(t->xpm.xpm_img->width),
				      &(t->xpm.xpm_img->height))))
	    error_view('g');
	  else
	    t->texture.img = t->xpm.xpm_img;
	  t->texture.text_data = mlx_get_data_addr
	    (t->xpm.xpm_img, &buff, &buff, &buff);
	}
      t = t->next;
    }
}

void				go(t_data *d, t_vec2i ori, t_vec2i size)
{
  int				*c;
  t_vec2i			pos;
  static pthread_mutex_t	shield = PTHREAD_MUTEX_INITIALIZER;

  pos.y = ori.y;
  if (!(c = malloc(sizeof(int) * (unsigned long)(d->a_a * d->a_a))))
    my_exit("Malloc failed.\n");
  while (pos.y < ori.y + size.y)
    {
      pos.x = ori.x;
      while (pos.x < ori.x + size.x)
	{
	  pixel_to_image(d, pos.x, pos.y, anti_aliasing(d, pos.x, pos.y, c));
	  pos.x += 1;
	}
      if (d->has_win == 1)
	{
	  pthread_mutex_lock(&shield);
	  mlx_put_image_to_window
	    (d->win.mlx, d->win.win, d->win.img[d->count_img], 0, 0);
	  pthread_mutex_unlock(&shield);
	}
      pos.y += 1;
    }
}
