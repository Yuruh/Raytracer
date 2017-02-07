/*
** go_parsing.h for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Thu Mar 19 15:32:03 2015 Antoine Zanardi
** Last update Wed May 27 11:49:29 2015 Corentin Descamps
*/

#ifndef		GO_PARSING_H_
# define	GO_PARSING_H_

# include	"object.h"

void		check_argv(int, char **, t_arg *);
void		output_bmp(char **, int, t_arg *);
void		go_parsing(t_obj **, t_arg *, t_data *, t_face_data **);

#endif		/* !GO_PARSING_H_ */
