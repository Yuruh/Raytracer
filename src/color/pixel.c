/*
** manage_image.c for wolf in /home/lemper_a/rendu/MUL_2014_wolf3d
**
** Made by Antoine LEMPEREUR
** Login   <lemper_a@epitech.net>
**
** Started on  Tue Dec 16 11:31:53 2014 Antoine LEMPEREUR
** Last update Sun Jun  7 16:00:37 2015 Antoine LEMPEREUR
*/

#include	"manage_image.h"
#include	"my.h"
#include	"color.h"

void		pixel_to_image(t_data *p, int x, int y, int color)
{
  int		i;

  i = y * p->win.size_line + x * p->win.bpp / 8;
  if (y >= 0 && y < p->height && x >= 0 && x < p->width)
    {
      p->win.data[p->count_img][i] =
	(char)(mlx_get_color_value(p->win.mlx, color) & 0xFF);
      p->win.data[p->count_img][i + 1] =
	(char)(mlx_get_color_value(p->win.mlx, color) >> 8 & 0xFF);
      p->win.data[p->count_img][i + 2] =
	(char)(mlx_get_color_value(p->win.mlx, color) >> 16 & 0xFF);
      p->win.data[p->count_img][i + 3] = 0;
    }
}

int		get_pixel_color(t_data *p, int x, int y)
{
  int		i;
  int		color;
  int		blue;
  int		green;
  int		red;

  i = y * p->win.size_line + x * p->win.bpp / 8;
  if (i >= 0)
    {
      blue = p->win.data[p->count_img][i] & 0xFF;
      green = p->win.data[p->count_img][i + 1] & 0xFF;
      red = p->win.data[p->count_img][i + 2] & 0xFF;
      color = red;
      color <<= 8;
      color += green;
      color <<= 8;
      color += blue;
      return (color);
    }
  return (BLACK);
}

int		get_pixel_text_color(t_obj *data, int x, int y)
{
  int		i;
  int		color;
  int		blue;
  int		green;
  int		red;
  int		size;

  size = data->texture.img->width * data->texture.img->height * 4;
  i = y * data->texture.img->size_line + x * data->texture.img->bpp / 8;
  if (i >= 0 && i + 2 < size)
    {
      blue = data->texture.text_data[i] & 0xFF;
      green = data->texture.text_data[i + 1] & 0xFF;
      red = data->texture.text_data[i + 2] & 0xFF;
      color = red;
      color <<= 8;
      color += green;
      color <<= 8;
      color += blue;
      return (color);
    }
  return (BLACK);
}
