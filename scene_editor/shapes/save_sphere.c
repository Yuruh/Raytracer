/*
** save_sphere.c for rt in /home/descam_d/rendu/IGRAPH/MUL_2014_rtracer/scene_editor
** 
** Made by Corentin Descamps
** Login   <descam_d@epitech.net>
** 
** Started on  Fri Jun  5 15:16:47 2015 Corentin Descamps
** Last update Sun Jun  7 18:12:39 2015 Corentin Descamps
*/

#include	<stdlib.h>
#include	<gtk/gtk.h>
#include	"object.h"
#include	"save.h"
#include	"color.h"

static void		save_cons(GtkWidget **Entry, t_obj *tmp)
{
  tmp->rayon = atoi(gtk_entry_get_text(GTK_ENTRY(Entry[0])));
  tmp->bril = atoi(gtk_entry_get_text(GTK_ENTRY(Entry[1])));
  tmp->spec = atoi(gtk_entry_get_text(GTK_ENTRY(Entry[2])));
  tmp->trans = atoi(gtk_entry_get_text(GTK_ENTRY(Entry[3])));
  tmp->ref = atoi(gtk_entry_get_text(GTK_ENTRY(Entry[4])));
}

void		save_sphere(GtkWidget *Widget, gpointer data)
{
  t_wid		*wid;
  t_obj		tmp;

  (void)Widget;
  wid = (t_wid*)data;
  tmp.type = SPHERE;
  save_all_pos(wid, &tmp);
  save_cons(wid->entry_cons, &tmp);
  save_color(wid, tmp.rgb);
  stack_obj(&tmp);
  gtk_widget_destroy(wid->win);
}
