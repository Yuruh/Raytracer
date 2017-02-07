/*
** write_color.c for  in /home/descam_d/rendu/IGRAPH/MUL_2014_rtracer/scene_editor
** 
** Made by Corentin Descamps
** Login   <descam_d@epitech.net>
** 
** Started on  Sun Jun  7 16:18:03 2015 Corentin Descamps
** Last update Sun Jun  7 22:10:45 2015 Corentin Descamps
*/

#include	<stdlib.h>
#include	<gtk/gtk.h>
#include	<stdio.h>
#include	<string.h>
#include	"define.h"
#include	"object.h"
#include	"verif.h"

void		my_putnbr_hexa(FILE *file, unsigned char nb)
{
  if (nb >= 16)
    {
      my_putnbr_hexa(file, nb / 16);
      if (nb % 16 <= 9)
	fprintf(file, "%c", (nb % 16 + 48));
      else if (nb % 16 >= 10)
	fprintf(file, "%c", (nb % 16 + 55));
    }
  else if (nb <= 9)
    fprintf(file, "%c", (nb + 48));
  else if (nb >= 10 && nb <= 15)
    fprintf(file, "%c", (nb + 55));
}

void		write_color(FILE *file, unsigned char rgb[3])
{
  int		i;

  i = 0;
  fprintf(file, "COLOR: 0x");
  while (i < 3)
    {
      if (rgb[i] < 16)
	fprintf(file, "0");
      my_putnbr_hexa(file, rgb[i]);
      i++;
    }
  fprintf(file, "\n");
}
