/*
** blur.c for rt in /home/lemper_a/rendu/igraph/MUL_2014_rtracer/src
**
** Made by Antoine LEMPEREUR
** Login   <lemper_a@epitech.net>
**
** Started on  Sun May  3 11:53:02 2015 Antoine LEMPEREUR
** Last update Mon Jun  1 14:18:58 2015 Antoine LEMPEREUR
*/

#include	<stdlib.h>
#include	"my.h"
#include	"manage_image.h"
#include	"my_lib.h"
#include	"blur.h"

void		set_blur(t_data *d, t_ray_data *ray, int i, int j)
{
  d->blur[j][i].k = ray->k.k;
  if (ray->obj != NULL)
    d->blur[j][i].focus = ray->obj->cons.focus;
  else if (ray->tri != NULL)
    d->blur[j][i].focus = ray->tri->cons.focus;
  else
    d->blur[j][i].focus = 0;
}

t_blur		**get_blur_tab(int width, int height)
{
  t_blur	**blur;
  int		i;

  i = 0;
  if (!(blur = malloc(sizeof(*blur) * (unsigned int)(height))))
    my_exit("Could not alloc\n");
  while (i < height)
    if (!(blur[i++] = malloc(sizeof(**blur) * (unsigned int)width)))
      my_exit("Could not alloc\n");
  return (blur);
}

void		set_i_j(int *i, int *j, int width, int height)
{
  if (*i - BLUR / 2 < 0)
    *i = BLUR / 2;
  if (*j - BLUR / 2 < 0)
    *j = BLUR / 2;
  if (*i + BLUR / 2 > width)
    *i = width - BLUR / 2;
  if (*j + BLUR / 2 > height)
    *j = height - BLUR / 2;
  *j -= BLUR / 2;
  *i -= BLUR / 2;
}

void		apply_blur(t_data *d)
{
  int		i;
  int		j;

  i = -1;
  while (++i < d->width - 1)
    {
      j = -1;
      while (++j < d->height - 1)
        d->blur[j][i].color = get_blur_color(d, i, j);
    }
  i = -1;
  while (++i < d->width - 1)
    {
      j = -1;
      while (++j < d->height - 1)
        if (d->blur[j][i].color != -1)
          pixel_to_image(d, i, j, d->blur[j][i].color);
      mlx_put_image_to_window(d->win.mlx, d->win.win,
			      d->win.img[d->count_img], 0, 0);
    }
}
