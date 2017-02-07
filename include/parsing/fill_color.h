/*
** fill_color.h for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer/parsing_rt
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Thu Mar 19 00:03:33 2015 Antoine Zanardi
** Last update Thu May 21 22:17:18 2015 Antoine Zanardi
*/

#include	"parsing_rt.h"
#include	"object.h"

#ifndef		FILL_COLOR_H_
# define	FILL_COLOR_H_

void		fill_color(char *, int, t_obj **, t_bool *);
void		fill_damier(char *, int, t_obj **, t_bool *);
void		fill_focus(char *, int, t_obj **, t_bool *);
void		fill_lumos(char *, int, t_obj **, t_bool *);
int		get_color(char *, int);

#endif		/* !FILL_COLOR_H_ */
