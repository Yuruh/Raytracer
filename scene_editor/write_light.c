/*
** write_light.c for rt in /home/descam_d/rendu/IGRAPH/MUL_2014_rtracer/scene_editor
** 
** Made by Corentin Descamps
** Login   <descam_d@epitech.net>
** 
** Started on  Sun Jun  7 21:34:06 2015 Corentin Descamps
** Last update Sun Jun  7 21:51:15 2015 Corentin Descamps
*/

#include	<stdlib.h>
#include	<gtk/gtk.h>
#include	"object.h"
#include	"color.h"
#include	"writer.h"

extern	t_light	*g_light;

void		write_light(FILE *file)
{
  t_light	*tmp;

  tmp = g_light;
  while (tmp)
    {
      fprintf(file, "<DEF>\nFORM: LIGHT\n");
      fprintf(file, "POS: X = %d Y = %d Z = %d\n",
	      tmp->pos.x, tmp->pos.y, tmp->pos.z);
      write_color(file, tmp->rgb);
      fprintf(file, "</DEF>\n");
      tmp = tmp->next;
    }
}
