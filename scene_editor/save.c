/*
** save.c for rt in /home/descam_d/rendu/IGRAPH/MUL_2014_rtracer/scene_editor
** 
** Made by Corentin Descamps
** Login   <descam_d@epitech.net>
** 
** Started on  Thu Jun  4 14:02:37 2015 Corentin Descamps
** Last update Fri Jun  5 15:19:33 2015 Corentin Descamps
*/

#include	<stdlib.h>
#include	<gtk/gtk.h>
#include	<string.h>
#include	"object.h"

void		save_pos(GtkWidget **Entry, t_pos *pos)
{
  pos->x = atoi(gtk_entry_get_text(GTK_ENTRY(Entry[0])));
  pos->y = atoi(gtk_entry_get_text(GTK_ENTRY(Entry[1])));
  pos->z = atoi(gtk_entry_get_text(GTK_ENTRY(Entry[2])));
}

void		save_all_pos(t_wid *wid, t_obj *tmp)
{
  save_pos(wid->entry_pos, &tmp->pos);
  save_pos(wid->entry_rot, &tmp->rot);
  save_pos(wid->entry_hlim, &tmp->h_lim);
  save_pos(wid->entry_blim, &tmp->b_lim);
}
