/*
** writer.c for rt in /home/descam_d/rendu/IGRAPH/MUL_2014_rtracer/scene_editor
** 
** Made by Corentin Descamps
** Login   <descam_d@epitech.net>
** 
** Started on  Tue Jun  2 16:02:56 2015 Corentin Descamps
** Last update Sun Jun  7 21:40:04 2015 Corentin Descamps
*/

#include	<stdlib.h>
#include	<gtk/gtk.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<string.h>
#include	"define.h"
#include	"object.h"
#include	"verif.h"
#include	"writer.h"

extern	t_obj	*g_obj;
extern	t_def	g_def;
extern	t_view	g_view;

void		write_type(FILE *file, t_obj *tmp)
{
  if (tmp->type == SPHERE)
    fprintf(file, "FORM: SPHERE\n");
  else if (tmp->type == PLAN)
    fprintf(file, "FORM: PLAN\n");
  else if (tmp->type == CONE)
    fprintf(file, "FORM: CONE\n");
  else if (tmp->type == CYLINDRE)
    fprintf(file, "FORM: CYLINDRE\n");
}

void		write_cons(FILE *file, t_obj *tmp)
{
  if (tmp->type == SPHERE)
    fprintf(file, "RAYON: %d\n", tmp->rayon);
  fprintf(file, "BRILLANCE: %d%%\n", tmp->bril);
  fprintf(file, "SPECULARITE: %d%%\n", tmp->spec);
  fprintf(file, "TRANSPARENCE: %d%%\n", tmp->trans);
  fprintf(file, "REFLEXION: %d%%\n", tmp->ref);
}

void		write_obj(FILE *file, t_obj *tmp)
{
  fprintf(file, "<DEF>\n");
  write_type(file, tmp);
  fprintf(file, "POS: X = %d Y = %d Z = %d\n",
	  tmp->pos.x, tmp->pos.y, tmp->pos.z);
  fprintf(file, "ROTATE: X = %d Y = %d Z = %d\n",
	  tmp->rot.x, tmp->rot.y, tmp->rot.z);
  if (verif_lim(&tmp->h_lim) == EXIT_SUCCESS)
    fprintf(file, "H_LIM: X = %d Y = %d Z = %d\n",
	    tmp->h_lim.x, tmp->h_lim.y, tmp->h_lim.z);
  if (verif_lim(&tmp->b_lim) == EXIT_SUCCESS)
    fprintf(file, "B_LIM: X = %d Y = %d Z = %d\n",
	    tmp->b_lim.x, tmp->b_lim.y, tmp->b_lim.z);
  if (tmp->type == CONE)
    fprintf(file, "DISTORSION: 1 1 1\n");
  write_cons(file, tmp);
  write_color(file, tmp->rgb);
  fprintf(file, "</DEF>\n");
}

void		write_view(FILE *file)
{
  fprintf(file, "<DEF>\nFORM: VIEW\n");
  fprintf(file, "POS: X = %d Y = %d Z = %d\n",
	  g_view.pos.x, g_view.pos.y, g_view.pos.z);
  fprintf(file, "ROTATE: X = %d Y = %d Z = %d\n",
	  g_view.rot.x, g_view.rot.y, g_view.rot.z);
  fprintf(file, "</DEF>\n");
}

void		writer(GtkWidget *Widget, gpointer data)
{
  FILE		*file;
  t_obj		*tmp;

  (void)Widget;
  (void)data;
  file = fopen(g_def.filename, "w+");
  fprintf(file, "#define\t\ta_a\t%s\n", g_def.a_a);
  fprintf(file, "#define\t\twidth\t%s\n", g_def.width);
  fprintf(file, "#define\t\theight\t%s\n", g_def.height);
  fprintf(file, "\n");
  write_view(file);
  tmp = g_obj;
  while (tmp)
    {
      write_obj(file, tmp);
      tmp = tmp->next;
    }
  write_light(file);
  gtk_main_quit();
}
