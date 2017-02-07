/*
** object.h for rt in /home/descam_d/rendu/IGRAPH/MUL_2014_rtracer
**
** Made by Corentin Descamps
** Login   <descam_d@epitech.net>
**
** Started on  Mon Mar 16 22:34:22 2015 Corentin Descamps
** Last update Mon Jun  1 10:38:57 2015 Antoine Zanardi
*/

#ifndef		OBJECT_H_
# define	OBJECT_H_

# include	"mlx_int.h"
# include	"parsing/define.h"

# define	PLAN		0
# define	SPHERE		1
# define	CYLINDRE	2
# define	CONE		3
# define	PARABOLOID	4
# define	HYPERBOLOID	5
# define	ELLIPSOID	6
# define	TORE		7
# define	CUBE		8
# define	DD		9
# define	STAR		10
# define	MOBIUS		11
# define	VIEW		12
# define	LIGHT		13
# define	OBJ		14
# define	TRIANGLE	15
# define	IGN		16

typedef struct		s_pos
{
  double		x;
  double		y;
  double		z;
}			t_pos;

typedef struct		s_vec2i
{
  int			x;
  int			y;
}			t_vec2i;

typedef struct		s_k
{
  double		k;
  int			is_sec;
}			t_k;

typedef struct		s_inter
{
  double		x;
  double		y;
  double		z;
  int			is_sec;
}			t_inter;

typedef	struct		s_pos_data
{
  t_pos			*pos;
  unsigned int		lim;
}			t_pos_data;

typedef	struct		s_face
{
  t_pos			pt1;
  t_pos			pt2;
  t_pos			pt3;
  t_pos			norm1;
  t_pos			norm2;
  t_pos			norm3;
  t_pos			text1;
  t_pos			text2;
  t_pos			text3;
}			t_face;

typedef struct		s_lim
{
  int			is_lim;
  t_pos			bot;
  t_pos			top;
}			t_lim;

typedef struct		s_cons
{
  double		ref;
  double		tra;
  double		bril;
  double		spec;
  double		rempli;
  int			focus;
  int			lumos;
  int			sheet;
}			t_cons;

typedef	struct		s_face_data
{
  t_face		*face;
  int			is_normale;
  int			is_texture;
  unsigned int		lim;
  int			nb;
  t_pos			pos;
  t_pos			rot;
  double		size;
  int			color;
  t_cons		cons;
  char			*text_path;
  t_img			*img;
  char			*text_data;
  struct s_face_data	*next;
}			t_face_data;

typedef	struct		s_tri_data
{
  t_pos			u;
  t_pos			v;
  t_pos			n;
  double		uu;
  double		uv;
  double		vv;
  double		d;
  t_pos			norm;
  double		side_1;
  double		side_2;
  double		side_3;
}			t_tri_data;

typedef struct		s_triangle
{
  t_face		f;
  t_tri_data		t_d;
  int			src_col;
  t_cons		cons;
  struct s_triangle	*next;
  struct s_triangle	*prev;
}			t_triangle;

typedef	struct		s_lux_data
{
  double		spec;
  double		cos;
  double		shdw;
  int			col;
  int			ref_col;
  int			tra_col;
  int			col_obj;
}			t_lux_data;

typedef	struct		s_dis
{
  double		x;
  double		y;
  double		z;
}			t_dis;

typedef struct		s_long
{
  double		ang;
  double		ray;
  double		circonference;
  double		size;
}			t_long;

typedef	struct		s_xpm_img
{
  int			xpm;
  t_img			*xpm_img;
  char			*xpm_path;
}			t_xpm_img;

typedef struct		s_texture
{
  char			*text_path;
  t_img			*img;
  char			*text_data;
  int			is_normale;
  int			is_texture;
}			t_texture;

typedef	struct		s_rotc
{
  unsigned int		bool;
  t_pos			pos;
  t_pos			ang;
}			t_rotc;

typedef	struct		s_video
{
  double		ratio;
  t_pos			pos;
  t_pos			rot;
  t_rotc		rot_cent;
  struct s_video	*next;
}			t_video;

typedef struct		s_video_data
{
  int			id;
  double		time;
  t_video		*list;
}			t_video_data;

typedef	struct		s_list_pos
{
  t_pos			pos;
  t_pos			rot;
  struct s_list_pos	*next;
  struct s_list_pos	*prev;
}			t_list_pos;

typedef struct		s_obj
{
  int			type;
  t_long		lon;
  t_lim			lim;
  int			src_col;
  int			damier_col;
  t_xpm_img		xpm;
  t_video_data		video;
  t_list_pos		*list_pos;
  t_cons		cons;
  t_dis			dis;
  t_pos			pos;
  t_pos			rot;
  t_texture		texture;
  struct s_obj		*next;
  struct s_triangle	*triangle;
}			t_obj;

typedef	struct		s_ray_data
{
  t_pos			v_dir_n;
  t_inter		inter;
  t_obj			*obj;
  t_obj			*old_obj;
  t_triangle		*tri;
  t_pos			eye_pos_n;
  t_pos			v_pos_n;
  t_k			k;
  int			color;
  int			ref;
}			t_ray_data;

#endif		/* !OBJECT_H_ */
