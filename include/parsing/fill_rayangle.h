/*
** fill_rayangle.h for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer/parsing_rt
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed Mar 18 18:46:43 2015 Antoine Zanardi
** Last update Sun May 10 19:02:07 2015 Antoine Zanardi
*/

#include	"object.h"
#include	"parsing_rt.h"

#ifndef		FILL_RAYANGLE_H_
# define	FILL_RAYANGLE_H_

void		fill_rayon(char *, int, t_obj **, t_bool *);
void		fill_angle(char *, int, t_obj **, t_bool *);
void		fill_circonference(char *, int, t_obj **, t_bool *);

#endif		/* !FILL_RAYANGLE_H_ */
