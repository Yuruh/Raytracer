/*
** sphere.h for rt in /home/descam_d/rendu/IGRAPH/MUL_2014_rtracer
**
** Made by Corentin Descamps
** Login   <descam_d@epitech.net>
**
** Started on  Mon Mar 16 23:01:59 2015 Corentin Descamps
** Last update Tue May  5 13:30:08 2015 Raphael Thiebault
*/

#ifndef		SPHERE_H_
# define	SPHERE_H_

#include	"object.h"
#include	"my.h"

t_pos		get_equ_sph(t_pos *, t_pos *, double, t_pos);
void		fill_info_sphere(t_data *, t_pos *, t_obj *);

#endif		/* SPHERE_H_ */
