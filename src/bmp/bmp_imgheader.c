/*
** bmp_imgheader.c for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer/pas_touche_vasseu_g_tests
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Wed Mar 18 22:45:07 2015 Adrien Vasseur
** Last update Thu May  7 23:18:22 2015 Adrien Vasseur
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"bmp/bmp.h"
#include	"bmp/bmp_imgheader.h"
#include	"bmp/bmp_utils.h"

unsigned int	bmp_get_imgheader_size(void)
{
  return (4 + 4 + 4 + 2 + 2 + 4 + 4 + 4 + 4 + 4 + 4);
}

int		bmp_write_imgheader(int fd, t_bmp_imgheader *data)
{
  if (data == NULL)
    return (EXIT_FAILURE);
  if (write(fd, data->imgheader_size.m_char, 4) == -1)
    return (my_bmp_error("Error : unable to write to output file\n"));
  if (write(fd, data->img_width.m_char, 4) == -1)
    return (my_bmp_error("Error : unable to write to output file\n"));
  if (write(fd, data->img_height.m_char, 4) == -1)
    return (my_bmp_error("Error : unable to write to output file\n"));
  if (write(fd, data->nbr_plane.m_char, 2) == -1)
    return (my_bmp_error("Error : unable to write to output file\n"));
  if (write(fd, data->bpp.m_char, 2) == -1)
    return (my_bmp_error("Error : unable to write to output file\n"));
  if (write(fd, data->compression.m_char, 4) == -1)
    return (my_bmp_error("Error : unable to write to output file\n"));
  if (write(fd, data->total_size.m_char, 4) == -1)
    return (my_bmp_error("Error : unable to write to output file\n"));
  if (write(fd, data->res_hori.m_char, 4) == -1)
    return (my_bmp_error("Error : unable to write to output file\n"));
  if (write(fd, data->res_verti.m_char, 4) == -1)
    return (my_bmp_error("Error : unable to write to output file\n"));
  if (write(fd, data->colors.m_char, 4) == -1)
    return (my_bmp_error("Error : unable to write to output file\n"));
  if (write(fd, data->imp_colors.m_char, 4) == -1)
    return (my_bmp_error("Error : unable to write to output file\n"));
  return (EXIT_SUCCESS);
}

int		bmp_read_imgheader(int fd, t_bmp_imgheader *data)
{
  if (data == NULL)
    return (EXIT_FAILURE);
  if (read(fd, data->imgheader_size.m_char, 4) != 4)
    return (my_bmp_error("Error : not a correct bmp file\n"));
  if (read(fd, data->img_width.m_char, 4) != 4)
    return (my_bmp_error("Error : not a correct bmp file\n"));
  if (read(fd, data->img_height.m_char, 4) != 4)
    return (my_bmp_error("Error : not a correct bmp file\n"));
  if (read(fd, data->nbr_plane.m_char, 2) != 2)
    return (my_bmp_error("Error : not a correct bmp file\n"));
  if (read(fd, data->bpp.m_char, 2) != 2)
    return (my_bmp_error("Error : not a correct bmp file\n"));
  if (read(fd, data->compression.m_char, 4) != 4)
    return (my_bmp_error("Error : not a correct bmp file\n"));
  if (read(fd, data->total_size.m_char, 4) != 4)
    return (my_bmp_error("Error : not a correct bmp file\n"));
  if (read(fd, data->res_hori.m_char, 4) != 4)
    return (my_bmp_error("Error : not a correct bmp file\n"));
  if (read(fd, data->res_verti.m_char, 4) != 4)
    return (my_bmp_error("Error : not a correct bmp file\n"));
  if (read(fd, data->colors.m_char, 4) != 4)
    return (my_bmp_error("Error : not a correct bmp file\n"));
  if (read(fd, data->imp_colors.m_char, 4) != 4)
    return (my_bmp_error("Error : not a correct bmp file\n"));
  return (EXIT_SUCCESS);
}
