/*
** my_reader.c for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Wed Jun  3 23:34:45 2015 Adrien Vasseur
** Last update Sun Jun  7 15:33:41 2015 Adrien Vasseur
*/

#include	<stdlib.h>
#include	"my.h"
#include	"net/define_packet.h"
#include	"net/my_texture.h"
#include	"net/my_reader.h"

unsigned int	net_read_uint(char **data)
{
  t_write_data	result;
  size_t	i;
  char		*buff;

  i = 0;
  buff = (*data);
  while (i < sizeof(unsigned int))
    {
      result.m_char[i] = buff[0];
      buff++;
      i++;
    }
  (*data) = buff;
  return (result.m_int[0]);
}

t_list_pos	*net_pos_read(char **data)
{
  t_list_pos	*result;
  t_list_pos	*next;
  t_list_pos	*last;
  unsigned int	size;
  unsigned int	i;

  size = net_read_uint(data);
  i = 0;
  result = NULL;
  last = NULL;
  while (i < size)
    {
      next = (t_list_pos *) (*data);
      (*data) += sizeof(*next);
      next->next = NULL;
      next->prev = last;
      result = (result == NULL) ? next : result;
      if (last != NULL)
	last->next = next;
      last = next;
      i++;
    }
  return (result);
}

t_triangle	*net_tri_read(char **data)
{
  t_triangle	*result;
  t_triangle	*next;
  t_triangle	*last;
  unsigned int	size;
  unsigned int	i;

  size = net_read_uint(data);
  i = 0;
  result = NULL;
  last = NULL;
  while (i < size)
    {
      next = (t_triangle *) (*data);
      (*data) += sizeof(*next);
      next->prev = last;
      result = (result == NULL) ? next : result;
      if (last != NULL)
	last->next = next;
      last = next;
      i++;
    }
  return (result);
}

t_obj		*net_obj_read(char **data)
{
  t_obj		*result;
  t_obj		*next;
  t_obj		*last;
  unsigned int	size;
  unsigned int	i;

  size = net_read_uint(data);
  i = 0;
  result = NULL;
  last = NULL;
  while (i < size)
    {
      next = (t_obj *) (*data);
      (*data) += sizeof(*next);
      net_tex_read(result, next, data);
      next->list_pos = net_pos_read(data);
      next->triangle = net_tri_read(data);
      next->next = NULL;
      result = (result == NULL) ? next : result;
      if (last != NULL)
	last->next = next;
      last = next;
      i++;
    }
  return (result);
}

t_lux		*net_lux_read(char **data)
{
  t_lux		*result;
  t_lux		*next;
  t_lux		*last;
  unsigned int	size;
  unsigned int	i;

  size = net_read_uint(data);
  i = 0;
  result = NULL;
  last = NULL;
  while (i < size)
    {
      next = (t_lux *) (*data);
      (*data) += sizeof(*next);
      next->next = NULL;
      result = (result == NULL) ? next : result;
      if (last != NULL)
	last->next = next;
      last = next;
      i++;
    }
  return (result);
}
