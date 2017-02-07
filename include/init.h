/*
** init.h for rt in /home/descam_d/rendu/IGRAPH/MUL_2014_rtracer
**
** Made by Corentin Descamps
** Login   <descam_d@epitech.net>
**
** Started on  Mon Mar 16 23:20:23 2015 Corentin Descamps
** Last update Sun Jun  7 00:41:24 2015 Adrien Vasseur
*/

#ifndef		INIT_H_
# define	INIT_H_

#include	"my.h"
#include	"parsing_rt.h"

void		list_inter(void (**)(t_ray_data*, t_obj*, t_k*));
void		list_norm(void (**)(t_ray_data*, t_pos*));
void		panel_init(t_data*, int, char**, t_arg*);

#endif		/* !INIT_H_ */
