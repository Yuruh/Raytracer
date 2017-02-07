/*
** color.h for rt in /home/descam_d/rendu/IGRAPH/MUL_2014_rtracer/include
**
** Made by Corentin Descamps
** Login   <descam_d@epitech.net>
**
** Started on  Mon Mar 16 22:24:00 2015 Corentin Descamps
** Last update Sat Jun  6 15:40:04 2015 Raphael Thiebault
*/

#ifndef		COLOR_H_
# define	COLOR_H_

# define	WHITE		0xFFFFFF
# define	RED		0xFF0000
# define	GREEN		0x00FF00
# define	BLUE		0x0000FF
# define	YELLOW		0xFFFF00
# define	ORANGE		0xFFAA00
# define	CYAN		0x00FFFF
# define	BLACK		0x000000
# define	MAGENTA		0xFF00FF
# define	CHINESE_HAT	0xFFEA4F

typedef	struct	s_color
{
  unsigned int	rgb[3];
  unsigned int	amb[3];
  unsigned int	phong[3];
  unsigned int	ref_tab[3];
  unsigned int	tra_tab[3];
}		t_color;

int		mix(int *, int);
void		init_col_tab(t_color *, int, t_cons *, t_lux_data *);

#endif		/* !COLOR_H_ */
