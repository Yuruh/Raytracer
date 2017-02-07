/*
** error_video.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Mon May 18 23:11:19 2015 Antoine Zanardi
** Last update Tue May 26 13:58:42 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"fc_base.h"
#include	"fc_str.h"
#include	"error_video.h"

static void	error_video_2(char type)
{
  if (type == 'i')
    my_putstr(" [Uknown parameter].\n");
  else if (type == 'j')
    my_putstr(" [The ratios are not equals to 100%].\n");
  else if (type == 'k')
    my_putstr(" [A translation has to be set].\n");
  else if (type == 'l')
    my_putstr(" [A rotation has to be set].\n");
  else if (type == 'm')
    my_putstr(" [Bad declaration for a rotation centrale].\n");
}

void		error_video(char type)
{
  if (type == 'a')
    my_putstr(" [Bad <VID></VID>].\n");
  else if (type == 'b')
    my_putstr(" [Too many parameters.]\n");
  else if (type == 'c')
    my_putstr(" [Bad percent value].\n");
  else if (type == 'd')
    my_putstr(" [Multiple definition of the same parameter].\n");
  else if (type == 'e')
    my_putstr(" [Time that takes the movement is missing].\n");
  else if (type == 'f')
    my_putstr(" [Bad declaration for a position].\n");
  else if (type == 'g')
    my_putstr(" [Not a valid number].\n");
  else if (type == 'h')
    my_putstr(" [Bad declaration for a rotation].\n");
  else
    error_video_2(type);
}
