/*
** color.c for rt in /home/descam_d/rendu/IGRAPH/MUL_2014_rtracer/scene_editor
** 
** Made by Corentin Descamps
** Login   <descam_d@epitech.net>
** 
** Started on  Sun Jun  7 15:08:00 2015 Corentin Descamps
** Last update Sun Jun  7 17:06:29 2015 Corentin Descamps
*/

#include	<stdlib.h>
#include	<gtk/gtk.h>
#include	"object.h"

void		color_scale(GtkWidget *Grid, t_wid *Widget)
{
  GtkWidget	*Label[3];

  if (!(Widget->Scale = malloc(sizeof(GtkWidget*) * 3)))
    exit(1);
  Label[0] = gtk_label_new("Red :");
  Label[1] = gtk_label_new("Green :");
  Label[2] = gtk_label_new("Blue :");
  Widget->Scale[0] = gtk_scale_new_with_range(GTK_ORIENTATION_HORIZONTAL,
					      0, 255, 1);
  Widget->Scale[1] = gtk_scale_new_with_range(GTK_ORIENTATION_HORIZONTAL,
					      0, 255, 1);
  Widget->Scale[2] = gtk_scale_new_with_range(GTK_ORIENTATION_HORIZONTAL,
					      0, 255, 1);
  gtk_grid_attach(GTK_GRID(Grid), Widget->Scale[0], 1, 22, 2, 1);
  gtk_grid_attach(GTK_GRID(Grid), Widget->Scale[1], 1, 23, 2, 1);
  gtk_grid_attach(GTK_GRID(Grid), Widget->Scale[2], 1, 24, 2, 1);
  gtk_grid_attach(GTK_GRID(Grid), Label[0], 0, 22, 1, 1);
  gtk_grid_attach(GTK_GRID(Grid), Label[1], 0, 23, 1, 1);
  gtk_grid_attach(GTK_GRID(Grid), Label[2], 0, 24, 1, 1);
}
