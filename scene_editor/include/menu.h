/*
** menu.h for rt in /home/descam_d/rendu/IGRAPH/MUL_2014_rtracer/scene_editor/include
** 
** Made by Corentin Descamps
** Login   <descam_d@epitech.net>
** 
** Started on  Tue May 12 16:03:34 2015 Corentin Descamps
** Last update Fri May 29 11:18:28 2015 Corentin Descamps
*/

#ifndef		MENU_H_
# define	MENU_H_

typedef	struct	s_menu
{
  const	gchar	*title;
  GCallback	callback;
  gpointer	data;
  struct s_menu	*next;
}		t_menu;

int		menu_bar(t_data *);
int		add_stack(t_menu **, const gchar *, GCallback, gpointer);

#endif		/* !MENU_H_ */
