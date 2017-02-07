/*
** init.c for rtv in /home/lemper_a/rendu/igraph/MUL_2014_rtv1
**
** Made by Antoine LEMPEREUR
** Login   <lemper_a@epitech.net>
**
** Started on  Wed Feb  4 10:21:30 2015 Antoine LEMPEREUR
** Last update Sun Jun  7 00:22:09 2015 Adrien Vasseur
*/

#include	<stdlib.h>
#include	"mlx.h"
#include	"my.h"
#include	"init.h"
#include	"triangle.h"
#include	"my_lib.h"
#include	"parsing_rt.h"
#include	"go_parsing.h"
#include	"my_lists.h"
#include	"bmp/bmp_importer.h"

void		list_inter(void (**do_inter)(t_ray_data*, t_obj*, t_k*))
{
  do_inter[0] = inter_plan;
  do_inter[1] = inter_sphere;
  do_inter[2] = inter_cyl;
  do_inter[3] = inter_cone;
  do_inter[4] = inter_para;
  do_inter[5] = inter_hyper;
  do_inter[6] = inter_elli;
  do_inter[7] = inter_tore;
  do_inter[8] = inter_cube;
  do_inter[9] = inter_dingdong;
  do_inter[10] = inter_stellar;
  do_inter[11] = inter_mobius;
}

void		list_norm(void (**do_norm)(t_ray_data*, t_pos*))
{
  do_norm[0] = norm_plan;
  do_norm[1] = norm_sphere;
  do_norm[2] = norm_cyl;
  do_norm[3] = norm_cone;
  do_norm[4] = norm_para;
  do_norm[5] = norm_hyper;
  do_norm[6] = norm_elli;
  do_norm[7] = norm_tore;
  do_norm[8] = norm_cube;
  do_norm[9] = norm_dingdong;
  do_norm[10] = norm_star;
  do_norm[11] = norm_mobius;
}

static void	init_mlx_data(t_data *d)
{
  int		i;

  i = -1;
  if (!(d->win.data = malloc(sizeof(*(d->win.data)) * d->time * IMG_SEC)))
    my_exit("Could not alloc\n");
  if (!(d->win.img = malloc(sizeof(*(d->win.img)) * d->time * IMG_SEC)))
    my_exit("Could not alloc\n");
  d->win.win = mlx_new_window(d->win.mlx, d->width, d->height, "RayTracer");
  while (++i < d->time * 24)
    {
      d->win.img[i] = mlx_new_image(d->win.mlx, d->width, d->height);
      d->win.data[i] = mlx_get_data_addr(d->win.img[i], &(d->win.bpp),
				       &(d->win.size_line), &(d->win.endian));
    }
}

static void	get_input(t_data *d, t_arg *arg)
{
  t_obj		*only_obj;
  t_obj		*obj;
  t_obj		*view;
  t_face_data	*tri;
  t_lux		*light;

  obj = NULL;
  view = NULL;
  tri = NULL;
  light = NULL;
  only_obj = NULL;
  d->video.id = -1;
  go_parsing(&obj, arg, d, &tri);
  create_lists(&light, obj, &view, &only_obj);
  if (tri != NULL)
    put_tri_in_list(&only_obj, tri);
  d->obj = only_obj;
  d->nb_light = count_lux(light);
  d->lux = light;
  d->eye = view->pos;
  d->rot = view->rot;
  if (view->video.id != -1)
    d->video = view->video;
  if (only_obj != NULL)
    load_xpm(d, &(d->obj));
}

void		panel_init(t_data *d, int ac, char **av, t_arg *arg)
{
  if (!(d->do_inter = malloc(sizeof(void*) * 12)) ||
      !(d->do_shdw = malloc(sizeof(void*) * 12)) ||
      !(d->do_norm = malloc(sizeof(void*) * 12)))
    my_exit("Could not alloc\n");
  arg->argc = ac;
  arg->argv = av;
  d->list_pos = NULL;
  if (!(d->win.mlx = mlx_init()))
    my_exit("I need the environment!\n");
  get_input(d, arg);
  init_mlx_data(d);
  list_inter(d->do_inter);
  list_norm(d->do_norm);
  list_shdw(d->do_shdw);
  d->blur = get_blur_tab(d->width, d->height);
  d->is_paused = 0;
  d->has_win = 1;
}
