/*
** image.h for image.h in /home/descam_d/rendu/IGRAPH/MUL_2014_rtracer
** 
** Made by Corentin Descamps
** Login   <descam_d@epitech.net>
** 
** Started on  Mon Mar 16 23:23:13 2015 Corentin Descamps
** Last update Mon Mar 16 23:26:12 2015 Corentin Descamps
*/

#ifndef		IMAGE_H_
# define	IMAGE_H_

# include	"my.h"

void		pixel_to_image(t_data *, int, int, int);
int		get_pixel_color(t_data *, int, int);

#endif		/* !IMAGE_H_ */
