/*
** go.h for rt in /home/descam_d/rendu/IGRAPH/MUL_2014_rtracer
**
** Made by Corentin Descamps
** Login   <descam_d@epitech.net>
**
** Started on  Mon Mar 16 23:16:03 2015 Corentin Descamps
** Last update Wed May  6 17:34:47 2015 Raphael Thiebault
*/

#ifndef		GO_H_
# define	GO_H_

# include	"my.h"
# include	"object.h"

void		go(t_data *, t_vec2i, t_vec2i);
int		mix(int *, int);
int		anti_aliasing(t_data *, double, double, int*);

#endif		/* !GO_H_ */
