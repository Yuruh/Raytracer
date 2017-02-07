/*
** parsing_obj.h for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer/parsing
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Thu Mar 26 10:16:55 2015 Antoine Zanardi
** Last update Thu May  7 17:42:36 2015 Antoine Zanardi
*/

#ifndef		PARSING_OBJ_H_
# define	PARSING_OBJ_H_

# include	"object.h"
# include	"define.h"

typedef struct	s_coor
{
  t_pos_data	point;
  t_pos_data	normale;
  t_pos_data	texture;
}		t_coor;

void		exec_parsing_obj(t_name *, t_face_data **, t_obj **);
char		*correct_file_obj(char *);
int		open_file(char *, int *);

#endif		/* !PARSING_OBJ_H_ */
