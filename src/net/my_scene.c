/*
** my_scene.c for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Mon Jun  1 18:34:19 2015 Adrien Vasseur
** Last update Mon Jun  1 18:47:02 2015 Adrien Vasseur
*/

#include	<stdlib.h>
#include	"my.h"
#include	"net/define_client.h"
#include	"net/my_scene.h"

int		net_add_scene(t_scene **list, size_t id, t_data *dat)
{
  t_scene	*elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (EXIT_FAILURE);
  elem->id = id;
  elem->data = dat;
  elem->next = (*list);
  (*list) = elem;
  return (EXIT_SUCCESS);
}
