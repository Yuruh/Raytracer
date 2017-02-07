/*
** fc_str.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer/parsing_rt
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Tue Mar 17 14:38:58 2015 Antoine Zanardi
** Last update Tue Mar 31 17:11:28 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"fc_str.h"

void		pass_spaces(char *str, int *compt_str)
{
  while ((str[*compt_str] == ' ' || str[*compt_str] == '\t') &&
	 str[*compt_str] != '\0')
    (*compt_str)++;
}

void		pass_void(char *str, int *compt_str, int *line)
{
  while ((str[*compt_str] == ' ' || str[*compt_str] == '\t' ||
	  str[*compt_str] == '\n') && str[*compt_str] != '\0')
    {
      if (str[*compt_str] == '\n' && line != NULL)
	(*line)++;
      (*compt_str)++;
    }
}

void		pass_line(char *str, int *compt_str, int *line)
{
  while (str[*compt_str] != '\n' && str[*compt_str] != '\0')
    (*compt_str)++;
  if (str[*compt_str] == '\n')
    {
      if (line != NULL)
	(*line)++;
      (*compt_str)++;
    }
}

int		my_strcmp_exact(char *str, char *str2, int compt2)
{
  int		compt;

  compt = 0;
  while (str[compt] != '\0')
    {
      if (str2[compt2] == '\0' || str[compt] != str2[compt2])
	return (1);
      else
	{
	  compt++;
	  compt2++;
	}
    }
  if (str[compt] != '\0' || str2[compt2] != '\0')
    return (1);
  return (0);
}
