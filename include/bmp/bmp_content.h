/*
** bmp_content.h for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer/pas_touche_vasseu_g_tests
**
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
**
** Started on  Mon Mar 23 12:11:23 2015 Adrien Vasseur
** Last update Thu May  7 23:32:07 2015 Adrien Vasseur
*/

#ifndef		BMP_CONTENT_H_
# define	BMP_CONTENT_H_

# include	"my.h"

unsigned int	bmp_get_content_size(t_data *);
int		bmp_write_content(int, t_win *, t_data *);
int		bmp_read_content(int, char *, t_img *);

#endif /* !BMP_CONTENT_H_ */
