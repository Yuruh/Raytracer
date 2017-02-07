/*
** parsing_rt.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer/parsing_rt
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Tue Mar 17 10:13:19 2015 Antoine Zanardi
** Last update Fri May 29 12:00:50 2015 Raphael Thiebault
*/

#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	"my.h"
#include	"fc_base.h"
#include	"parsing_obj.h"
#include	"parsing_rt.h"
#include	"check_basic.h"
#include	"check_def.h"
#include	"check_form.h"
#include	"check_pos.h"
#include	"check_rot_lim.h"
#include	"check_simple_num.h"
#include	"check_color.h"
#include	"check_percent.h"
#include	"check_focus.h"
#include	"check_id.h"
#include	"check_size.h"
#include	"check_xpm.h"
#include	"check_distorsion.h"
#include	"check_circonference.h"
#include	"check_video.h"
#include	"check_remplissage.h"
#include	"object.h"
#include	"go_parsing.h"
#include	"fill_obj_list.h"
#include	"fill_xpm_in_obj.h"
#include	"notice.h"
#include	"error_parsing.h"
#include	"error_obj.h"
#include	"my.h"
#include	"comments.h"
#include	"my_realloc.h"
#include	"parsing_rt.h"
#include	"parsing_video.h"
#include	"my_free.h"

char		*correct_file(char *file, t_def *def)
{
  long		ret;
  int		fd;
  char		*buffer;
  char		*final;

  final = NULL;
  if ((buffer = malloc(sizeof(char) * BUFFER_SIZE + 1)) == NULL)
    my_putstr_error('b', 0, 0);
  open_file(file, &fd);
  while ((ret = read(fd, buffer, BUFFER_SIZE - 1)) != 0)
    {
      if (ret == -1)
	error_file(file);
      buffer[ret] = '\0';
      final = my_realloc(buffer, final);
    }
  if (final == NULL)
    return (NULL);
  fill_define(final, 0, def);
  close(fd);
  free_str(buffer);
  return (erase_comment(final));
}

void		init_compt(int *line, int *compt_str, int *co_pa, t_bool *bool)
{
  *line = 1;
  *compt_str = 0;
  *co_pa = 0;
  bool->form = 0;
}

void		check_all(char *file, int line, int compt_param, t_def *def)
{
  check_def(file, line, 0, compt_param);
  check_form(file, line, compt_param, def);
  check_pos(file, line, compt_param, 0);
  check_h_lim(file, line, compt_param, 0);
  check_b_lim(file, line, compt_param, 0);
  check_rotate(file, line, compt_param, 0);
  check_rayon(file, line, compt_param, 0);
  check_angle(file, line, compt_param, 0);
  check_color(file, line, compt_param, 0);
  check_bri(file, line, compt_param, 0);
  check_reflex(file, line, compt_param, 0);
  check_trans(file, line, compt_param, 0);
  check_spec(file, line, compt_param, 0);
  check_remplissage(file, line, compt_param, 0);
  check_damier(file, line, compt_param, 0);
  check_focus(file, line, compt_param, 0);
  check_lumos(file, line, compt_param, 0);
  check_size(file, line, compt_param, 0);
  check_sheet(file, line, compt_param, 0);
  check_xpm(file, line, compt_param, def);
  check_distorsion(file, line, compt_param, 0);
  check_circonference(file, line, compt_param, 0);
  check_video(file, line, compt_param, def);
}

void		view_list(t_obj **obj)
{
  int		bool;
  t_obj		*tmp;

  tmp = *obj;
  bool = 0;
  while (tmp != NULL)
    {
      if (tmp->type == VIEW)
	bool++;
      tmp = tmp->next;
    }
  if (bool == 0)
    error_view('a');
  else if (bool > 1)
    error_view('b');
}

void		parsing_rt(char **argv, t_obj **obj, t_data *da, t_face_data **d)
{
  char		*file;
  int		line;
  int		compt_str;
  int		compt_param;
  t_bool	bool;
  t_def		def;

  init_compt(&line, &compt_str, &compt_param, &bool);
  file = correct_file(argv[1], &def);
  if (file == NULL)
    my_putstr_error('c', 1, 'a');
  check_fill_def(&def, da);
  check_id(&def);
  check_all(file, line, compt_param, &def);
  fill_obj_list(file, obj, &bool, line);
  if (def.xpm != NULL)
    fill_xpm_in_obj(obj, def.xpm);
  free_str(file);
  view_list(obj);
  exec_parsing_obj(def.name, d, obj);
  exec_parsing_vid(def.video, obj);
}
