/*
** view.c for rt in /home/descam_d/rendu/IGRAPH/MUL_2014_rtracer/scene_editor
** 
** Made by Corentin Descamps
** Login   <descam_d@epitech.net>
** 
** Started on  Sat Jun  6 17:55:29 2015 Corentin Descamps
** Last update Sun Jun  7 17:47:55 2015 Corentin Descamps
*/

#include	<stdlib.h>
#include	<gtk/gtk.h>
#include	"object.h"
#include	"set_form.h"
#include	"init_form.h"

extern	t_view	g_view;

void		init_view()
{
  g_view.pos.x = 0;
  g_view.pos.y = 0;
  g_view.pos.z = 0;
  g_view.rot.x = 0;
  g_view.rot.y = 0;
  g_view.rot.z = 0;
}

void		save_view(GtkWidget *Widget, gpointer data)
{
  t_wid		*wid;

  (void)Widget;
  wid = (t_wid*)data;
  g_view.pos.x = atoi(gtk_entry_get_text(GTK_ENTRY(wid->entry_pos[0])));
  g_view.pos.y = atoi(gtk_entry_get_text(GTK_ENTRY(wid->entry_pos[1])));
  g_view.pos.z = atoi(gtk_entry_get_text(GTK_ENTRY(wid->entry_pos[2])));
  g_view.rot.x = atoi(gtk_entry_get_text(GTK_ENTRY(wid->entry_rot[0])));
  g_view.rot.y = atoi(gtk_entry_get_text(GTK_ENTRY(wid->entry_rot[1])));
  g_view.rot.z = atoi(gtk_entry_get_text(GTK_ENTRY(wid->entry_rot[2])));
  gtk_widget_destroy(wid->win);
}

void		form_view(GtkWidget *Window)
{
  t_wid		*Widget;
  GtkWidget	*Save;
  GtkWidget	*Grid;

  if (!(Widget = malloc(sizeof(t_wid))))
    exit(1);
  Widget->win = Window;
  init_widget_pos(Widget);
  create_form_pos(Widget->label_pos, Widget->entry_pos, "POSITION :");
  create_form_pos(Widget->label_rot, Widget->entry_rot, "ROTATION :");
  Grid = gtk_grid_new();
  gtk_container_add(GTK_CONTAINER(Window), Grid);
  gtk_grid_set_column_homogeneous(GTK_GRID(Grid), TRUE);
  set_position(Grid, Widget->label_pos, Widget->entry_pos, 0);
  set_position(Grid, Widget->label_rot, Widget->entry_rot, 4);
  Save = gtk_button_new_with_label("Save");
  gtk_grid_attach(GTK_GRID(Grid), Save, 1, 22, 1, 1);
  g_signal_connect(G_OBJECT(Save), "clicked", G_CALLBACK(save_view), Widget);
}

void		modif_view(GtkWidget *Widget, gpointer data)
{
  GtkWidget	*Window;

  (void)Widget;
  (void)data;
  Window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(Window), "Modif view");
  gtk_window_set_default_size(GTK_WINDOW(Window), 1, 1);
  gtk_window_set_position(GTK_WINDOW(Window), GTK_WIN_POS_CENTER);
  gtk_window_set_modal(GTK_WINDOW(Window), TRUE);
  form_view(Window);
  gtk_widget_show_all(Window);
}
