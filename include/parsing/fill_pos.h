/*
** fill_pos.h for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer/parsing_rt
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed Mar 18 17:39:15 2015 Antoine Zanardi
** Last update Mon Mar 30 10:39:29 2015 Antoine Zanardi
*/

#include	"object.h"
#include	"parsing_rt.h"

#ifndef		FILL_POS_H_
# define	FILL_POS_H_

void		fill_pos(char *, int, t_obj **, t_bool *);
void		fill_rot(char *, int, t_obj **, t_bool *);
void		fill_h_lim(char *, int, t_obj **, t_bool *);
void		fill_b_lim(char *, int, t_obj **, t_bool *);
double		get_pos(char *, int *);

#endif		/* !FILL_POS_H_ */
