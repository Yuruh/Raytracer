/*
** parsing_obj.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer/parsing
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Thu Mar 26 09:21:22 2015 Antoine Zanardi
** Last update Sun Jun  7 11:11:33 2015 Antoine Zanardi
*/

#include	<sys/stat.h>
#include	<fcntl.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"my.h"
#include	"object.h"
#include	"comments.h"
#include	"error_parsing.h"
#include	"error_obj.h"
#include	"fc_str.h"
#include	"parsing_rt.h"
#include	"parsing_obj.h"
#include	"check_points.h"
#include	"check_normale.h"
#include	"check_texture.h"
#include	"check_tab.h"
#include	"fc_base.h"
#include	"fill_points_tab.h"
#include	"fill_obj_tab.h"
#include	"my_realloc.h"
#include	"my_free.h"
#include	"fill_normale_tab.h"
#include	"fill_texture_tab.h"
#include	"fill_texture_mtl.h"

int		open_file(char *file, int *fd)
{
  if ((*fd = open(file, O_RDONLY)) == -1)
    {
      my_putstr("File ");
      my_putstr(file);
      my_putstr(" not accessible.\n");
      exit(1);
    }
  return (0);
}

char		*correct_file_obj(char *file)
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
	{
	  my_putstr(file);
	  my_putstr(" not readable.\n");
	  exit(1);
	}
      buffer[ret] = '\0';
      final = my_realloc(buffer, final);
    }
  if (final == NULL)
    return (NULL);
  free_str(buffer);
  close(fd);
  return (erase_comment(final));
}

static void	init_obj_elem(t_face_data *elem, t_obj *obj, char *str)
{
  elem->pos.x = obj->pos.x;
  elem->pos.y = obj->pos.y;
  elem->pos.z = obj->pos.z;
  elem->rot = obj->rot;
  elem->color = obj->src_col;
  elem->cons = obj->cons;
  elem->size = obj->lon.size;
  elem->is_normale = 0;
  elem->is_texture = 0;
  fill_texture_mtl(obj, str);
  elem->text_path = obj->texture.text_path;
}

static void	parsing_obj(char *file_name, t_face_data **triangle, t_obj *obj)
{
  char		*str;
  t_coor	coor;
  t_face_data	*elem;

  if ((str = correct_file_obj(file_name)) == NULL)
    error_open_file();
  if ((elem = malloc(sizeof(t_face_data))) == NULL)
    my_putstr_error('b', 0, 0);
  init_obj_elem(elem, obj, str);
  check_point(str);
  check_normal(str, elem);
  check_texture(str, elem);
  check_tab(str, elem);
  coor.point = fill_points_tab(str);
  coor.normale = fill_normale_tab(str);
  coor.texture = fill_texture_tab(str);
  fill_tab(str, elem, &coor);
  elem->next = *triangle;
  *triangle = elem;
  free_str(str);
}

void		exec_parsing_obj(t_name *name, t_face_data **tri, t_obj **obj)
{
  t_obj		*tmp_obj;
  t_name	*tmp;

  tmp = name;
  while (tmp != NULL)
    {
      tmp_obj = *obj;
      while (tmp_obj != NULL)
	{
	  if (tmp_obj->type == IGN &&
	      (unsigned int)tmp_obj->damier_col == tmp->id)
	    parsing_obj(tmp->name, tri, tmp_obj);
	  tmp_obj = tmp_obj->next;
	}
      tmp = tmp->next;
    }
}
