/*
** realloc.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Mon Mar 30 09:23:30 2015 Antoine Zanardi
** Last update Wed May 27 12:05:04 2015 Corentin Descamps
*/

#include	<stdlib.h>
#include	"my.h"
#include	"my_realloc.h"
#include	"error_parsing.h"
#include	"fc_base.h"
#include	"my_free.h"

void		init_realloc(int *compt_str, int *compt_dest, int *compt_final)
{
  *compt_str = 0;
  *compt_final = 0;
  *compt_dest = 0;
}

char		*my_realloc(char *str, char *final)
{
  int		compt_final;
  int		compt_dest;
  int		compt_str;
  char		*dest;

  init_realloc(&compt_str, &compt_dest, &compt_final);
  if (!(dest = malloc(sizeof(char) * (my_strlen(str) + my_strlen(final) + 1))))
    my_putstr_error('b', 0, 0);
  if (final != NULL)
    while (final[compt_final] != '\0')
      {
	dest[compt_dest] = final[compt_final];
	compt_dest++;
	compt_final++;
      }
  while (str[compt_str] != '\0')
    {
      dest[compt_dest] = str[compt_str];
      compt_dest++;
      compt_str++;
    }
  dest[compt_dest] = '\0';
  free_str(final);
  return (dest);
}
