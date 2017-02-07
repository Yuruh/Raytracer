/*
** fill_percent.h for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer/parsing_rt
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed Mar 18 22:57:33 2015 Antoine Zanardi
** Last update Mon May  4 15:43:20 2015 Antoine Zanardi
*/

#include	"object.h"
#include	"parsing_rt.h"

#ifndef		FILL_PERCENT_H_
# define	FILL_PERCENT_H_

void		fill_bri(char *, int, t_obj **, t_bool *);
void		fill_trans(char *, int, t_obj **, t_bool *);
void		fill_reflex(char *, int, t_obj **, t_bool *);
void		fill_size(char *, int, t_obj **, t_bool *);
double		get_percent(char *, int);

#endif		/* !FILL_PERCENT_H_ */
