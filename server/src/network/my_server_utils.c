/*
** my_server_utils.c for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer/pas_touche_vasseu_g_tests/server
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Tue Mar 24 00:37:10 2015 Adrien Vasseur
** Last update Tue Mar 31 00:33:28 2015 Adrien Vasseur
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"network/my_server_utils.h"

size_t		my_strlen(char *str)
{
  size_t	i;

  if (str == NULL)
    return (0);
  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

int		my_server_error(char *str)
{
  write(2, str, my_strlen(str));
  return (-1);
}

int		my_print_error(char *str)
{
  write(2, str, my_strlen(str));
  return (EXIT_FAILURE);
}
