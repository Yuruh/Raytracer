/*
** set_form.c for rt in /home/descam_d/rendu/IGRAPH/MUL_2014_rtracer/scene_editor
** 
** Made by Corentin Descamps
** Login   <descam_d@epitech.net>
** 
** Started on  Thu Jun  4 11:03:48 2015 Corentin Descamps
** Last update Sun Jun  7 15:33:49 2015 Corentin Descamps
*/

#include	<stdlib.h>
#include	<gtk/gtk.h>
#include	"object.h"

void		set_position(GtkWidget *Grid, GtkWidget **Label,
			     GtkWidget **Entry, int pos)
{
  gtk_grid_attach(GTK_GRID(Grid), Label[0],
		  0, pos, 2, 1);
  gtk_grid_attach(GTK_GRID(Grid), Label[1],
		  0, pos + 1, 1, 1);
  gtk_grid_attach_next_to(GTK_GRID(Grid), Entry[0],
			  Label[1], GTK_POS_RIGHT, 2, 1);
  gtk_grid_attach_next_to(GTK_GRID(Grid), Label[2],
			  Label[1], GTK_POS_BOTTOM, 1, 1);
  gtk_grid_attach_next_to(GTK_GRID(Grid), Entry[1],
			  Label[2], GTK_POS_RIGHT, 2, 1);
  gtk_grid_attach_next_to(GTK_GRID(Grid), Label[3],
			  Label[2], GTK_POS_BOTTOM, 1, 1);
  gtk_grid_attach_next_to(GTK_GRID(Grid), Entry[2],
			  Label[3], GTK_POS_RIGHT, 2, 1);
}

void		set_all_position(GtkWidget *Grid, t_wid *Widget)
{
  set_position(Grid, Widget->label_pos, Widget->entry_pos, 0);
  set_position(Grid, Widget->label_rot, Widget->entry_rot, 4);
  set_position(Grid, Widget->label_hlim, Widget->entry_hlim, 8);
  set_position(Grid, Widget->label_blim, Widget->entry_blim, 12);
}
