/*
** trans.h for azer in /home/lemper_a/rendu/igraph/MUL_2014_rtracer
**
** Made by Antoine LEMPEREUR
** Login   <lemper_a@epitech.net>
**
** Started on  Fri Apr  3 00:08:29 2015 Antoine LEMPEREUR
** Last update Thu May  7 15:11:46 2015 Raphael Thiebault
*/

#ifndef		TRANS_H_
# define	TRANS_H_

# include	"my.h"
# include	"object.h"

int		get_trans_color(t_ray_data *, t_pos *, t_data *);
int		new_col_trans(t_ray_data *, int, int);

#endif		/* !MIRROR_H_ */
