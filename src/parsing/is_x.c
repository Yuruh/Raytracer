/*
** is_x.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer/parsing_rt
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed Mar 18 10:00:09 2015 Antoine Zanardi
** Last update Thu Jun  4 13:43:07 2015 Raphael Thiebault
*/

#include	"is_x.h"
#include	"my_getnbr.h"

int		is_num_posi(char *str)
{
  int		compt_str;

  compt_str = 0;
  if (!(str[compt_str] >= '0' && str[compt_str] <= '9'))
    return (1);
  while (str[compt_str] != ' ' && str[compt_str] != '\t' &&
	 str[compt_str] && str[compt_str] != '\n' &&
	 str[compt_str] != '\r')
    {
      if (str[compt_str] >= '0' && str[compt_str] <= '9')
	compt_str++;
      else
	return (1);
    }
  return (0);
}

int		is_num(char *str)
{
  int		compt_str;

  compt_str = 0;
  if (str[compt_str] == '-')
    compt_str++;
  if (!(str[compt_str] >= '0' && str[compt_str] <= '9'))
    return (1);
  while (str[compt_str] != ' ' && str[compt_str] != '\t' &&
	 str[compt_str] && str[compt_str] != '\n' &&
	 str[compt_str] != '\r')
    {
      if (str[compt_str] >= '0' && str[compt_str] <= '9')
	compt_str++;
      else
	return (1);
    }
  return (0);
}

int		is_hexa(char *str)
{
  int		compt_str;

  compt_str = 0;
  if (str[compt_str] != '0')
    return (1);
  compt_str++;
  if (str[compt_str] != 'x')
    return (1);
  compt_str++;
  while (str[compt_str] != ' ' && str[compt_str] != '\t' &&
	 str[compt_str] && str[compt_str] != '\n' &&
	 str[compt_str] != '\r' && compt_str < 8)
    {
      if ((str[compt_str] >= '0' && str[compt_str] <= '9') ||
	  (str[compt_str] >= 'A' && str[compt_str] <= 'F'))
	compt_str++;
      else
	return (1);
    }
  if (str[compt_str] != ' ' && str[compt_str] != '\t' &&
      str[compt_str] && str[compt_str] != '\n' &&
      str[compt_str] != '\r')
    return (1);
  return (0);
}

int		is_percent(char *str)
{
  int		compt_str;

  compt_str = 0;
  if (!(str[compt_str] >= '0' && str[compt_str] <= '9'))
    return (1);
  if (my_getnbr(str) > 100 || my_getnbr(str) < 0)
    return (1);
  if (str[compt_str] == '%')
    return (1);
  while (str[compt_str] != ' ' && str[compt_str] != '\t' &&
	 str[compt_str] && str[compt_str] != '\n' &&
	 str[compt_str] != '\r' &&
	 str[compt_str] >= '0' && str[compt_str] <= '9')
    compt_str++;
  if (str[compt_str] && str[compt_str] != '%')
    return (1);
  compt_str++;
  if (str[compt_str] != ' ' && str[compt_str] != '\t' &&
      str[compt_str] && str[compt_str] != '\n' &&
      str[compt_str] != '\r')
    return (1);
  return (0);
}

int		is_percent_size(char *str)
{
  int		compt_str;

  compt_str = 0;
  if (!(str[compt_str] >= '0' && str[compt_str] <= '9'))
    return (1);
  if (my_getnbr(str) <= 0)
    return (1);
  if (str[compt_str] == '%')
    return (1);
  while (str[compt_str] != ' ' && str[compt_str] != '\t' &&
	 str[compt_str] && str[compt_str] != '\n' &&
	 str[compt_str] != '\r' &&
	 str[compt_str] >= '0' && str[compt_str] <= '9')
    compt_str++;
  if (str[compt_str] && str[compt_str] != '%')
    return (1);
  compt_str++;
  if (str[compt_str] != ' ' && str[compt_str] != '\t' &&
      str[compt_str] && str[compt_str] != '\n' &&
      str[compt_str] != '\r')
    return (1);
  return (0);
}
