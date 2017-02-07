/*
** my.h for wolf in /home/lemper_a/rendu/MUL_2014_wolf3d/include
**
** Made by Antoine LEMPEREUR
** Login   <lemper_a@epitech.net>
**
** Started on  Mon Dec  1 09:49:13 2014 Antoine LEMPEREUR
** Last update Sun Jun  7 17:49:48 2015 Antoine LEMPEREUR
*/

# ifndef	MY_H_
# define	MY_H_

# include	"mlx.h"
# include	"windata.h"
# include	"object.h"
# include	"parse_ip.h"

# define	SHADOW		0.05
# define	AMB		0.2
# define	A_A		4
# define	PI		3.14159
# define	W		d->width
# define	H		d->height
# define	EYE		d->eye_pos_n
# define        VEC		d->v_pos_n
# define	ANG		o->lon.ang
# define	RAY		o->lon.ray
# define	BLUR		12
# define	IMG_SEC		24

typedef	struct		s_lux
{
  t_pos			pos;
  t_pos			rot;
  t_lim			lim;
  int			color;
  int			form;
  t_video_data		video;
  struct s_lux		*next;
  struct s_lux		*prev;
}			t_lux;

typedef struct		s_equ
{
  double		*roots;
  int			nb_roots;
}			t_equ;

typedef struct		s_dir
{
  t_pos			init;
  t_pos			vec;
}			t_dir;

typedef	struct		s_blur
{
  int			color;
  double		k;
  char			focus;
}			t_blur;

typedef struct		s_data
{
  t_win			win;
  t_pos			eye;
  t_pos			rot;
  t_video_data		video;
  t_list_pos		*list_pos;
  t_obj			*obj;
  t_lux			*lux;
  t_blur		**blur;
  int			width;
  int			height;
  int			a_a;
  double		time;
  int			count_img;
  int			is_paused;
  int			nb_light;
  int			has_win;
  void			(**do_inter)(t_ray_data *, t_obj *, t_k *);
  void			(**do_shdw)(t_dir *, double *, t_obj *, t_lux *);
  void			(**do_norm)(t_ray_data *, t_pos *);
}			t_data;

