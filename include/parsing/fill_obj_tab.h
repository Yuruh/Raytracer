/*
** fill_obj_tab.h for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Thu Mar 26 18:30:00 2015 Antoine Zanardi
** Last update Thu May  7 17:42:04 2015 Antoine Zanardi
*/

#ifndef		FILL_OBJ_TAB_H_
# define	FILL_OBJ_TAB_H_

# include	"object.h"
# include	"parsing_obj.h"

void		pass_coor(char *, int *);
unsigned int	nb_faces(char *);
int		fill_coor(char *, int, unsigned int *, t_pos_data *);
t_face		face_in_tab(char *, int, t_coor *);
void		fill_tab(char *, t_face_data *, t_coor *);

#endif		/* !FILL_OBJ_TAB_H_ */
