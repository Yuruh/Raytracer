/*
** shadow.h for azer in /home/lemper_a/rendu/igraph/MUL_2014_rtracer
**
** Made by Antoine LEMPEREUR
** Login   <lemper_a@epitech.net>
**
** Started on  Thu May  7 23:27:01 2015 Antoine LEMPEREUR
** Last update Thu May 28 14:09:16 2015 Raphael Thiebault
*/

#ifndef		SHADOW_H_
# define	SHADOW_H_

# include	"my.h"
# include	"object.h"

double		get_shadow_value(t_data *, t_dir *, t_obj *, t_lux *);
void		shdw_lim(t_pos*, t_k *, t_obj *, t_dir *);
void		shdw_lim_complex(double[6], t_k *, t_obj *, t_dir *);

#endif		/* !SHADOW_H_ */
