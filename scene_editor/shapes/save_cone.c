/*
** save_cone.c for rt in /home/descam_d/rendu/IGRAPH/MUL_2014_rtracer/scene_editor/shapes
** 
** Made by Corentin Descamps
** Login   <descam_d@epitech.net>
** 
** Started on  Fri Jun  5 17:24:10 2015 Corentin Descamps
** Last update Sun Jun  7 22:06:27 2015 Corentin Descamps
*/

#include	<stdlib.h>
#include	<gtk/gtk.h>
#include	"object.h"
#include	"save.h"
#include	"color.h"

static void		save_cons(GtkWidget **Entry, t_obj *tmp)
{
  tmp->bril= atoi(gtk_entry_get_text(GTK_ENTRY(Entry[0])));
  tmp->spec = atoi(gtk_entry_get_text(GTK_ENTRY(Entry[1])));
  tmp->trans = atoi(gtk_entry_get_text(GTK_ENTRY(Entry[2])));
  tmp->ref = atoi(gtk_entry_get_text(GTK_ENTRY(Entry[3])));
}

void		save_cone(GtkWidget *Widget, gpointer data)
{
  t_wid		*wid;
  t_obj		tmp;

  (void)Widget;
  wid = (t_wid*)data;
  tmp.type = CONE;
  save_all_pos(wid, &tmp);
  save_cons(wid->entry_cons, &tmp);
  save_color(wid, tmp.rgb);
  stack_obj(&tmp);
  gtk_widget_destroy(wid->win);
}
