/*
** main.c for azer in /home/lemper_a/rendu/MUL_2014_wolf3d
**
** Made by Antoine LEMPEREUR
** Login   <lemper_a@epitech.net>
**
** Started on  Tue Nov 25 11:32:40 2014 Antoine LEMPEREUR
** Last update Sun Jun  7 22:28:18 2015 Raphael Thiebault
*/

#include	<sys/time.h>
#include	<stdlib.h>
#include	<string.h>
#include	"my.h"
#include	"parsing/parsing_rt.h"
#include	"net/my_client.h"
#include	"init.h"
#include	"find_video_list.h"
#include	"bmp/bmp_exporter.h"

static int	gere_expose(t_data *d)
{
  mlx_put_image_to_window(d->win.mlx, d->win.win,
			  d->win.img[d->count_img], 0, 0);
  return (0);
}

static int	gere_key(int key, t_data *d)
{
  if (key == 65307)
    exit(1);
  if (key == 32)
    {
      if (d->is_paused == 0)
	d->is_paused = 1;
      else
	d->is_paused = 0;
    }
  return (0);
}

void		list_shdw(void (**do_shdw)(t_dir*, double*, t_obj*, t_lux *))
{
  do_shdw[0] = shdw_plan;
  do_shdw[1] = shdw_sphere;
  do_shdw[2] = shdw_cyl;
  do_shdw[3] = shdw_cone;
  do_shdw[4] = shdw_para;
  do_shdw[5] = shdw_hyper;
  do_shdw[6] = shdw_elli;
  do_shdw[7] = shdw_tore;
  do_shdw[8] = shdw_cube;
  do_shdw[9] = shdw_dingdong;
  do_shdw[10] = shdw_star;
  do_shdw[11] = shdw_mobius;
}

int		gere_loop(t_data *d)
{
  static struct timeval	old;
  struct timeval	value;
  int		wait;

  if (old.tv_usec == 0)
    gettimeofday(&old, NULL);
  wait = 1000000 / IMG_SEC;
  gettimeofday(&value, NULL);
  if (value.tv_usec > old.tv_usec + wait || value.tv_sec > old.tv_sec)
    {
      mlx_put_image_to_window(d->win.mlx, d->win.win,
			      d->win.img[d->count_img], 0, 0);
      if (d->is_paused == 0)
	d->count_img++;
      if (d->count_img == d->time * IMG_SEC)
	d->count_img = 0;
      gettimeofday(&old, NULL);
    }
  return (0);
}

int		main(int ac, char **av)
{
  t_data	d;
  t_arg		arg;
  t_ip		ip;

  parse_ip(&ip, av);
  if (ac > 1 && strcmp("--silent", av[1]) == 0)
    return (my_client(&ip, NULL));
  panel_init(&d, ac, av, &arg);
  d.count_img = 0;
  if (d.obj != NULL && (is_video_list(&(d.obj), &(d.lux)) == EXIT_SUCCESS ||
			d.video.id != -1))
    launch_video(&d, &ip);
  else
    no_video(&d, &ip);
  d.count_img = 0;
  if (arg.o == 1)
    bmp_exporter(arg.bmp, &(d.win), &d);
  mlx_key_hook(d.win.win, gere_key, &d);
  mlx_expose_hook(d.win.win, gere_expose, &d);
  mlx_put_image_to_window(d.win.mlx, d.win.win, d.win.img[d.count_img], 0, 0);
  if (d.obj != NULL && (is_video_list(&(d.obj), &(d.lux)) == EXIT_SUCCESS ||
			d.video.id != -1))
    mlx_loop_hook(d.win.mlx, gere_loop, &d);
  mlx_loop(d.win.mlx);
  return (EXIT_SUCCESS);
}
