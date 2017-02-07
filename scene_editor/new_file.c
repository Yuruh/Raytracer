/*
** new_file.c for rt in /home/descam_d/rendu/IGRAPH/MUL_2014_rtracer/scene_editor
** 
** Made by Corentin Descamps
** Login   <descam_d@epitech.net>
** 
** Started on  Thu May 28 10:48:58 2015 Corentin Descamps
** Last update Sun Jun  7 22:15:34 2015 Corentin Descamps
*/

#include	<stdlib.h>
#include	<gtk/gtk.h>
#include	<string.h>
#include	"data.h"
#include	"define.h"
#include	"object.h"
#include	"verif.h"
#include	"writer.h"
#include	"fill_object.h"

extern t_def	g_def;

void		create_form(GtkWidget *Label[4], GtkWidget **Entry)
{
  Label[0] = gtk_label_new("File name");
  Entry[0] = gtk_entry_new();
  Label[1] = gtk_label_new("  Anti Aliasing");
  Entry[1] = gtk_entry_new();
  Label[2] = gtk_label_new("Width");
  Entry[2] = gtk_entry_new();
  Label[3] = gtk_label_new("Height");
  Entry[3] = gtk_entry_new();
}

void		set_form(GtkWidget *Grid, GtkWidget *Label[4], GtkWidget **Entry)
{
  gtk_grid_set_column_homogeneous(GTK_GRID(Grid), TRUE);
  gtk_grid_attach(GTK_GRID(Grid), Label[0],
			    0, 0, 1, 1);
  gtk_grid_attach_next_to(GTK_GRID(Grid), Entry[0],
			  Label[0], GTK_POS_RIGHT, 2, 1);
  gtk_grid_attach_next_to(GTK_GRID(Grid), Label[1],
			  Label[0], GTK_POS_BOTTOM, 1, 1);
  gtk_grid_attach_next_to(GTK_GRID(Grid), Entry[1],
			  Label[1], GTK_POS_RIGHT, 2, 1);
  gtk_grid_attach_next_to(GTK_GRID(Grid), Label[2],
			  Label[1], GTK_POS_BOTTOM, 1, 1);
  gtk_grid_attach_next_to(GTK_GRID(Grid), Entry[2],
			  Label[2], GTK_POS_RIGHT, 2, 1);
  gtk_grid_attach_next_to(GTK_GRID(Grid), Label[3],
  			  Label[2], GTK_POS_BOTTOM, 1, 1);
  gtk_grid_attach_next_to(GTK_GRID(Grid), Entry[3],
  			  Label[3], GTK_POS_RIGHT, 2, 1);
}

void		save_button(GtkWidget *Widget, gpointer data)
{
  GtkWidget	**Entry;

  (void)Widget;
  Entry = (GtkWidget **)data;
  g_def.filename = strdup(gtk_entry_get_text(GTK_ENTRY(Entry[0])));
  g_def.a_a = strdup(gtk_entry_get_text(GTK_ENTRY(Entry[1])));
  g_def.width = strdup(gtk_entry_get_text(GTK_ENTRY(Entry[2])));
  g_def.height = strdup(gtk_entry_get_text(GTK_ENTRY(Entry[3])));
  if (verif_value(0) == EXIT_SUCCESS)
    {
      gtk_widget_destroy(g_def.New);
      g_def.filename = strcat((char *)g_def.filename, ".rt");
    }
}

void		formulary(GtkWidget *Window)
{
  GtkWidget	*Label[4];
  GtkWidget	**Entry;
  GtkWidget	*Save;
  GtkWidget	*Grid;

  if (!(Entry = malloc(sizeof(GtkWidget*) * 4)))
    exit(1);
  create_form(Label, Entry);
  Grid = gtk_grid_new();
  gtk_container_add(GTK_CONTAINER(Window), Grid);
  set_form(Grid, Label, Entry);
  gtk_grid_insert_column(GTK_GRID(Grid), 1);
  Save = gtk_button_new_with_label("Save");
  gtk_grid_attach(GTK_GRID(Grid), Save, 1, 4, 2, 1);
  g_signal_connect(G_OBJECT(Save), "clicked", G_CALLBACK(save_button), Entry);
}

void		new_file(GtkWidget *Widget, gpointer data)
{
  t_data	*info;

  (void)Widget;
  g_def.New = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(g_def.New), "New Scene");
  gtk_window_set_default_size(GTK_WINDOW(g_def.New), 1, 1);
  gtk_window_set_position(GTK_WINDOW(g_def.New), GTK_WIN_POS_CENTER);
  gtk_window_set_modal(GTK_WINDOW(g_def.New), TRUE);
  gtk_window_set_decorated(GTK_WINDOW(g_def.New), FALSE);
  info = (t_data *)data;
  formulary(g_def.New);
  maj_window(info);
  gtk_widget_show_all(g_def.New);
}
