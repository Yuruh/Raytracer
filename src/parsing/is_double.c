/*
** is_double.c for rt in /home/zanard_a/rendu/Projets_TEK1/tests
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Thu May  7 15:25:18 2015 Antoine Zanardi
** Last update Thu May 28 21:44:53 2015 Raphael Thiebault
*/

#include	"is_double.h"

int		is_double_posi(char *str)
{
  int		compt_str;

  compt_str = 0;
  if (str[compt_str] == '-')
    compt_str++;
  if (!(str[compt_str] >= '0' && str[compt_str] <= '9'))
    return (1);
  while (str[compt_str] >= '0' && str[compt_str] <= '9')
    compt_str++;
  if (str[compt_str] == '\0' || str[compt_str] == '\t' ||
      str[compt_str] == '\n' || str[compt_str] == '\r' ||
      str[compt_str] == ' ')
    return (0);
  if (str[compt_str] != '.' ||
      (!(str[++compt_str] >= '0' && str[compt_str] <= '9')))
    return (1);
  while (str[compt_str] != ' ' && str[compt_str] != '\t' &&
	 str[compt_str] && str[compt_str] != '\n' &&
	 str[compt_str] != '\r')
    {
      if (!(str[compt_str] >= '0' && str[compt_str] <= '9'))
	return (1);
      compt_str++;
    }
  return (0);
}

int		is_double(char *str)
{
  int		compt_str;

  compt_str = 0;
  if (str[compt_str] && str[compt_str] == '-')
    compt_str++;
  if (!(str[compt_str] >= '0' && str[compt_str] <= '9'))
    return (1);
  while (str[compt_str] >= '0' && str[compt_str] <= '9')
    compt_str++;
  if (str[compt_str] == '\0' || str[compt_str] == '\t' ||
      str[compt_str] == '\n' || str[compt_str] == '\r' ||
      str[compt_str] == ' ')
    return (0);
  if (str[compt_str] != '.' ||
      (!(str[++compt_str] >= '0' && str[compt_str] <= '9')))
    return (1);
  while (str[compt_str] != ' ' && str[compt_str] != '\t' &&
	 str[compt_str] && str[compt_str] != '\n' &&
	 str[compt_str] != '\r')
    {
      if (!(str[compt_str] >= '0' && str[compt_str] <= '9'))
	return (1);
      compt_str++;
    }
  return (0);
}
