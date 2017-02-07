/*
** recvscene.c for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Wed Jun  3 18:00:05 2015 Adrien Vasseur
** Last update Sun Jun  7 00:44:19 2015 Adrien Vasseur
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"my.h"
#include	"init.h"
#include	"my_lib.h"
#include	"net/define_client.h"
#include	"net/define_packet.h"
#include	"net/my_reader.h"
#include	"net/my_scene.h"
#include	"net/my_calculator.h"
#include	"net/packets/asktask.h"
#include	"net/packets/recvscene.h"

static size_t	get_scene_id(char **buff)
{
  t_write_data	data;
  char		*read;
  size_t	i;

  data.m_long = 0;
  i = 0;
  read = (*buff);
  while (i < sizeof(size_t))
    {
      data.m_char[i] = read[0];
      i++;
      read++;
    }
  (*buff) = read;
  return (data.m_long);
}

static int	my_init(t_data *d)
{
  d->count_img = 0;
  d->has_win = 0;
  if ((d->win.mlx = mlx_init()) == NULL)
    my_exit("I need the environment!\n");
  if ((d->win.data = malloc(sizeof(*(d->win.data)))) == NULL)
    return (EXIT_FAILURE);
  if ((d->win.img = malloc(sizeof(*(d->win.img)))) == NULL)
    return (EXIT_FAILURE);
  if ((d->win.img[0] = mlx_new_image(d->win.mlx, d->width, d->height)) == NULL)
    return (EXIT_FAILURE);
  if ((d->win.data[0] = mlx_get_data_addr(d->win.img[0], &(d->win.bpp),
					  &(d->win.size_line),
					  &(d->win.endian))) == NULL)
    return (EXIT_FAILURE);
  if ((d->do_inter = malloc(sizeof(*d->do_inter) * 12)) == NULL)
    return (EXIT_FAILURE);
  if ((d->do_norm = malloc(sizeof(*d->do_norm) * 12)) == NULL)
    return (EXIT_FAILURE);
  if ((d->do_shdw = malloc(sizeof(*d->do_shdw) * 12)) == NULL)
    return (EXIT_FAILURE);
  list_inter(d->do_inter);
  list_norm(d->do_norm);
  list_shdw(d->do_shdw);
  return (EXIT_SUCCESS);
}

int		recvscene(t_client *client, t_packet *packet)
{
  t_data	*data;
  size_t	id;
  char		*buff;

  buff = packet->data;
  id = get_scene_id(&buff);
  printf("[INFO] New scene [%ld] downloaded!\n", id);
  data = (t_data *) buff;
  buff += sizeof(*data);
  if (my_init(data) == EXIT_FAILURE)
    my_exit("[ERROR] Unable to create mlx environment!\n");
  data->blur = get_blur_tab(data->width, data->height);
  data->list_pos = net_pos_read(&buff);
  data->obj = net_obj_read(&buff);
  data->lux = net_lux_read(&buff);
  if (net_add_scene(&(client->scenes), id, data) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  my_calculator(client);
  return (asktask(client->my_socket));
}
