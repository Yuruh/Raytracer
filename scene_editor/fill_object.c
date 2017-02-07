/*
** fill_object.c for rt in /home/descam_d/rendu/IGRAPH/MUL_2014_rtracer/scene_editor
** 
** Made by Corentin Descamps
** Login   <descam_d@epitech.net>
** 
** Started on  Wed Jun  3 12:07:38 2015 Corentin Descamps
** Last update Sun Jun  7 22:14:31 2015 Corentin Descamps
*/

#include	<stdlib.h>
#include	<gtk/gtk.h>
#include	"data.h"
#include	"object.h"
#include	"save_shape.h"
#include	"writer.h"

t_obj		*g_obj;
t_view		g_view;
t_light		*g_light;

void		create_button(GtkWidget **Button)
{
  Button[0] = gtk_button_new_with_label("Add sphere");
  Button[1] = gtk_button_new_with_label("Add cylindre");
  Button[2] = gtk_button_new_with_label("Add plan");
  Button[3] = gtk_button_new_with_label("Add cone");
  Button[4] = gtk_button_new_with_label("Modif view");
  Button[5] = gtk_button_new_with_label("Add light");
  Button[6] = gtk_button_new_with_label("Finish");
}

void		place_widget(GtkWidget *Grid, GtkWidget **Button)
{
  gtk_grid_set_column_homogeneous(GTK_GRID(Grid), TRUE);
  gtk_grid_attach(GTK_GRID(Grid), Button[0],
		  0, 1, 1, 1);
  gtk_grid_attach_next_to(GTK_GRID(Grid), Button[1],
  			  Button[0], GTK_POS_BOTTOM, 1, 1);
  gtk_grid_attach_next_to(GTK_GRID(Grid), Button[2],
  			  Button[1], GTK_POS_BOTTOM, 1, 1);
  gtk_grid_attach_next_to(GTK_GRID(Grid), Button[3],
  			  Button[2], GTK_POS_BOTTOM, 1, 1);
  gtk_grid_attach_next_to(GTK_GRID(Grid), Button[4],
  			  Button[3], GTK_POS_BOTTOM, 1, 1);
  gtk_grid_attach_next_to(GTK_GRID(Grid), Button[5],
  			  Button[4], GTK_POS_BOTTOM, 1, 1);
  gtk_grid_attach_next_to(GTK_GRID(Grid), Button[6],
  			  Button[5], GTK_POS_BOTTOM, 1, 1);
}

void		maj_window(t_data *data)
{
  GtkWidget	**Button;

  if (!(Button = malloc(sizeof(GtkWidget*) * 7)))
    exit(1);
  g_obj = NULL;
  create_button(Button);
  place_widget(data->table, Button);
  gtk_widget_show_all(data->MainWindow);
  init_view();
  g_signal_connect(G_OBJECT(Button[0]), "clicked",
		   G_CALLBACK(add_sphere), NULL);
  g_signal_connect(G_OBJECT(Button[1]), "clicked",
		   G_CALLBACK(add_cyl), NULL);
  g_signal_connect(G_OBJECT(Button[2]), "clicked",
		   G_CALLBACK(add_plan), NULL);
  g_signal_connect(G_OBJECT(Button[3]), "clicked",
		   G_CALLBACK(add_cone), NULL);
  g_signal_connect(G_OBJECT(Button[4]),
		   "clicked", G_CALLBACK(modif_view), NULL);
  g_signal_connect(G_OBJECT(Button[5]), "clicked",
		   G_CALLBACK(add_light), NULL);
  g_signal_connect(G_OBJECT(Button[6]), "clicked",
		   G_CALLBACK(writer), NULL);
}
