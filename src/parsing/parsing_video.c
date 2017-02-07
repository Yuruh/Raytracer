/*
** parsing_video.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Mon May 18 22:31:00 2015 Antoine Zanardi
** Last update Wed May 27 11:50:26 2015 Corentin Descamps
*/

#include	<stdlib.h>
#include	"my.h"
#include	"object.h"
#include	"parsing_rt.h"
#include	"parsing_obj.h"
#include	"parsing_video.h"
#include	"check_balise_vid.h"
#include	"check_percent_time.h"
#include	"check_translation.h"
#include	"check_rotate_video.h"
#include	"fill_video_list.h"
#include	"check_sum_time.h"
#include	"check_rotate_centrale.h"
#include	"error_obj.h"

static void	parsing_video(char *file_name, t_obj *obj)
{
  char		*str;

  obj->video.list = NULL;
  if ((str = correct_file_obj(file_name)) == NULL)
    error_open_file();
  check_balise_vid(str, 1, 0, 0);
  check_percent_time(str, 1, 0, 0);
  check_translation(str, 1, 0, 0);
  check_rotate_video(str, 1, 0, 0);
  check_rotate_centrale(str, 1, 0, 0);
  fill_video_li(str, &(obj->video.list), 1);
  check_sum_time(&(obj->video.list));
}

void		exec_parsing_vid(t_xpm *video, t_obj **obj)
{
  t_obj		*tmp_obj;
  t_xpm		*tmp_vid;

  tmp_vid = video;
  while (tmp_vid != NULL)
    {
      tmp_obj = *obj;
      while (tmp_obj != NULL)
	{
	  if ((tmp_obj->video.id) == (int)tmp_vid->id)
	    parsing_video(tmp_vid->xpm, tmp_obj);
	  tmp_obj = tmp_obj->next;
	}
      tmp_vid = tmp_vid->next;
    }
}
