/*
** error_obj.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer/parsing
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Thu Mar 26 11:11:58 2015 Antoine Zanardi
** Last update Thu May 28 20:41:20 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"my.h"
#include	"parsing_rt.h"
#include	"error_obj.h"
#include	"fc_base.h"

int		error_view(char type)
{
  if (type == 'a')
    my_putstr("A point of view has to be set.\n");
  else if (type == 'b')
    my_putstr("Multiple point of view are not allowed.\n");
  else if (type == 'c')
    my_putstr("Some problem with output arguments, check --help.\n");
  else if (type == 'd')
    my_putstr("Two <DEF> of an OBJ have the same ID.\n");
  else if (type == 'e')
    my_putstr("Two define of an OBJ have the same id.\n");
  else if (type == 'f')
    my_putstr("Two define of an XPM have the same id.\n");
  else if (type == 'g')
    my_putstr("An XPM doesn't exist.\n");
  exit(1);
}

void		error_obj(char type)
{
  if (type == 'a')
    my_putstr(" [Bad double value for coordinates].\n");
  else if (type == 'b')
    my_putstr(" [Bad tab construction].\n");
  else if (type == 'c')
    my_putstr(" [Bad double value for normale].\n");
  else if (type == 'd')
    my_putstr(" [Bad double value for texture].\n");
  else if (type == 'e')
    my_putstr(" [Bad tab value].\n");
}

int		error_file(char *name)
{
  my_putstr("File ");
  my_putstr(name);
  my_putstr(" not readable.\n");
  exit(1);
}

int		error_open_file(void)
{
  my_putstr("ERROR opening a file, surely empty.\n");
  exit(1);
}
