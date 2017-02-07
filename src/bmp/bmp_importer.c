/*
** bmp_importer.c for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer
**
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
**
** Started on  Thu May  7 15:29:31 2015 Adrien Vasseur
** Last update Sun Jun  7 16:21:07 2015 Adrien Vasseur
*/

#include		<stdlib.h>
#include		"my.h"
#include		"mlx_int.h"
#include		"my_lib.h"
#include		"bmp/bmp.h"
#include		"bmp/bmp_utils.h"
#include		"bmp/bmp_fileheader.h"
#include		"bmp/bmp_imgheader.h"
#include		"bmp/bmp_content.h"
#include		"bmp/bmp_importer.h"

static int		input_file(char *filename)
{
  int			fd;

  if ((fd = open(filename, O_RDONLY)) == -1)
    {
      my_bmp_error("Error : unable to read file : ");
      my_bmp_error(filename);
      my_bmp_error("\n");
      my_exit(" ");
    }
  return (fd);
}

static t_img		*force_quit(char *str, int fd)
{
  if (fd != -1)
    close(fd);
  if (str != NULL)
    my_bmp_error(str);
  return (NULL);
}

t_img			*bmp_importer(t_data *data, char *filename)
{
  int			fd;
  t_bmp_fileheader	fileheader;
  t_bmp_imgheader	imgheader;
  t_img			*ret;
  char			*ptr;
  int			tmp;

  if (filename == NULL)
    return (force_quit("Error : bad filename\n", -1));
  if ((fd = input_file(filename)) == -1)
    return (force_quit(NULL, fd));
  if (bmp_read_fileheader(fd, &fileheader) == EXIT_FAILURE)
    return (force_quit(NULL, fd));
  if (bmp_read_imgheader(fd, &imgheader) == EXIT_FAILURE)
    return (force_quit(NULL, fd));
  ret = mlx_new_image(data->win.mlx, (int) imgheader.img_width.m_int,
		      (int) imgheader.img_height.m_int);
  if (ret == NULL)
    return (force_quit(NULL, fd));
  ptr = mlx_get_data_addr(ret, &(tmp), &(tmp), &(tmp));
  lseek(fd, fileheader.offset.m_int, SEEK_SET);
  if (bmp_read_content(fd, ptr, ret) != EXIT_SUCCESS)
    return (force_quit(NULL, fd));
  close(fd);
  return (ret);
}
