/*
** fc_base.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer/parsing_rt
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Tue Mar 17 11:40:09 2015 Antoine Zanardi
** Last update Mon Mar 30 10:04:40 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"fc_base.h"
#include	"fc_str.h"

unsigned int	my_strlen(char *str)
{
  unsigned int	compt_str;

  compt_str = 0;
  if (str == NULL)
    return (0);
  while (str[compt_str] != '\0')
    compt_str++;
  return (compt_str);
}

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		my_putstr(char *str)
{
  int		compt_str;

  compt_str = 0;
  while (str[compt_str] != '\0')
    {
      my_putchar(str[compt_str]);
      compt_str++;
    }
}

void		next_line(char *str, int *compt_str, int *line)
{
  pass_line(str, compt_str, line);
  pass_void(str, compt_str, line);
}
