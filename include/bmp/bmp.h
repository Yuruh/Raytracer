/*
** bmp.h for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer/pas_touche_vasseu_g_tests
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Mon Mar 16 23:32:28 2015 Adrien Vasseur
** Last update Fri May  8 21:38:23 2015 Adrien Vasseur
*/

#ifndef BMP_H_
# define BMP_H_

# define BMP_MAGIC_NUMBER 0x4d42

typedef union	u_bmp_data
{
  unsigned int	m_int;
  unsigned char	m_char[4];
}		t_bmp_data;

typedef struct	s_bmp_fileheader
{
  t_bmp_data	magic;
  t_bmp_data	file_size;
  t_bmp_data	reserved;
  t_bmp_data	offset;
}		t_bmp_fileheader;

typedef struct	s_bmp_imgheader
{
  t_bmp_data	imgheader_size;
  t_bmp_data	img_width;
  t_bmp_data	img_height;
  t_bmp_data	nbr_plane;
  t_bmp_data	bpp;
  t_bmp_data	compression;
  t_bmp_data	total_size;
  t_bmp_data	res_hori;
  t_bmp_data	res_verti;
  t_bmp_data	colors;
  t_bmp_data	imp_colors;
}		t_bmp_imgheader;

#endif /* !BMP_H_ */
