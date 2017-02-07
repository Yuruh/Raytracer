/*
** bmp_exporter.c for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer/pas_touche_vasseu_g_tests
**
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
**
** Started on  Wed Mar 18 21:38:23 2015 Adrien Vasseur
** Last update Tue Mar 24 13:46:52 2015 Antoine Zanardi
*/

#include		<stdlib.h>
#include		<unistd.h>
#include		<fcntl.h>
#include		"mlx.h"
#include		"my.h"
#include		"mlx_int.h"
#include		"windata.h"
#include		"bmp/bmp.h"
#include		"bmp/bmp_exporter.h"
#include		"bmp/bmp_utils.h"
#include		"bmp/bmp_fileheader.h"
#include		"bmp/bmp_imgheader.h"
#include		"bmp/bmp_content.h"

static int		output_file(char *filename)
{
  int			fd;

  if ((fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
    {
      my_bmp_error("Error : unable to create file :");
      my_bmp_error(filename);
      my_bmp_error("\n");
    }
  return (fd);
}

static int		fileheader(int fd, unsigned int total)
{
  t_bmp_fileheader	fileheader;

  fileheader.magic.m_int = BMP_MAGIC_NUMBER;
  fileheader.file_size.m_int = total;
  fileheader.reserved.m_int = 0;
  fileheader.offset.m_int = bmp_get_fileheader_size()
    + bmp_get_imgheader_size();
  return (bmp_write_fileheader(fd, &fileheader));
}

static int		imgheader(int fd, unsigned int content, t_data *d)
{
  t_bmp_imgheader	imgheader;

  imgheader.imgheader_size.m_int = bmp_get_imgheader_size();
  imgheader.img_width.m_int = (unsigned int)W;
  imgheader.img_height.m_int = (unsigned int)H;
  imgheader.nbr_plane.m_int = 1;
  imgheader.bpp.m_int = 24;
  imgheader.compression.m_int = 0;
  imgheader.total_size.m_int = content;
  imgheader.res_hori.m_int = 2834;
  imgheader.res_verti.m_int = 2834;
  imgheader.colors.m_int = 0;
  imgheader.imp_colors.m_int = 0;
  return (bmp_write_imgheader(fd, &imgheader));
}

int			bmp_exporter(char *filename, t_win *data, t_data *d)
{
  int			fd;
  unsigned int		content_size;
  unsigned int		total_size;

  if ((fd = output_file(filename)) == -1)
    return (EXIT_FAILURE);
  content_size = bmp_get_content_size(d);
  total_size = content_size + bmp_get_fileheader_size()
    + bmp_get_imgheader_size();
  fileheader(fd, total_size);
  imgheader(fd, content_size, d);
  bmp_write_content(fd, data, d);
  close(fd);
  return (EXIT_SUCCESS);
}
