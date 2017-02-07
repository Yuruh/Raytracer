/*
** comments.c<scene_editor> for rt in /home/descam_d/rendu/IGRAPH/MUL_2014_rtracer/scene_editor
** 
** Made by Corentin Descamps
** Login   <descam_d@epitech.net>
** 
** Started on  Wed May 27 14:32:14 2015 Corentin Descamps
** Last update Wed May 27 15:51:33 2015 Corentin Descamps
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my.h"
#include	"error_parsing.h"
#include	"pass_x.h"
#include	"fc_str.h"
#include	"fc_base.h"
#include	"comments.h"
#include	"my_free.h"
#include	"malloc_error.h"

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
  if (!(dest = malloc(sizeof(char) * comment_len(str) + 1)))
    return (malloc_failed());
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
  free(str);
  return (dest);
}
