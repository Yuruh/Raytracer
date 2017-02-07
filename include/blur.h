/*
** blur.h for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Thu May  7 13:42:54 2015 Antoine Zanardi
** Last update Fri May  8 17:48:49 2015 Antoine Zanardi
*/

#ifndef		BLUR_H_
# define	BLUR_H_

void		set_blur(t_data *, t_ray_data *, int, int);
void		apply(t_data *);
void		set_i_j(int *, int *, int, int);
int		get_blur_color(t_data *, int, int);
t_blur		**get_blur_tab(int, int);

#endif		/* !BLUR_H_ */
