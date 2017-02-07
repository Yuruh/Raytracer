/*
** my_lib.c for rtv1 in /home/lemper_a/rendu/igraph/MUL_2015_rtv1
**
** Made by Antoine LEMPEREUR
** Login   <lemper_a@epitech.net>
**
** Started on  Mon Feb  2 11:39:20 2015 Antoine LEMPEREUR
** Last update Thu May  7 18:03:59 2015 Adrien Vasseur
*/

#include	<stdlib.h>
#include	"my.h"
#include	"fc_base.h"
#include	"my_lib.h"

int		my_exit(char *s)
{
  my_putstr(s);
  exit(EXIT_FAILURE);
}
