/*
** define.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Mon Mar 23 16:24:19 2015 Antoine Zanardi
** Last update Thu May 28 17:17:40 2015 Raphael Thiebault
*/

#include	<stdlib.h>
#include	"my.h"
#include	"is_x.h"
#include	"pass_x.h"
#include	"my_getnbr.h"
#include	"cut_str.h"
#include	"fc_base.h"
#include	"fc_str.h"
#include	"error_parsing.h"
#include	"define.h"
#include	"fill_obj_name.h"
#include	"fill_xpm_name.h"
#include	"my_free.h"

void		init_def(t_def *def, int *line)
{
  *line = 1;
  def->anti = -1;
  def->width = -1;
  def->height = -1;
  def->time = -1.0;
  def->name = NULL;
  def->xpm = NULL;
  def->video = NULL;
}

static void	which_define(char *str, int compt_str, t_def *def, int line)
{
  if (my_strncmp_on_s1("a_a", str + compt_str) == 0)
    fill_aa(str, compt_str, def, line);
  else if (my_strncmp_on_s1("width", str + compt_str) == 0)
    fill_width(str, compt_str, def, line);
  else if (my_strncmp_on_s1("height", str + compt_str) == 0)
    fill_height(str, compt_str, def, line);
  else if (my_strncmp_on_s1("obj", str + compt_str) == 0)
    fill_obj_name(str, compt_str, &(def->name), line);
  else if (my_strncmp_on_s1("xpm", str + compt_str) == 0)
    fill_xpm_name(str, compt_str, &(def->xpm), line);
  else if (my_strncmp_on_s1("video", str + compt_str) == 0)
    fill_video_list(str, compt_str, &(def->video), line);
  else if (my_strncmp_on_s1("time", str + compt_str) == 0)
    fill_time_def(str, compt_str, def, line);
  else
    my_putstr_error('c', line, 'l');
}

void		fill_define(char *str, int compt_str, t_def *def)
{
  int		line;

  init_def(def, &line);
  while (str[compt_str] != '\0')
    {
      pass_void(str, &compt_str, &line);
      if (my_strncmp_on_s1("#define", str + compt_str) != 0)
	pass_line(str, &compt_str, &line);
      else
	{
	  compt_str += 7;
	  pass_spaces(str, &compt_str);
	  which_define(str, compt_str, def, line);
	  pass_line(str, &compt_str, &line);
	}
    }
}
