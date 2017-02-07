/*
** verif.c for rt in /home/descam_d/rendu/IGRAPH/MUL_2014_rtracer/scene_editor
** 
** Made by Corentin Descamps
** Login   <descam_d@epitech.net>
** 
** Started on  Tue Jun  2 14:40:49 2015 Corentin Descamps
** Last update Sat Jun  6 16:33:26 2015 Corentin Descamps
*/

#include	<stdlib.h>
#include	<gtk/gtk.h>
#include	"define.h"
#include	"object.h"

extern	t_def	g_def;

int		verif_lim(t_pos *pos)
{
  if (pos->x == 0 && pos->y == 0 && pos->z == 0)
    return (EXIT_FAILURE);
  else
    return (EXIT_SUCCESS);
}

int		verif_value(int bool)
{
  if (g_def.filename[0] == '\0')
    {
      printf("[ERROR] Veuillez indiquer un nom de fichier\n");
      bool++;
    }
  if (atoi(g_def.a_a) <= 0)
    {
      printf("[ERROR] Veuillez indiquer un anti_aliasing positive\n");
      bool++;
    }
  if (atoi(g_def.width) <= 0)
    {
      printf("[ERROR] Veuillez indiquer une largeur positive\n");
      bool++;
    }
  if (atoi(g_def.height) <= 0)
    {
      printf("[ERROR] Veuillez indiquer une hauteur positive\n");
      bool++;
    }
  if (bool != 0)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
