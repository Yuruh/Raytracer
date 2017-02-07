/*
** cut_str.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer/parsing_rt
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Tue Mar 17 14:56:37 2015 Antoine Zanardi
** Last update Sun Jun  7 19:47:27 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"my.h"
#include	"error_parsing.h"
#include	"cut_str.h"
#include	"fc_base.h"

unsigned int	label_len(char *str, int compt_str)
{
  unsigned int	len;

  len = 0;
  if (str == NULL)
    my_putstr_error('b', 0, 0);
  while (str[compt_str] != ' ' && str[compt_str] != '\t' &&
	 str[compt_str] != '\0' && str[compt_str] != '\n')
    {
      len++;
      compt_str++;
    }
  return (len);
}

char		*my_strdup(char *str, int compt_str)
{
  int		compt_dest;
  char		*dest;

  compt_dest = 0;
  if (str == NULL)
    my_putstr_error('b', 0, 0);
  if ((dest = malloc(sizeof(char) * label_len(str, compt_str) + 1)) == NULL)
    my_putstr_error('b', 0, 0);
  while (str[compt_str] != ' ' && str[compt_str] != '\t' &&
	 str[compt_str] != '\0' && str[compt_str] != '\n' &&
	 str[compt_str] != '\r')
    {
      dest[compt_dest] = str[compt_str];
      compt_str++;
      compt_dest++;
    }
  dest[compt_dest] = '\0';
  return (dest);
}

char		*my_strcat(char *str, char *str2)
{
  char		*dest;
  unsigned int	compt_str;
  unsigned int	compt_dest;

  compt_str = 0;
  compt_dest = 0;
  if (str == NULL || str2 == NULL)
    my_putstr_error('b', 0, 0);
  if ((dest = malloc(sizeof(char) * (my_strlen(str) +
				     my_strlen(str2) + 1))) == NULL)
    my_putstr_error('b', 0, 0);
  while (str[compt_str] != '\0')
    {
      dest[compt_dest] = str[compt_str++];
      compt_dest++;
    }
  compt_str = 0;
  while (str2[compt_str] != '\0')
    {
      dest[compt_dest] = str2[compt_str++];
      compt_dest++;
    }
  dest[compt_dest] = '\0';
  return (dest);
}
