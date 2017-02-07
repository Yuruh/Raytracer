/*
** triangle.h for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Mon Mar 30 15:44:48 2015 Antoine Zanardi
** Last update Thu Jun  4 13:53:44 2015 Antoine LEMPEREUR
*/

#ifndef		TRIANGLE_H_
# define	TRIANGLE_H_

# include	"object.h"

void		put_tri_in_list(t_obj **, t_face_data *);
t_k		pick_k_tri(t_triangle *, t_dir *, t_triangle **);
t_pos		get_norm_tri(t_pos *, t_pos *, t_pos *);
t_pos		get_actual_tri_norm(t_triangle *, t_pos *);
t_pos		get_vec(t_pos *, t_pos *);
t_pos		cross(t_pos *, t_pos *);
void		apply_pos(t_face *, t_pos *);
void		apply_rot(t_face *, t_pos *);
void		apply_size(t_face *, double);
t_triangle	*get_tri_list(t_triangle **, t_face_data *);

#endif		/* !TRIANGLE_H_ */
