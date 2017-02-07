/*
** recvresult.c for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Fri Jun  5 00:34:25 2015 Adrien Vasseur
** Last update Sun Jun  7 17:02:49 2015 Adrien Vasseur
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"my.h"
#include	"net/define_client.h"
#include	"net/define_packet.h"
#include	"net/packets/recvresult.h"

static t_task	*read_task(char **buff)
{
  t_task	*result;

  result = (t_task *) (*buff);
  (*buff) += sizeof(result->id) + sizeof(result->pt) * 2;
  return (result);
}

static void	write_data(t_task *task, t_data *data, char *buff)
{
  int		x;
  int		y;
  int		i;
  int		j;
  t_blur	*tmp;

  y = task->pt.y - 1;
  j = 0;
  while (++y < task->pt.y + task->size.y)
    {
      i = y * data->win.size_line + task->pt.x * data->win.bpp / 8;
      x = i + data->win.bpp / 8 * task->size.x;
      while (i < x)
	data->win.data[data->count_img][i++] = buff[j++];
      x = task->pt.x + task->size.x;
      i = task->pt.x;
      while (i < x)
	{
	  tmp = (t_blur *) (&(buff[j]));
	  data->blur[y][i++] = *tmp;
	  j += sizeof(t_blur);
	}
    }
  mlx_put_image_to_window(data->win.mlx, data->win.win,
			  data->win.img[data->count_img], 0, 0);
}

int		recvresult(t_client *client, t_packet *packet)
{
  t_task	*task;
  char		*data;

  data = packet->data;
  printf("[INFO] Task result received!\n");
  task = read_task(&data);
  write_data(task, client->scenes->data, data);
  return (EXIT_SUCCESS);
}
