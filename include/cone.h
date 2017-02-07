/*
** cone.h for rt in /home/descam_d/rendu/IGRAPH/MUL_2014_rtracer
**
** Made by Corentin Descamps
** Login   <descam_d@epitech.net>
**
** Started on  Mon Mar 16 22:55:02 2015 Corentin Descamps
** Last update Tue May  5 13:33:37 2015 Raphael Thiebault
*/

#ifndef		CONE_H_
# define	CONE_H_

# include	"my.h"
# include	"object.h"

t_pos		get_equ_con(t_pos *, t_pos *, double, t_pos);
void		fill_info_con(t_data *, t_pos *, t_obj *);

#endif		/* CONE_H_ */
