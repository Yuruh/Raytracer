/*
** face_in_tab.h for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Thu Jun  4 10:49:39 2015 Antoine Zanardi
** Last update Thu Jun  4 14:08:04 2015 Raphael Thiebault
*/

#ifndef		FACE_IN_TAB_H_
# define	FACE_IN_TAB_H_

typedef struct	s_parse
{
  unsigned int	pos;
  int	        i;
  char		*str;
}		t_parse;

t_face		face_in_tab(char *, int, t_coor *);

#endif		/* !FACE_IN_TAB_H_ */
