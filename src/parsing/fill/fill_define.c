/*
** fill_define.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed May  6 22:23:08 2015 Antoine Zanardi
** Last update Fri May 29 16:55:39 2015 Raphael Thiebault
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
#include	"my_free.h"

void		fill_aa(char *str, int compt_str, t_def *def, int line)
{
  compt_str += 3;
  pass_spaces(str, &compt_str);
  if (is_num(str + compt_str) == 1)
    my_putstr_error('c', line, 'm');
  if (def->anti != -1)
    my_putstr_error('c', line, 'n');
  def->anti = my_getnbr(str + compt_str);
  if (def->anti != 1 && def->anti != 2 && def->anti != 4)
    my_putstr_error('c', line, 'm');
  if (def->anti <= 0)
    my_putstr_error('c', line, 'm');
  pass_num(str, &compt_str);
  pass_spaces(str, &compt_str);
  if (str[compt_str] != '\n' && str[compt_str] != '\0')
    my_putstr_error('c', line, 'o');
}

void		fill_width(char *str, int compt_str, t_def *def, int line)
{
  compt_str += 5;
  pass_spaces(str, &compt_str);
  if (is_num(str + compt_str) == 1)
    my_putstr_error('c', line, 'p');
  if (def->width != -1)
    my_putstr_error('c', line, 'n');
  def->width = my_getnbr(str + compt_str);
  if (def->width <= 0)
    my_putstr_error('c', line, 'p');
  pass_num(str, &compt_str);
  pass_spaces(str, &compt_str);
  if (str[compt_str] != '\n' && str[compt_str] != '\0')
    my_putstr_error('c', line, 'o');
}

void		fill_height(char *str, int compt_str, t_def *def, int line)
{
  compt_str += 6;
  pass_spaces(str, &compt_str);
  if (is_num(str + compt_str) == 1)
    my_putstr_error('c', line, 'q');
  if (def->height != -1)
    my_putstr_error('c', line, 'n');
  def->height = my_getnbr(str + compt_str);
  if (def->height <= 0)
    my_putstr_error('c', line, 'q');
  pass_num(str, &compt_str);
  pass_spaces(str, &compt_str);
  if (str[compt_str] != '\n' && str[compt_str] != '\0')
    my_putstr_error('c', line, 'o');
}

void		fill_time_def(char *str, int compt_str, t_def *def, int line)
{
  compt_str += 4;
  pass_spaces(str, &compt_str);
  if (is_num(str + compt_str) == 1)
    my_putstr_error('c', line, 'A');
  if (def->time >= 0)
    my_putstr_error('c', line, 'n');
  def->time = atof(str + compt_str);
  if (def->time <= 0)
    my_putstr_error('c', line, 'A');
  pass_num(str, &compt_str);
  pass_spaces(str, &compt_str);
  if (str[compt_str] != '\n' && str[compt_str] != '\0')
    my_putstr_error('c', line, 'o');
}
