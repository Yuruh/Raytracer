/*
** bmp_imgheader.h for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer/pas_touche_vasseu_g_tests
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Wed Mar 18 22:50:52 2015 Adrien Vasseur
** Last update Thu May  7 23:40:35 2015 Adrien Vasseur
*/

#ifndef BMP_IMGHEADER_H_
# define BMP_IMGHEADER_H_

unsigned int	bmp_get_imgheader_size(void);
int		bmp_write_imgheader(int, t_bmp_imgheader *);
int		bmp_read_imgheader(int, t_bmp_imgheader *);

#endif /* !BMP_IMGHEADER_H_ */
