/*
** modif.h for modif.h in /home/descam_d/rendu/IGRAPH/MUL_2014_rtracer
**
** Made by Corentin Descamps
** Login   <descam_d@epitech.net>
**
** Started on  Mon Mar 16 23:27:07 2015 Corentin Descamps
** Last update Tue May 26 14:47:51 2015 Antoine LEMPEREUR
*/

#ifndef		MODIF_H_
# define	MODIF_H_

# include	"my.h"
# include	"object.h"

void		launch_modif_plan_lum(t_pos *, t_pos *, t_pos *, t_pos *);
void		launch_modif(t_pos *, t_pos *, t_obj *);
int		mod_pos(t_pos *, t_pos *, char);
int		rotate_x(double *, double *, double);
int		rotate_y(double *, double *, double);
int		rotate_z(double *, double *, double);

#endif		/* MODIF_H_ */
