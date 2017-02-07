/*
** parsing_rt.h for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer/parsing_rt
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Tue Mar 17 11:32:52 2015 Antoine Zanardi
** Last update Wed May 27 12:15:42 2015 Corentin Descamps
*/

#ifndef		PARSING_RT_H_
# define	PARSING_RT_H_

# include	"define.h"
# include	"object.h"

# define	D_R(nb)			((3.14 * (double)nb) / 180.0)
# define	BUFFER_SIZE		100000

typedef	struct	s_arg
{
  int		argc;
  char		**argv;
  int		o;
  char		*bmp;
}		t_arg;

typedef	struct	s_bool
{
  int		form;
  int		pos;
  int		rot;
  int		bri;
  int		trans;
  int		color;
  int		reflex;
  int		angle;
  int		rayon;
  int		h_lim;
  int		b_lim;
  int		damier;
  int		focus;
  int		size;
  int		xpm;
  int		dis;
  int		circonference;
  int		spec;
  int		rempli;
  int		video;
  int		lumos;
  int		sheet;
}		t_bool;

void		parsing_rt(char **, t_obj **, t_data *, t_face_data **);
void		init_compt(int *, int *, int *, t_bool *);
void		check_all(char *, int, int, t_def *);
void		view_list(t_obj **);
char		*correct_file(char *, t_def *);

#endif		/* !PARSING_RT_H */
