/*
** get_blur_color.c for azer in /home/lemper_a/rendu/igraph/MUL_2014_rtracer/src
**
** Made by Antoine LEMPEREUR
** Login   <lemper_a@epitech.net>
**
** Started on  Mon Jun  1 14:17:59 2015 Antoine LEMPEREUR
** Last update Thu Jun  4 13:42:36 2015 Antoine LEMPEREUR
*/

#include	"my.h"

void		add_blur(t_data *d, int i, int j, int rgb[3])
{
  int		color;

  color = get_pixel_color(d, i, j);
  rgb[0] += (color & 0xFF0000) >> 16;
  rgb[1] += (color & 0x00FF00) >> 8;
  rgb[2] += (color & 0x0000FF);
}
int		final_blur_color(int rgb[3], int total)
{
  if (total != 0)
    {
      rgb[0] /= total;
      rgb[1] /= total;
      rgb[2] /= total;
    }
  else
    return (-1);
  return ((rgb[0] << 16) | (rgb[1] << 8) | (rgb[2]));
}

void		set_rgb_and_total(int rgb[3], int *total)
{
  rgb[0] = 0;
  rgb[1] = 0;
  rgb[2] = 0;
  *total = 0;
}

int		get_blur_color(t_data *d, int i, int j)
{
  int		total;
  int		rgb[3];
  int		lim_x;
  int		lim_y;

  if (d->blur[j][i].focus == 1)
    return (get_pixel_color(d, i, j));
  set_i_j(&i, &j, d->width, d->height);
  lim_x = BLUR + i;
  lim_y = BLUR + j;
  set_rgb_and_total(rgb, &total);
  j--;
  while (++j < lim_y)
    {
      i = lim_x - BLUR - 1;
      while (++i < lim_x)
	if (d->blur[j][i].focus != 1)
	  {
	    add_blur(d, i, j, rgb);
	    total++;
	  }
    }
  return (final_blur_color(rgb, total));
}
