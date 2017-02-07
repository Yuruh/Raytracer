/*
** pass_x.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer/parsing_rt
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed Mar 18 09:53:45 2015 Antoine Zanardi
** Last update Thu May  7 16:46:46 2015 Antoine Zanardi
*/

#include	"fc_base.h"
#include	"fc_str.h"
#include	"pass_x.h"

void		pass_label(char *str, int *compt_str)
{
  while ((str[*compt_str] >= 'A' && str[*compt_str] <= 'Z') ||
	 str[*compt_str] == '_')
    (*compt_str)++;
  if (str[*compt_str] == ':')
    (*compt_str)++;
  pass_spaces(str, compt_str);
}

void		pass_num(char *str, int *compt_str)
{
  if (str[*compt_str] == '-')
    (*compt_str)++;
  while (str[*compt_str] >= '0' && str[*compt_str] <= '9')
    (*compt_str)++;
}

void		pass_percent(char *str, int *compt_str)
{
  while (str[*compt_str] >= '0' && str[*compt_str] <= '9')
    (*compt_str)++;
  (*compt_str)++;
}

void		pass_double(char *str, int *compt_str)
{
  if (str[*compt_str] == '-')
    (*compt_str)++;
  while (str[*compt_str] >= '0' && str[*compt_str] <= '9')
    (*compt_str)++;
  if (str[*compt_str] == '.')
    (*compt_str)++;
  while (str[*compt_str] >= '0' && str[*compt_str] <= '9')
    (*compt_str)++;
}
