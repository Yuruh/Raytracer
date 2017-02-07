/*
** fill_rolim.h for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Mon Mar 30 10:32:55 2015 Antoine Zanardi
** Last update Mon Jun  1 22:50:41 2015 Antoine Zanardi
*/

#ifndef		FILL_ROLIM_H_
# define	FILL_ROLIM_H_

# include	"object.h"
# include	"parsing_rt.h"

void		rolim_h_lim(t_bool *, t_obj **);
void		rolim_b_lim(t_bool *, t_obj **);
void		rolim_rot(t_bool *, t_obj **);
void		rolim_dis(t_bool *, t_obj **);

#endif		/* !FILL_ROLIM_H_ */
