/*
** light_vec.h for rt in /home/descam_d/rendu/IGRAPH/MUL_2014_rtracer
** 
** Made by Corentin Descamps
** Login   <descam_d@epitech.net>
** 
** Started on  Thu May 28 13:48:11 2015 Corentin Descamps
** Last update Thu May 28 13:49:21 2015 Corentin Descamps
*/

#ifndef		LIGHT_VEC_H_
# define	LIGHT_VEC_H_

void		calc_light(t_pos *, t_pos *, t_inter *);
void		get_light_vec(t_lux *, t_dir *, t_ray_data *);

#endif		/* !LIGHT_VEC_H_ */