int		my_strncmp_on_s1(char*, char*);
t_ray_data	get_pix(t_data*, t_dir*, int, t_obj *);
t_obj		*malloc_obj(void);
int		init_value(t_data*);
t_ray_data	*final_color(t_data *, t_ray_data *, t_pos *, t_pos *);
unsigned int	modify_col(int, t_lux_data *, int, t_cons *);
int		shadow_sph(t_obj*, t_lux*, t_pos);
int		shadow_pla(t_obj*, t_lux*, t_pos);
int		shadow_cyl(t_obj*, t_lux*, t_pos);
int		shadow_con(t_obj*, t_lux*, t_pos);
void		init_lim(t_data*);
int		bread_and_butter(t_data*, t_pos*);
void		init_pos(t_data*);
void		init_rot(t_data*);
void		init_spe_bril(t_data*);
void		init_type_color(t_data*);
void		init_ref_tra(t_data*);
void		put_type_color(t_data*, int, int, int);
void		put_spe_bril(t_data*, double, float, int);
void		put_lim(t_data*, double, double, int);
void		apply_effects(t_data*, t_pos*, t_obj*);
int		refl(t_data*, t_ray_data *, t_pos *);
int		my_getnbr(char*);
double		my_getdouble(char*);
void		display_usage(void);
int		parse(t_data*, char*);
void		trans(t_data*, t_obj*, t_pos*);
t_pos		convert_to_unit(t_pos*);
void		in_lim(t_data*, t_obj*, t_pos*, t_pos);
void		init_pos2(t_data*);
void		init_ref_tra(t_data*);
int		go_shadow(t_obj*, t_lux*, t_pos);
double		get_sec_k(double, double, double);
void		normalise(t_pos *);
void		get_k1_k2(double *, double *, t_obj *, t_inter *);
double		inter_box(t_lim *, t_pos *, t_pos *);
t_blur		**get_blur_tab(int, int);
int		get_blur_color(t_data *, int, int);
void		apply_blur(t_data *);
void		inter_plan(t_ray_data*, t_obj*, t_k*);
void		inter_sphere(t_ray_data*, t_obj*, t_k*);
void		inter_cyl(t_ray_data*, t_obj*, t_k*);
void		inter_cone(t_ray_data*, t_obj*, t_k*);
void		inter_para(t_ray_data*, t_obj*, t_k*);
void		inter_hyper(t_ray_data*, t_obj*, t_k*);
void		inter_elli(t_ray_data*, t_obj*, t_k*);
void		inter_tore(t_ray_data*, t_obj*, t_k*);
void		inter_cube(t_ray_data*, t_obj*, t_k*);
void		inter_dingdong(t_ray_data*, t_obj*, t_k*);
void		inter_mobius(t_ray_data*, t_obj*, t_k*);
void		inter_stellar(t_ray_data*, t_obj*, t_k*);
void		norm_plan(t_ray_data*, t_pos*);
void		norm_sphere(t_ray_data*, t_pos*);
void		norm_cyl(t_ray_data*, t_pos*);
void		norm_cone(t_ray_data*, t_pos*);
void		norm_para(t_ray_data*, t_pos*);
void		norm_hyper(t_ray_data*, t_pos*);
void		norm_elli(t_ray_data*, t_pos*);
void		norm_tore(t_ray_data*, t_pos*);
void		norm_cube(t_ray_data*, t_pos*);
void		norm_dingdong(t_ray_data*, t_pos*);
void		norm_mobius(t_ray_data*, t_pos*);
void		norm_star(t_ray_data*, t_pos*);
void		shdw_plan(t_dir*, double*, t_obj*, t_lux *);
void		shdw_sphere(t_dir*, double*, t_obj*, t_lux *);
void		shdw_cyl(t_dir*, double*, t_obj*, t_lux *);
void		shdw_cone(t_dir*, double*, t_obj*, t_lux *);
void		shdw_para(t_dir*, double*, t_obj*, t_lux *);
void		shdw_hyper(t_dir*, double*, t_obj*, t_lux *);
void		shdw_elli(t_dir*, double*, t_obj*, t_lux *);
void		shdw_tore(t_dir*, double*, t_obj*, t_lux *);
void		shdw_cube(t_dir*, double*, t_obj*, t_lux *);
void		shdw_dingdong(t_dir*, double*, t_obj*, t_lux *);
void		shdw_mobius(t_dir*, double*, t_obj*, t_lux *);
void		shdw_star(t_dir*, double*, t_obj*, t_lux *);
void		list_shdw(void(**)(t_dir*, double*, t_obj*, t_lux *));
void		get_biggest_dif_x(t_face_data *, double *, double *);
void		get_biggest_dif_y(t_face_data *, double *, double *);
void		get_biggest_dif_z(t_face_data *, double *, double *);
void		get_lim_box(t_face_data *, t_lim *);
int		my_put_end_list(t_list_pos **, t_pos *, t_pos *);
t_pos		norm_plan_lumin(t_lux *, t_obj *);
int		is_inter_plan(t_lux *, t_dir *);
void		load_xpm(t_data *, t_obj **);
void		launch_video(t_data *, t_ip *);
t_pos		get_img_pos(t_pos *, t_pos *, int, double);
t_k		get_k_tri(t_triangle *, t_pos *, t_pos *);
void		calc_list_pos_eye(t_video *, t_list_pos **, double, t_data *);
void		calc_list_pos(t_video *, t_list_pos **, t_obj *, double);
void		get_komplex(t_equ *, t_k *, t_ray_data *, t_obj *);
void		get_lum_komplex(t_equ *, t_k *, t_dir *, t_obj *);
int		get_pixel_color(t_data *, int, int);
void		set_i_j(int *, int *, int, int);
void		no_video(t_data *, t_ip *);
int		get_text_col(t_ray_data *);

#endif          /* !MY_H_ */
