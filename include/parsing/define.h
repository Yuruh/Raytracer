/*
** define.h for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Mon Mar 23 16:25:10 2015 Antoine Zanardi
** Last update Wed May 20 16:56:24 2015 Antoine Zanardi
*/

#ifndef		DEFINE_H_
# define	DEFINE_H_

typedef struct	s_xpm
{
  char		*xpm;
  unsigned int	id;
  struct s_xpm	*next;
}		t_xpm;

typedef	struct	s_name
{
  char		*name;
  unsigned int	id;
  struct s_name	*next;
  struct s_name *prev;
}		t_name;

typedef	struct	s_def
{
  int		anti;
  int		height;
  int		width;
  double	time;
  t_name	*name;
  t_xpm		*xpm;
  t_xpm		*video;
}		t_def;

void		init_def(t_def *, int *);
void		fill_define(char *, int, t_def *);
void		fill_aa(char *, int, t_def *, int);
void		fill_width(char *, int, t_def *, int);
void		fill_height(char *, int, t_def *, int);
void		fill_time_def(char *, int, t_def *, int);

#endif		/* !DEFINE_H_ */
