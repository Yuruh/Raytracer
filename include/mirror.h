/*
** mirror.h for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Tue Mar 24 14:02:53 2015 Antoine Zanardi
** Last update Thu May  7 13:57:20 2015 Raphael Thiebault
*/

#ifndef		MIRROR_H_
# define	MIRROR_H_

# include	"my.h"
# include	"object.h"

int		get_reflected_color(t_data *, t_obj *, t_pos *);
int		new_col_refl(t_ray_data*, int, int);
t_pos		convert_to_unit(t_pos *);

#endif		/* !MIRROR_H_ */
