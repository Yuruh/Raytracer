/*
** manage_image.h for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Tue Mar 24 14:11:44 2015 Antoine Zanardi
** Last update Sat May  9 01:21:30 2015 Adrien Vasseur
*/

#ifndef		MANAGE_IMAGE_H_
# define	MANAGE_IMAGE_H_

# include	"my.h"

void		pixel_to_image(t_data *, int, int , int);
int		get_pixel_color(t_data *, int, int);
int		get_pixel_text_color(t_obj *, int, int);

#endif		/* !MANAGE_IMAGE_H_ */
