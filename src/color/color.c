/*
** color.c for rt in /home/thieba_r/Documents/IGRAPH/MUL_2014_rtracer/src
**
** Made by Raphael Thiebault
** Login   <thieba_r@epitech.net>
**
** Started on  Tue May  5 14:55:56 2015 Raphael Thiebault
** Last update Sun Jun  7 19:37:11 2015 Raphael Thiebault
*/

#include	"my.h"
#include	"color.h"
#include	"phong.h"

int		mix(int *color, int len)
{
  int		c;
  int		i;
  int		r;
  int		g;
  int		b;

  i = -1;
  r = 0;
  b = 0;
  g = 0;
  while (++i < len)
    {
      r += color[i] >> 16 & 0xFF;
      g += color[i] >> 8 & 0xFF;
      b += color[i] & 0xFF;
    }
  c = r / len;
  c <<= 8;
  c += g / len;
  c <<= 8;
  c += b / len;
  return (c);
}

unsigned int	modify_col(int col, t_lux_data *l_data, int nb_light,
			   t_cons *cons)
{
  t_color	c;
  int		i;

  i = 0;
  init_col_tab(&c, col, cons, l_data);
  while (i < 3)
    {
      c.rgb[i] = c.rgb[i] * (1 - cons->ref) + c.ref_tab[i] * cons->ref;
      c.rgb[i] = c.rgb[i] * (1 - cons->tra) + c.tra_tab[i] * cons->tra;
      c.amb[i] = c.rgb[i] * (20.0 / 100.0);
      l_data->cos += cons->tra;
      if (l_data->cos < 1.0)
	c.rgb[i] *= (l_data->cos);
      c.rgb[i] = apply_phong(c.rgb[i], c.phong[i], l_data);
      if (l_data->shdw < 1 - 0.5)
	c.rgb[i] *= (1 - l_data->shdw);
      else
	c.rgb[i] *= 0.5;
      if (c.rgb[i] < c.amb[i])
	c.rgb[i] = c.amb[i];
      c.rgb[i] /= (unsigned int)nb_light;
      i++;
    }
  return ((c.rgb[0] << 16) | (c.rgb[1] << 8) | (c.rgb[2]));
}
