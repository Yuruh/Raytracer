/*
** comments.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer/parsing
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Mon Mar 23 15:53:09 2015 Antoine Zanardi
** Last update Wed May 27 14:39:34 2015 Corentin Descamps
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"my.h"
#include	"error_parsing.h"
#include	"pass_x.h"
#include	"fc_str.h"
#include	"fc_base.h"
#include	"comments.h"
#include	"my_free.h"

int		comment_len(char *str)
{
  int		compt_str;
  int		len;

  compt_str = 0;
  len = 0;
  pass_spaces(str, &compt_str);
  while (str[compt_str] != '\0')
    {
      if (str[compt_str] == '#')
	{
	  while (str[compt_str] != '\n' && str[compt_str] != '\0')
	    compt_str++;
	}
      if (str[compt_str] != '\0')
	compt_str++;
      len++;
    }
  return (len);
}

char		*erase_comment(char *str)
{
  char		*dest;
  int		compt_str;
  int		compt_dest;

  compt_str = 0;
  compt_dest = 0;
  if ((dest = malloc(sizeof(char) *
		     ((unsigned long)comment_len(str) + 1))) == NULL)
    my_putstr_error(2, 0, 0);
  while (str[compt_str] != '\0')
    {
      if (str[compt_str] == '#')
	while (str[compt_str] != '\n' && str[compt_str] != '\0')
	  compt_str++;
      dest[compt_dest] = str[compt_str];
      if (str[compt_str] != '\0')
	{
	  compt_dest++;
	  compt_str++;
	}
    }
  dest[compt_dest] = '\0';
  free_str(str);
  return (dest);
}
