/*
** fill_obj_list.h for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer/parsing_rt
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed Mar 18 16:54:04 2015 Antoine Zanardi
** Last update Mon Mar 30 10:50:54 2015 Antoine Zanardi
*/

#include	"object.h"

#ifndef		FILL_OBJ_LIST_H_
# define	FILL_OBJ_LIST_H_

void		check_bool(t_obj **, t_bool *);
void		fill_obj_list(char *, t_obj **, t_bool *, int);
void		init_bool(t_bool *, t_obj **);
int		which_to_fill_2(char *, int, t_obj **, t_bool *);
int		which_to_fill(char *, int, t_obj **, t_bool *);

#endif		/* !FILL_OBJ_LIST_H_ */
