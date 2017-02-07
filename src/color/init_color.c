/*
** init_color.c for rt in /home/descam_d/rendu/IGRAPH/MUL_2014_rtracer
** 
** Made by Corentin Descamps
** Login   <descam_d@epitech.net>
** 
** Started on  Mon Jun  1 17:13:05 2015 Corentin Descamps
** Last update Sat Jun  6 14:40:57 2015 Raphael Thiebault
*/

#include	"my.h"
#include	"color.h"
#include	"phong.h"

void		set_tab_color(unsigned int *tab, int c)
{
  tab[0] = ((c & 0xFF0000) >> 16);
  tab[1] = ((c & 0x00FF00) >> 8);
  tab[2] = (c & 0x0000FF);
}

void		set_rgb_bril(unsigned int *rgb, int col, t_cons *cons,
			     t_lux_data *l_data)
{
  rgb[0] = (unsigned int)(((col & 0xFF0000) >> 16) * (1.0f - cons->bril)
			  + ((l_data->col & 0xFF0000) >> 16) * cons->bril);
  rgb[1] = (unsigned int)(((col & 0x00FF00) >> 8) * (1.0f - cons->bril)
			  + ((l_data->col & 0x00FF00) >> 8) * cons->bril);
  rgb[2] = (unsigned int)((col & 0x0000FF) * (1.0f - cons->bril)
			  + (l_data->col & 0x0000FF) * cons->bril);
}

void		init_col_tab(t_color *color, int col,
			     t_cons *cons, t_lux_data *l_data)
{
  set_rgb_bril(color->rgb, col, cons, l_data);
  rgb_phong(color->phong, l_data, cons);
  set_tab_color(color->ref_tab, l_data->ref_col);
  set_tab_color(color->tra_tab, l_data->tra_col);
}
