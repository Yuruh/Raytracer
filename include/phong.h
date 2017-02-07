/*
** phong.h for rt in /home/descam_d/rendu/IGRAPH/MUL_2014_rtracer
**
** Made by Corentin Descamps
** Login   <descam_d@epitech.net>
**
** Started on  Fri May  8 20:36:40 2015 Corentin Descamps
** Last update Wed May 20 17:13:20 2015 Corentin Descamps
*/

#ifndef		PHONG_H_
# define	PHONG_H_

unsigned int	apply_phong(unsigned int, unsigned int, t_lux_data *);
void		rgb_phong(unsigned int *, t_lux_data *, t_cons *);
double		specular_ref(t_pos *, t_ray_data *, t_dir *);

#endif		/* !PHONG_H_ */
