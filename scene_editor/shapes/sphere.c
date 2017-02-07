/*
** sphere.c for rt in /home/descam_d/rendu/IGRAPH/MUL_2014_rtracer/scene_editor
** 
** Made by Corentin Descamps
** Login   <descam_d@epitech.net>
** 
** Started on  Thu Jun  4 10:22:10 2015 Corentin Descamps
** Last update Sun Jun  7 15:35:10 2015 Corentin Descamps
*/

#include	<stdlib.h>
#include	<gtk/gtk.h>
#include	"object.h"
#include	"set_form.h"
#include	"init_form.h"
#include	"save_shape.h"
#include	"color.h"

static void	set_cons(GtkWidget *Grid, GtkWidget **Label,
			 GtkWidget **Entry)
{
  gtk_grid_attach(GTK_GRID(Grid), Label[0],
		  0, 16, 2, 1);
  gtk_grid_attach(GTK_GRID(Grid), Label[1],
		  0, 17, 1, 1);
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
  gtk_grid_attach_next_to(GTK_GRID(Grid), Label[4],
			  Label[3], GTK_POS_BOTTOM, 1, 1);
  gtk_grid_attach_next_to(GTK_GRID(Grid), Entry[3],
			  Label[4], GTK_POS_RIGHT, 2, 1);
  gtk_grid_attach_next_to(GTK_GRID(Grid), Label[5],
			  Label[4], GTK_POS_BOTTOM, 1, 1);
  gtk_grid_attach_next_to(GTK_GRID(Grid), Entry[4],
			  Label[5], GTK_POS_RIGHT, 2, 1);

}

static void		create_form_cons(GtkWidget **Label, GtkWidget **Entry)
{
  Label[0] = gtk_label_new("CONSTANTE :");
  Label[1] = gtk_label_new("Rayon :");
  Entry[0] = gtk_entry_new();
  gtk_entry_set_max_length(GTK_ENTRY(Entry[0]), 10);
  Label[2] = gtk_label_new("Brillance :");
  Entry[1] = gtk_entry_new();
  gtk_entry_set_max_length(GTK_ENTRY(Entry[1]), 3);
  Label[3] = gtk_label_new("Specularite :");
  Entry[2] = gtk_entry_new();
  gtk_entry_set_max_length(GTK_ENTRY(Entry[2]), 3);
  Label[4] = gtk_label_new("Transparence :");
  Entry[3] = gtk_entry_new();
  gtk_entry_set_max_length(GTK_ENTRY(Entry[3]), 3);
  Label[5] = gtk_label_new("Reflexion :");
  Entry[4] = gtk_entry_new();
  gtk_entry_set_max_length(GTK_ENTRY(Entry[4]), 3);
}

static void		init_widget_cons(t_wid *Widget)
{
  if (!(Widget->entry_cons = malloc(sizeof(GtkWidget*) * 5)))
    exit(1);
  if (!(Widget->label_cons = malloc(sizeof(GtkWidget*) * 6)))
    exit(1);
}

void		form_sphere(GtkWidget *Window)
{
  t_wid		*Widget;
  GtkWidget	*Save;
  GtkWidget	*Grid;

  if (!(Widget = malloc(sizeof(t_wid))))
      exit(1);
  Widget->win = Window;
  init_widget_pos(Widget);
  init_widget_cons(Widget);
  create_form_pos(Widget->label_pos, Widget->entry_pos, "POSITION :");
  create_form_pos(Widget->label_rot, Widget->entry_rot, "ROTATION :");
  create_form_pos(Widget->label_hlim, Widget->entry_hlim, "LIMITE HAUTE :");
  create_form_pos(Widget->label_blim, Widget->entry_blim, "LIMITE_BASSE :");
  create_form_cons(Widget->label_cons, Widget->entry_cons);
  Grid = gtk_grid_new();
  gtk_container_add(GTK_CONTAINER(Window), Grid);
  gtk_grid_set_column_homogeneous(GTK_GRID(Grid), TRUE);
  set_all_position(Grid, Widget);
  set_cons(Grid, Widget->label_cons, Widget->entry_cons);
  color_scale(Grid, Widget);
  Save = gtk_button_new_with_label("Save");
  gtk_grid_attach(GTK_GRID(Grid), Save, 1, 27, 1, 1);
  g_signal_connect(G_OBJECT(Save), "clicked", G_CALLBACK(save_sphere), Widget);
}

void		add_sphere(GtkWidget *Widget, gpointer data)
{
  GtkWidget	*Window;

  (void)Widget;
  (void)data;
  Window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(Window), "New Sphere");
  gtk_window_set_default_size(GTK_WINDOW(Window), 1, 1);
  gtk_window_set_position(GTK_WINDOW(Window), GTK_WIN_POS_CENTER);
  gtk_window_set_modal(GTK_WINDOW(Window), TRUE);
  form_sphere(Window);
  gtk_widget_show_all(Window);
}
