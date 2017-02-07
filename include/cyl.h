/*
** cyl.h for rt in /home/descam_d/rendu/IGRAPH/MUL_2014_rtracer
**
** Made by Corentin Descamps
** Login   <descam_d@epitech.net>
**
** Started on  Mon Mar 16 23:05:29 2015 Corentin Descamps
** Last update Fri Mar 27 15:46:04 2015 Antoine LEMPEREUR
*/

#ifndef		CYL_H_
# define	CYL_H_

# include	"object.h"
# include	"my.h"

void		fill_info_cyl(t_data *, t_pos *, t_obj *);
t_pos		get_norm_cyl(t_inter *);
t_pos		get_equ_cyl(t_pos *, t_pos *, double, t_pos);

#endif		/* !CYL_H_ */
