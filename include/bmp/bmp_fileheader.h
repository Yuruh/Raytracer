/*
** bmp_fileheader.h for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer/pas_touche_vasseu_g_tests
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Wed Mar 18 22:10:04 2015 Adrien Vasseur
** Last update Thu May  7 23:39:35 2015 Adrien Vasseur
*/

#ifndef		BMP_FILEHEADER_H_
# define	BMP_FILEHEADER_H_

unsigned int	bmp_get_fileheader_size(void);
int		bmp_write_fileheader(int, t_bmp_fileheader *);
int		bmp_read_fileheader(int, t_bmp_fileheader *);

#endif		/* !BMP_FILEHEADER_H_ */
