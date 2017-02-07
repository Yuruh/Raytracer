/*
** check_basic.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer/parsing_rt
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Tue Mar 17 16:14:16 2015 Antoine Zanardi
** Last update Wed May 20 16:52:01 2015 Antoine Zanardi
*/

#include	"define.h"
#include	"my.h"
#include	"check_basic.h"
#include	"fc_base.h"
#include	"fc_str.h"
#include	"error_parsing.h"

void		check_fill_def(t_def *def, t_data *data)
{
  if (def->anti == -1)
    def->anti = 1;
  if (def->width == -1)
    def->width = 1280;
  if (def->height == -1)
    def->height = 720;
  if (def->time <= 0.0)
    def->time = 3;
  data->a_a = def->anti;
  data->width = def->width;
  data->height = def->height;
  data->time = def->time;
}

void		check_end_line(char *str, int compt_str, int line)
{
  pass_spaces(str, &compt_str);
  if (str[compt_str] != '\n' && str[compt_str] != '\0'
      && str[compt_str] != '\r')
    my_putstr_error('c', line, 'b');
}
