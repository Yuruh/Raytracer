/*
** bmp_content.c for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer/pas_touche_vasseu_g_tests
**
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
**
** Started on  Mon Mar 23 11:45:58 2015 Adrien Vasseur
** Last update Thu May 21 17:16:30 2015 Antoine LEMPEREUR
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"mlx.h"
#include	"mlx_int.h"
#include	"windata.h"
#include	"bmp/bmp.h"
#include	"bmp/bmp_content.h"
#include	"bmp/bmp_utils.h"

unsigned int	bmp_get_content_size(t_data *d)
{
  unsigned int	rowsize;
  unsigned int	size;

  rowsize = (24 * (unsigned int)d->width + 31) / 32 * 4;
  size = rowsize * (unsigned int)d->height;
  return (size);
}

static void	write_pixel(int fd, char *data)
{
  write(fd, &(data[0]), 1);
  write(fd, &(data[1]), 1);
  write(fd, &(data[2]), 1);
}

static int	read_pixel(int fd, char *data)
{
  if (read(fd, &(data[0]), 1) != 1)
    return (EXIT_FAILURE);
  if (read(fd, &(data[1]), 1) != 1)
    return (EXIT_FAILURE);
  if (read(fd, &(data[2]), 1) != 1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int		bmp_write_content(int fd, t_win *data, t_data *d)
{
  int		x;
  int		y;
  int		i;
  int		j;
  int		row;

  y = H - 1;
  row = ((24 * W + 31) / 32) * 4;
  j = row - ((row / 3) * 3);
  while (y >= 0)
    {
      x = 0;
      while (x < row / 3)
	{
	  i = y * data->size_line + x * data->bpp / 8;
	  write_pixel(fd, &(data->data[0][i]));
	  x++;
	}
      x = -1;
      while (++x < j)
	write(fd, NULL, 1);
      y--;
    }
  return (EXIT_SUCCESS);
}

int		bmp_read_content(int fd, char *data, t_img *img)
{
  int		x;
  int		y;
  int		i;
  int		j;
  int		row;

  y = img->height - 1;
  row = ((24 * img->width + 31) / 32) * 4;
  j = row - ((row / 3) * 3);
  while (y >= 0)
    {
      x = 0;
      while (x < row / 3)
	{
	  i = y * img->size_line + x * img->bpp / 8;
	  if (read_pixel(fd, &(data[i])) != EXIT_SUCCESS)
	    return (EXIT_FAILURE);
	  x++;
	}
      lseek(fd, j, SEEK_CUR);
      y--;
    }
  return (EXIT_SUCCESS);
}
