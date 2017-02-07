/*
** my_add_client.c for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer/pas_touche_vasseu_g_tests/server
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Mon Mar 30 16:46:11 2015 Adrien Vasseur
** Last update Sun Jun  7 21:52:36 2015 Adrien Vasseur
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"network/define_server.h"
#include	"network/my_add_client.h"

int		my_add_client(t_socket **list, t_socket *new)
{
  t_socket	*tmp;

  printf("[INFO] [%d] New client [%d.%d.%d.%d] is connecting...\n",
	 new->socket,
	 (new->addr.sin_addr.s_addr&0xFF),
	 ((new->addr.sin_addr.s_addr&0xFF00)>>8),
	 ((new->addr.sin_addr.s_addr&0xFF0000)>>16),
	 ((new->addr.sin_addr.s_addr&0xFF000000)>>24));
  new->next = NULL;
  new->state = 0;
  new->buff = NULL;
  new->buff_size = 0;
  new->connected = 1;
  new->all = list;
  if ((*list) == NULL)
    {
      (*list) = new;
      return (EXIT_SUCCESS);
    }
  tmp = (*list);
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new;
  return (EXIT_SUCCESS);
}

int		my_rem_client(t_socket **list, t_socket *rem, t_scene *scene)
{
  t_socket	*tmp;

  printf("[INFO] Disconnecting client...\n");
  while (scene != NULL)
    {
      if (scene->client == rem)
	scene->client = NULL;
      scene = scene->next;
    }
  if ((*list) == rem)
    (*list) = rem->next;
  else
    {
      tmp = (*list);
      while (tmp->next != rem)
	tmp = tmp->next;
      tmp->next = rem->next;
    }
  free(rem->buff);
  free(rem);
  return (EXIT_SUCCESS);
}

int		my_free_client(t_socket **list)
{
  t_socket	*tmp;
  t_socket	*next;

  tmp = (*list);
  while (tmp != NULL)
    {
      next = tmp->next;
      free(tmp);
      tmp = next;
    }
  (*list) = NULL;
  return (EXIT_SUCCESS);
}
