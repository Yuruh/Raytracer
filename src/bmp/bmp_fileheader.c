/*
** bmp_fileheader.c for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer/pas_touche_vasseu_g_tests
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Wed Mar 18 22:06:42 2015 Adrien Vasseur
** Last update Thu May  7 23:20:47 2015 Adrien Vasseur
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"bmp/bmp.h"
#include	"bmp/bmp_fileheader.h"
#include	"bmp/bmp_utils.h"

unsigned int	bmp_get_fileheader_size(void)
{
  return (2 + 4 + 4 + 4);
}

int		bmp_write_fileheader(int fd, t_bmp_fileheader *data)
{
  if (data == NULL)
    return (EXIT_FAILURE);
  if (write(fd, data->magic.m_char, 2) == -1)
    return (my_bmp_error("Error : unable to write to output file\n"));
  if (write(fd, data->file_size.m_char, 4) == -1)
    return (my_bmp_error("Error : unable to write to output file\n"));
  if (write(fd, data->reserved.m_char, 4) == -1)
    return (my_bmp_error("Error : unable to write to output file\n"));
  if (write(fd, data->offset.m_char, 4) == -1)
    return (my_bmp_error("Error : unable to write to output file\n"));
  return (EXIT_SUCCESS);
}

static int	correct_bmp_fileheader(t_bmp_fileheader *data)
{
  if (data->magic.m_int != BMP_MAGIC_NUMBER)
    return (my_bmp_error("Error : not a bmp file\n"));
  if (data->file_size.m_int <= 0)
    return (my_bmp_error("Error : not a correct file size\n"));
  if (data->offset.m_int <= 0)
    return (my_bmp_error("Error : not a correct header offset\n"));
  return (EXIT_SUCCESS);
}

int		bmp_read_fileheader(int fd, t_bmp_fileheader *data)
{
  if (data == NULL)
    return (EXIT_FAILURE);
  data->magic.m_int = 0;
  if (read(fd, data->magic.m_char, 2) != 2)
    return (my_bmp_error("Error : not a correct bmp file\n"));
  if (read(fd, data->file_size.m_char, 4) != 4)
    return (my_bmp_error("Error : not a correct bmp file\n"));
  if (read(fd, data->reserved.m_char, 4) != 4)
    return (my_bmp_error("Error : not a correct bmp file\n"));
  if (read(fd, data->offset.m_char, 4) != 4)
    return (my_bmp_error("Error : not a correct bmp file\n"));
  return (correct_bmp_fileheader(data));
}
