/*
** error_parsing.c for ret in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer/parsing_rt
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Tue Mar 17 11:24:36 2015 Antoine Zanardi
** Last update Mon Jun  1 17:11:06 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my.h"
#include	"parsing_rt.h"
#include	"my_put_nbr.h"
#include	"object.h"
#include	"fc_base.h"
#include	"error_parsing.h"
#include	"error_obj.h"
#include	"error_video.h"

void		error_type_3(char type)
{
  if (type == 'w')
    my_putstr(" [XPM ID is not declared in a define].\n");
  else if (type == 'x')
    my_putstr(" [Distorsion value has to be -100 <= X <= 100 and != 0].\n");
  if (type == 'y')
    my_putstr(" [Video ID is not declared in a define].\n");
  else if (type == 'z')
    my_putstr(" [Bad ID for video. It has to be positive].\n");
  else if (type == 'A')
    my_putstr(" [Not a correct value for time (X > 0)].\n");
  else if (type == 'B')
    my_putstr(" [Not a correct sheet mod (1 leef or 2)].\n");
  else
    my_putstr(" [Unknown error].\n");
}

void		error_type_2(char type)
{
  if (type == 'l')
    my_putstr(" [Unknown define].\n");
  else if (type == 'm')
    my_putstr(" [Anti_aliasing needs a positive integer (1 / 2 / 4)].\n");
  else if (type == 'n')
    my_putstr(" [Multiple define for the same setting].\n");
  else if (type == 'o')
    my_putstr(" [Too much parameters for this define].\n");
  else if (type == 'p')
    my_putstr(" [Width needs a positive integer].\n");
  else if (type == 'q')
    my_putstr(" [Height needs a positive integer].\n");
  else if (type == 'r')
    my_putstr(" [Obj_file_name is missing].\n");
  else if (type == 's')
    my_putstr(" [Focus mode incorrect. '0' or '1' is expected].\n");
  else if (type == 't')
    my_putstr(" [Bad ID for obj. It has to be positive].\n");
  else if (type == 'u')
    my_putstr(" [Size has to be a percent > 0%].\n");
  else if (type == 'v')
    my_putstr(" [Bad ID for xpm. It has to be positive].\n");
  else
    error_type_3(type);
}

void		error_type(char type)
{
  if (type == 'a')
    my_putstr(" [Bad <DEF></DEF> declaration].\n");
  else if (type == 'b')
    my_putstr(" [Too many parameters].\n");
  else if (type == 'c')
    my_putstr(" [Multiple definition of the same parameter].\n");
  else if (type == 'd')
    my_putstr(" [No form/light/view set for this definition].\n");
  else if (type == 'e')
    my_putstr(" [Unknown form].\n");
  else if (type == 'f')
    my_putstr(" [No position set for this definition].\n");
  else if (type == 'g')
    my_putstr(" [Bad declaration of position].\n");
  else if (type == 'h')
    my_putstr(" [Not a valid number].\n");
  else if (type == 'i')
    my_putstr(" [Not a valid hexadecimal value].\n");
  else if (type == 'j')
    my_putstr(" [Not a valid percent value].\n");
  else if (type == 'k')
    my_putstr(" [Unknown setting].\n");
  else
    error_type_2(type);
}

int		my_putstr_error(char error, int line, char type)
{
  if (error == 'a')
    my_putstr("Raytracer needs a file to run. Try --help or --config\n");
  else if (error == 'b')
    my_putstr("Couldn't perform malloc.\n");
  else if (error == 'c')
    {
      my_putstr("Syntax error [config file] on line n°");
      my_put_nbr(line);
      error_type(type);
    }
  else if (error == 'd')
    {
      my_putstr("Syntax error [obj file] on line n°");
      my_put_nbr(line);
      error_obj(type);
    }
  else if (error == 'e')
    {
      my_putstr("Syntax error [video file] on line n°");
      my_put_nbr(line);
      error_video(type);
    }
  exit(1);
}
