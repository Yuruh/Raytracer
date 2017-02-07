/*
** light.h for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Mon Mar 30 15:49:10 2015 Antoine Zanardi
** Last update Sat May  9 14:16:13 2015 Antoine LEMPEREUR
*/

#ifndef		LIGHT_H_
# define	LIGHT_H_

# include	"triangle.h"
# include	"object.h"

void		calc_light(t_pos *, t_pos *, t_inter *);
double		scalaire(t_pos *, t_pos *);
int		final_tri_color(t_data *, t_triangle *, t_pos *, t_k, t_pos *);
unsigned int	lumos(t_data *, t_pos *, t_ray_data *, t_lux_data *);

#endif		/* !LIGHT_H_ */
