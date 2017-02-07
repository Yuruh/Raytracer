/*
** sendscene.c for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Thu May 28 17:41:23 2015 Adrien Vasseur
** Last update Sun Jun  7 15:32:27 2015 Adrien Vasseur
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"my.h"
#include	"net/define_client.h"
#include	"net/define_packet.h"
#include	"net/my_packet.h"
#include	"net/my_sender.h"
#include	"net/my_texture.h"
#include	"net/packets/sendscene.h"

static unsigned int	get_size(t_data *data)
{
  unsigned int		size;
  t_obj			*obj;

  size = sizeof(*data);
  size += sizeof(unsigned int);
  size += sizeof(t_list_pos) * net_pos_list(data->list_pos, 0, 0);
  size += sizeof(unsigned int);
  obj = data->obj;
  while (obj != NULL)
    {
      size += sizeof(*obj);
      size += net_tex_list(data->obj, obj, 0, 0);
      size += sizeof(unsigned int);
      size += sizeof(t_list_pos) * net_pos_list(obj->list_pos, 0, 0);
      size += sizeof(unsigned int);
      size += sizeof(t_triangle) * net_tri_list(obj->triangle, 0, 0);
      obj = obj->next;
    }
  size += sizeof(unsigned int);
  size += sizeof(t_lux) * net_lux_list(data->lux, 0, 0);
  return (size);
}

static void	send_data(t_data *data, int fd)
{
  unsigned int		size;
  t_obj			*obj;

  write(fd, data, sizeof(*data));
  size = net_pos_list(data->list_pos, 0, 0);
  write(fd, &size, sizeof(unsigned int));
  net_pos_list(data->list_pos, fd, 1);
  size = net_obj_list(data->obj, 0, 0);
  write(fd, &size, sizeof(unsigned int));
  obj = data->obj;
  while (obj != NULL)
    {
      write(fd, obj, sizeof(*obj));
      net_tex_list(data->obj, obj, fd, 1);
      size = net_pos_list(obj->list_pos, 0, 0);
      write(fd, &size, sizeof(unsigned int));
      net_pos_list(obj->list_pos, fd, 1);
      size = net_tri_list(obj->triangle, 0, 0);
      write(fd, &size, sizeof(unsigned int));
      net_tri_list(obj->triangle, fd, 1);
      obj = obj->next;
    }
  size = net_lux_list(data->lux, 0, 0);
  write(fd, &size, sizeof(unsigned int));
  net_lux_list(data->lux, fd, 1);
}

int		sendscene(t_client *client)
{
  t_packet	pack;

  pack.id.m_int[0] = SENDSCENE_MESSAGE;
  pack.size.m_int[0] = get_size(client->scenes->data);
  printf("[INFO] Uploading %d bytes to server...\n", pack.size.m_int[0]);
  write(client->my_socket, &(pack.id.m_char[0]), 1);
  write(client->my_socket, &(pack.size.m_char[0]), 4);
  send_data(client->scenes->data, client->my_socket);
  return (EXIT_SUCCESS);
}
