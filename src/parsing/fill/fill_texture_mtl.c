/*
** fill_texture_mtl.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Fri May  8 13:37:22 2015 Antoine Zanardi
** Last update Thu May 28 20:49:06 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"my.h"
#include	"object.h"
#include	"parsing_obj.h"
#include	"fill_texture_mtl.h"
#include	"cut_str.h"
#include	"pass_x.h"
#include	"my_free.h"
#include	"fc_str.h"
#include	"fc_base.h"
#include	"parsing_rt.h"
#include	"error_obj.h"

static char	*find_mtl_name(char *str)
{
  int		compt_str;

  compt_str = 0;
  pass_void(str, &compt_str, NULL);
  while (str[compt_str] != '\0')
    {
      pass_void(str, &compt_str, NULL);
      if (my_strncmp_on_s1("mtllib", str + compt_str) != 0)
	next_line(str, &compt_str, NULL);
      else
	{
	  compt_str += 6;
	  pass_spaces(str, &compt_str);
	  return (my_strdup(str, compt_str));
	}
    }
  return (NULL);
}

static char	*find_bmp_path(char *str)
{
  int		compt_str;

  compt_str = 0;
  pass_void(str, &compt_str, NULL);
  while (str[compt_str] != '\0')
    {
      pass_void(str, &compt_str, NULL);
      if (my_strncmp_on_s1("map_Kd", str + compt_str) != 0)
	next_line(str, &compt_str, NULL);
      else
	{
	  compt_str += 6;
	  pass_spaces(str, &compt_str);
	  return (my_strdup(str, compt_str));
	}
    }
  return (NULL);
}

void		fill_texture_mtl(t_obj *obj, char *str)
{
  char		*file_name_mtl;
  char		*mtl_content;
  char		*bmp_path;

  file_name_mtl = NULL;
  bmp_path = NULL;
  file_name_mtl = find_mtl_name(str);
  if (file_name_mtl == NULL)
    return ;
  if ((mtl_content = correct_file_obj(file_name_mtl)) == NULL)
    error_open_file();
  bmp_path = find_bmp_path(mtl_content);
  obj->texture.text_path = bmp_path;
}
