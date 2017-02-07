/*
** fill_points_tab.h for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Thu Mar 26 16:05:41 2015 Antoine Zanardi
** Last update Tue May  5 16:48:32 2015 Antoine Zanardi
*/

#ifndef		FILL_POINTS_TAB_H_
# define	FILL_POINTS_TAB_H_

# include	"object.h"

unsigned int	nb_points(char *);
t_pos		point_in_tab(char *, int);
t_pos_data	fill_points_tab(char *);

#endif		/* !FILL_POINTS_TAB_H_ */
