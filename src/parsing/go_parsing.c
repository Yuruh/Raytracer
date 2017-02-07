/*
** main.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer/parsing_rt
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Tue Mar 17 10:11:52 2015 Antoine Zanardi
** Last update Thu Jun  4 13:42:55 2015 Raphael Thiebault
*/

#include	<stdlib.h>
#include	"my.h"
#include	"fc_str.h"
#include	"error_parsing.h"
#include	"error_obj.h"
#include	"go_parsing.h"
#include	"parsing_rt.h"
#include	"notice.h"
#include	"my_lists.h"
#include	"bmp/bmp_importer.h"

void		output_bmp(char **argv, int compt_arg, t_arg *arg)
{
  if (compt_arg == 1 || argv[compt_arg + 1] == NULL ||
      argv[compt_arg + 1][0] == '\0')
    error_view('c');
  arg->o++;
  arg->bmp = argv[compt_arg + 1];
}

void		check_argv(int argc, char **argv, t_arg *arg)
{
  int		compt_arg;

  compt_arg = 1;
  arg->o = 0;
  if (argc < 2)
    my_putstr_error('a', 0, 0);
  while (argv[compt_arg] != '\0')
    {
      if (my_strcmp_exact("--config", argv[compt_arg], 0) == 0)
	my_notice(argv[compt_arg + 1]);
      else if (my_strcmp_exact("--help", argv[compt_arg], 0) == 0)
	my_help();
      else if (my_strcmp_exact("-o", argv[compt_arg], 0) == 0)
	output_bmp(argv, compt_arg, arg);
      compt_arg++;
    }
  if (arg->o > 1)
    error_view('c');
}

void		go_parsing(t_obj **obj, t_arg *arg, t_data *da, t_face_data **d)
{
  t_face_data	*tmp;
  int		buff;

  check_argv(arg->argc, arg->argv, arg);
  parsing_rt(arg->argv, obj, da, d);
  tmp = *d;
  while (tmp != NULL)
    {
      if (tmp->text_path != NULL)
	{
	  tmp->img = bmp_importer(da, tmp->text_path);
          tmp->text_data = mlx_get_data_addr(tmp->img, &buff, &buff, &buff);
	}
      tmp = tmp->next;
    }
}
