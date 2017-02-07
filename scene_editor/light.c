/*
** light.c for  in /home/descam_d/rendu/IGRAPH/MUL_2014_rtracer/scene_editor
** 
** Made by Corentin Descamps
** Login   <descam_d@epitech.net>
** 
** Started on  Sun Jun  7 17:20:09 2015 Corentin Descamps
** Last update Sun Jun  7 21:31:49 2015 Corentin Descamps
*/

#include	<stdlib.h>
#include	<gtk/gtk.h>
#include	"object.h"
#include	"set_form.h"
#include	"init_form.h"
#include	"color.h"

extern	t_light	*g_light;

void		save_light(GtkWidget *Button, gpointer data)
{
  t_wid		*Widget;
  t_light	tmp;

  (void)Button;
  (void)data;
  Widget = (t_wid*)data;
  tmp.pos.x = atoi(gtk_entry_get_text(GTK_ENTRY(Widget->entry_pos[0])));
  tmp.pos.y = atoi(gtk_entry_get_text(GTK_ENTRY(Widget->entry_pos[1])));
  tmp.pos.z = atoi(gtk_entry_get_text(GTK_ENTRY(Widget->entry_pos[2])));
  save_color(Widget, tmp.rgb);
  stack_light(&tmp);
  gtk_widget_destroy(Widget->win);
}

void		form_light(GtkWidget *Window)
{
  t_wid		*Widget;
  GtkWidget	*Save;
  GtkWidget	*Grid;

  if (!(Widget = malloc(sizeof(t_wid))))
    exit(1);
  Widget->win = Window;
  init_widget_pos(Widget);
  create_form_pos(Widget->label_pos, Widget->entry_pos, "POSITION :");
  Grid = gtk_grid_new();
  gtk_container_add(GTK_CONTAINER(Window), Grid);
  gtk_grid_set_column_homogeneous(GTK_GRID(Grid), TRUE);
  set_position(Grid, Widget->label_pos, Widget->entry_pos, 0);
  color_scale(Grid, Widget);
  Save = gtk_button_new_with_label("Save");
  gtk_grid_attach(GTK_GRID(Grid), Save, 1, 27, 1, 1);
  g_signal_connect(G_OBJECT(Save), "clicked", G_CALLBACK(save_light), Widget);
}

void		add_light(GtkWidget *Button, gpointer data)
{
  GtkWidget	*Window;

  (void)Button;
  (void)data;
  Window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(Window), "Add light");
  gtk_window_set_default_size(GTK_WINDOW(Window), 1, 1);
  gtk_window_set_position(GTK_WINDOW(Window), GTK_WIN_POS_CENTER);
  gtk_window_set_modal(GTK_WINDOW(Window), TRUE);
  form_light(Window);
  gtk_widget_show_all(Window);
}
