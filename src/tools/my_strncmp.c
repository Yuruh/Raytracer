/*
** my_strncmp.c for rt in /home/thieba_r/Documents/IGRAPH/MUL_2014_rtracer
** 
** Made by Raphael Thiebault
** Login   <thieba_r@epitech.net>
** 
** Started on  Thu May 28 15:52:30 2015 Raphael Thiebault
** Last update Fri May 29 11:57:06 2015 Raphael Thiebault
*/

#include	"fc_base.h"

int		my_strncmp_on_s1(char *s1, char *s2)
{
  int		i;
  int		nb;

  i = -1;
  nb = my_strlen(s1);
  while (++i < nb && s1[i] && s2[i])
    if (s1[i] != s2[i])
      return (-1);
  if (i < nb)
    return (-1);
  if (s2[i] != '\0' && s2[i] != '\r' && s2[i] != '\n' &&
      s2[i] != '\t' && s2[i] != ' ')
    return (1);
  return (0);
}
