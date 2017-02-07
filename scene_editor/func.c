/*
** func.c for rt in /home/descam_d/rendu/IGRAPH/MUL_2014_rtracer/scene_editor
** 
** Made by Corentin Descamps
** Login   <descam_d@epitech.net>
** 
** Started on  Wed May 27 14:03:45 2015 Corentin Descamps
** Last update Wed May 27 14:04:57 2015 Corentin Descamps
*/

#include	<stdlib.h>

int		my_strlen(char *str)
{
  int		i;

  if (str == NULL)
    return (0);
  i = 0;
  while (str[i])
    i++;
  return (i);
}
