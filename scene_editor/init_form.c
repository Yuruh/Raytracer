/*
** init_form.c for rt in /home/descam_d/rendu/IGRAPH/MUL_2014_rtracer/scene_editor
** 
** Made by Corentin Descamps
** Login   <descam_d@epitech.net>
** 
** Started on  Fri Jun  5 13:48:47 2015 Corentin Descamps
** Last update Fri Jun  5 14:08:59 2015 Corentin Descamps
*/

#include	<stdlib.h>
#include	<gtk/gtk.h>
#include	"object.h"

void		init_widget_pos(t_wid *Widget)
{
  if (!(Widget->entry_pos = malloc(sizeof(GtkWidget*) * 3)))
    exit(1);
  if (!(Widget->entry_rot = malloc(sizeof(GtkWidget*) * 3)))
    exit(1);
  if (!(Widget->label_pos = malloc(sizeof(GtkWidget*) * 4)))
    exit(1);
  if (!(Widget->label_rot = malloc(sizeof(GtkWidget*) * 4)))
    exit(1);
  if (!(Widget->entry_hlim = malloc(sizeof(GtkWidget*) * 3)))
    exit(1);
  if (!(Widget->label_hlim = malloc(sizeof(GtkWidget*) * 4)))
    exit(1);
  if (!(Widget->entry_blim = malloc(sizeof(GtkWidget*) * 3)))
    exit(1);
  if (!(Widget->label_blim = malloc(sizeof(GtkWidget*) * 4)))
    exit(1);

}

void		create_form_pos(GtkWidget **Label, GtkWidget **Entry,
				const char *str)
{
  Label[0] = gtk_label_new(str);
  Label[1] = gtk_label_new("X :");
  Entry[0] = gtk_entry_new();
  gtk_entry_set_max_length(GTK_ENTRY(Entry[0]), 10);
  Label[2] = gtk_label_new("Y :");
  Entry[1] = gtk_entry_new();
  gtk_entry_set_max_length(GTK_ENTRY(Entry[1]), 10);
  Label[3] = gtk_label_new("Z :");
  Entry[2] = gtk_entry_new();
  gtk_entry_set_max_length(GTK_ENTRY(Entry[2]), 10);
}
