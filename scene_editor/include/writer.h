/*
** writer.h for rt in /home/descam_d/rendu/IGRAPH/MUL_2014_rtracer/scene_editor
** 
** Made by Corentin Descamps
** Login   <descam_d@epitech.net>
** 
** Started on  Wed Jun  3 11:16:08 2015 Corentin Descamps
** Last update Sun Jun  7 21:42:21 2015 Corentin Descamps
*/

#ifndef		WRITER_H_
# define	WRITER_H_

void		write_light(FILE *);
void		write_color(FILE *, unsigned char *);
void		writer(GtkWidget *, gpointer);

#endif		/* !WRITER_H_ */
