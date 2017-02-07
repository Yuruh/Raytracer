/*
** save_color.c for rt in /home/descam_d/rendu/IGRAPH/MUL_2014_rtracer/scene_editor/shapes
** 
** Made by Corentin Descamps
** Login   <descam_d@epitech.net>
** 
** Started on  Sun Jun  7 15:49:59 2015 Corentin Descamps
** Last update Sun Jun  7 18:09:50 2015 Corentin Descamps
*/

#include	<stdlib.h>
#include	<gtk/gtk.h>
#include	"object.h"

void		save_color(t_wid *wid, unsigned char rgb[3])
{
  rgb[0] = (unsigned char)gtk_range_get_value(GTK_RANGE(wid->Scale[0]));
  rgb[1] = (unsigned char)gtk_range_get_value(GTK_RANGE(wid->Scale[1]));
  rgb[2] = (unsigned char)gtk_range_get_value(GTK_RANGE(wid->Scale[2]));
}
