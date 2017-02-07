/*
** my_sender.c for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Sat May 30 00:48:09 2015 Adrien Vasseur
** Last update Sun Jun  7 15:19:35 2015 Adrien Vasseur
*/

#include	<stdlib.h>
#include	"my.h"
#include	"net/my_sender.h"

unsigned int	net_pos_list(t_list_pos *list, int fd, int send)
{
  unsigned int	size;

  size = 0;
  while (list != NULL)
    {
      size++;
      if (send == 1)
	write(fd, list, sizeof(*list));
      list = list->next;
    }
  return (size);
}

unsigned int	net_tri_list(t_triangle *list, int fd, int send)
{
  unsigned int	size;

  size = 0;
  while (list != NULL)
    {
      size++;
      if (send == 1)
	write(fd, list, sizeof(*list));
      list = list->next;
    }
  return (size);
}

unsigned int	net_lux_list(t_lux *list, int fd, int send)
{
  unsigned int	size;

  size = 0;
  while (list != NULL)
    {
      size++;
      if (send == 1)
	write(fd, list, sizeof(*list));
      list = list->next;
    }
  return (size);
}

unsigned int	net_obj_list(t_obj *list, int fd, int send)
{
  unsigned int	size;

  size = 0;
  while (list != NULL)
    {
      size++;
      if (send == 1)
	write(fd, list, sizeof(*list));
      list = list->next;
    }
  return (size);
}
