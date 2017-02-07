/*
** fill_video_list.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Tue May 19 00:24:11 2015 Antoine Zanardi
** Last update Thu May 28 18:21:30 2015 Raphael Thiebault
*/

#include	<stdlib.h>
#include	"my.h"
#include	"parsing_video.h"
#include	"error_parsing.h"
#include	"object.h"
#include	"my_free.h"
#include	"fc_base.h"
#include	"fc_str.h"
#include	"cut_str.h"
#include	"fill_video_list.h"
#include	"fill_time.h"
#include	"fill_pos_video.h"
#include	"fill_rot_centrale.h"
#include	"video_list.h"

static int	video_to_fill(char *str, int compt, t_video **list)
{
  if (my_strncmp_on_s1("TIME:", str + compt) == 0)
    fill_time(str, compt, list);
  else if (my_strncmp_on_s1("POS:", str + compt) == 0)
    fill_pos_video(str, compt, list);
  else if (my_strncmp_on_s1("ROTATE:", str + compt) == 0)
    fill_rot_video(str, compt, list);
  else if (my_strncmp_on_s1("ROT_CENT:", str + compt) == 0)
    fill_rot_centrale(str, compt, list);
  else
    return (1);
  return (0);
}

void		fill_video_li(char *str, t_video **list, int line)
{
  int		compt_str;

  compt_str = 0;
  pass_void(str, &compt_str, &line);
  while (str[compt_str] != '\0')
    {
      add_bot_video(list);
      next_line(str, &compt_str, &line);
      while (my_strncmp_on_s1("</VID>", str + compt_str) != 0)
	{
	  if (video_to_fill(str, compt_str, list) == 1)
	    my_putstr_error('e', line, 'i');
	  next_line(str, &compt_str, &line);
	}
      next_line(str, &compt_str, &line);
    }
}
