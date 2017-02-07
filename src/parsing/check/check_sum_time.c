/*
** check_sum_time.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Tue May 19 11:26:45 2015 Antoine Zanardi
** Last update Thu May 28 22:58:36 2015 Antoine LEMPEREUR
*/

#include	<stdlib.h>
#include	"my.h"
#include	"object.h"
#include	"error_parsing.h"
#include	"check_sum_time.h"

void		check_sum_time(t_video **list)
{
  t_video	*tmp;
  double	sum;

  tmp = *list;
  sum = 0;
  while (tmp != NULL)
    {
      sum += tmp->ratio;
      tmp = tmp->next;
    }
  if (!(sum > 0.99 && sum < 1.01))
    my_putstr_error('e', 0, 'j');
}
