/*
** calc.h for rt in /home/descam_d/rendu/IGRAPH/MUL_2014_rtracer
**
** Made by Corentin Descamps
** Login   <descam_d@epitech.net>
**
** Started on  Mon Mar 16 22:48:09 2015 Corentin Descamps
** Last update Fri May  1 16:59:22 2015 Antoine LEMPEREUR
*/

#ifndef		CALC_H_
# define	CALC_H_

# include	"object.h"
# include	"my.h"

t_inter		get_inter(t_pos *, t_k, t_pos *);
t_inter		get_inter_bis(t_ray_data *);
void		go_rotate(double *, double *, double *, t_pos *);
void		go_derotate(double *, double *, double *, t_pos *);

#endif		/* !CALC_H_ */
