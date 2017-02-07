/*
** bmp_utils.c for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer/pas_touche_vasseu_g_tests
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Wed Mar 18 21:51:28 2015 Adrien Vasseur
** Last update Wed Mar 18 22:00:10 2015 Adrien Vasseur
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"bmp/bmp_utils.h"

unsigned int	my_bmp_strlen(char *str)
{
  unsigned int	i;

  if (str == NULL)
    return (0);
  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

int		my_bmp_error(char *str)
{
  write(2, str, my_bmp_strlen(str));
  return (EXIT_FAILURE);
}
