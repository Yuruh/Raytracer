/*
** windata.h for rt in /home/descam_d/rendu/IGRAPH/MUL_2014_rtracer
**
** Made by Corentin Descamps
** Login   <descam_d@epitech.net>
**
** Started on  Mon Mar 16 22:28:17 2015 Corentin Descamps
** Last update Fri May 15 15:33:11 2015 Antoine LEMPEREUR
*/

#ifndef		WINDATA_H_
# define	WINDATA_H_

typedef struct		s_win
{
  void			*mlx;
  void			*win;
  void			**img;
  int			bpp;
  int			size_line;
  int			endian;
  char			**data;
}			t_win;

#endif		/* !WINDATA_H_ */
