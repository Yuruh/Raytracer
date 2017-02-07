/*
** get_k.h for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Mon Mar 30 16:35:57 2015 Antoine Zanardi
** Last update Thu May 28 11:13:10 2015 Raphael Thiebault
*/

#ifndef		GET_K_H_
# define	GET_K_H_

# include	"my.h"
# include	"object.h"

# define	DOT(a, b) ((a).x * (b).x + (a).y * (b).y + (a).z * (b).z)
# define	ALMOST_ZERO	0.0000001

int		check_lim(double, t_obj *, t_ray_data *, t_k *);
t_k		get_k_plan(t_obj *, t_pos *, t_pos *, t_inter *);
t_k		get_k(t_obj *, t_dir *, t_data *, t_ray_data *);

#endif		/* !GET_K_H_ */
