/*
** fill_time.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Tue May 19 00:41:04 2015 Antoine Zanardi
** Last update Wed May 27 11:56:14 2015 Corentin Descamps
*/

#include	<stdlib.h>
#include	"my.h"
#include	"pass_x.h"
#include	"fc_str.h"
#include	"fill_percent.h"
#include	"my_getnbr.h"
#include	"object.h"
#include	"parsing_rt.h"
#include	"fill_time.h"

void		fill_time(char *str, int compt_str, t_video **video)
{
  t_video	*tmp;

  tmp = *video;
  while (tmp->next != NULL)
    tmp = tmp->next;
  pass_label(str, &compt_str);
  tmp->ratio = get_percent(str, compt_str);
}
