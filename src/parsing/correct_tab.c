/*
** correct_tab.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Tue May  5 15:40:36 2015 Antoine Zanardi
** Last update Wed May 27 12:00:49 2015 Corentin Descamps
*/

#include	"my.h"
#include	"correct_tab.h"
#include	"pass_x.h"
#include	"fc_str.h"
#include	"fc_base.h"
#include	"check_tab.h"
#include	"error_parsing.h"

void		correct_tab_1(char *str, int *compt_str, int line)
{
  pass_spaces(str, compt_str);
  is_num_tab(str, *compt_str, line);
  pass_num(str, compt_str);
  if (str[*compt_str] != '/')
    my_putstr_error('d', line, 'b');
  (*compt_str)++;
  is_num_tab(str, *compt_str, line);
  pass_num(str, compt_str);
  if (str[*compt_str] != '/')
    my_putstr_error('d', line, 'b');
  (*compt_str)++;
  is_num_tab(str, *compt_str, line);
  pass_num(str, compt_str);
  pass_spaces(str, compt_str);
}

void		correct_tab_2(char *str, int *compt_str, int line)
{
  pass_spaces(str, compt_str);
  is_num_tab(str, *compt_str, line);
  pass_num(str, compt_str);
  if (str[*compt_str] != '/')
    my_putstr_error('d', line, 'b');
  (*compt_str)++;
  if (str[*compt_str] != '/')
    my_putstr_error('d', line, 'b');
  (*compt_str)++;
  is_num_tab(str, *compt_str, line);
  pass_num(str, compt_str);
  pass_spaces(str, compt_str);
}

void		correct_tab_3(char *str, int *compt_str, int line)
{
  pass_spaces(str, compt_str);
  is_num_tab(str, *compt_str, line);
  pass_num(str, compt_str);
  if (str[*compt_str] != '/')
    my_putstr_error('d', line, 'b');
  (*compt_str)++;
  is_num_tab(str, *compt_str, line);
  pass_num(str, compt_str);
  pass_spaces(str, compt_str);
}

void		correct_tab_4(char *str, int *compt_str, int line)
{
  pass_spaces(str, compt_str);
  is_num_tab(str, *compt_str, line);
  pass_num(str, compt_str);
  pass_spaces(str, compt_str);
}
