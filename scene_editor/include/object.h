/*
** object.h for rt in /home/descam_d/rendu/IGRAPH/MUL_2014_rtracer/scene_editor
** 
** Made by Corentin Descamps
** Login   <descam_d@epitech.net>
** 
** Started on  Wed Jun  3 17:25:32 2015 Corentin Descamps
** Last update Sun Jun  7 21:32:19 2015 Corentin Descamps
*/

#ifndef		OBJECT_H_
# define	OBJECT_H_

# define	SPHERE		1
# define	CYLINDRE	2
# define	CONE		3
# define	PLAN		4

typedef	struct	s_wid
{
  GtkWidget	*win;
  GtkWidget	**label_pos;
  GtkWidget	**label_rot;
  GtkWidget	**label_cons;
  GtkWidget	**label_hlim;
  GtkWidget	**label_blim;
  GtkWidget	**entry_pos;
  GtkWidget	**entry_rot;
  GtkWidget	**entry_cons;
  GtkWidget	**entry_hlim;
  GtkWidget	**entry_blim;
  GtkWidget	**Scale;
}		t_wid;

typedef	struct	s_pos
{
  int		x;
  int		y;
  int		z;
}		t_pos;

typedef struct	s_obj
{
  int		type;
  int		color;
  t_pos		pos;
  t_pos		rot;
  t_pos		h_lim;
  t_pos		b_lim;
  int		rayon;
  int		bril;
  int		spec;
  int		trans;
  int		ref;
  unsigned char	rgb[3];
  struct s_obj	*next;
}		t_obj;

typedef	struct	s_view
{
  t_pos		pos;
  t_pos		rot;
}		t_view;

typedef struct		s_light
{
  t_pos			pos;
  unsigned char		rgb[3];
  struct s_light	*next;
}			t_light;

void		add_sphere(GtkWidget *, gpointer);
void		add_plan(GtkWidget *, gpointer);
void		add_cyl(GtkWidget *, gpointer);
void		add_cone(GtkWidget *, gpointer);
void		add_light(GtkWidget *, gpointer);
void		init_view(void);
int		stack_light(t_light *);
int		stack_obj(t_obj *);

#endif		/* !OBJECT_H_ */
