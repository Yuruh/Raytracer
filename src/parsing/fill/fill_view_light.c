/*
** fill_view_light.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Tue May 26 14:02:59 2015 Antoine Zanardi
** Last update Wed May 27 11:57:36 2015 Corentin Descamps
*/

#include	<stdlib.h>
#include	"my.h"
#include	"object.h"
#include	"error_parsing.h"
#include	"error_obj.h"
#include	"fill_default.h"
#include	"parsing_rt.h"
#include	"fill_rolim.h"
#include	"fill_view_light.h"

void		fill_view(t_obj **obj, t_bool *bool)
{
  fill_rolim(obj, bool);
  if (bool->video == 0)
    (*obj)->video.id = -1;
  if (bool->bri > 0 || bool->trans > 0 || bool->color > 0 ||
      bool->reflex > 0 || bool->angle > 0 || bool->rayon > 0 ||
      bool->h_lim > 0 || bool->b_lim > 0 || bool->damier > 0 ||
      bool->focus > 0 || bool->size > 0 || bool->xpm > 0 || bool->dis > 0 ||
      bool->circonference > 0 || bool->spec > 0 || bool->rempli > 0 ||
      bool->lumos > 0 || bool->sheet > 0)
    error_setting(bool);
}

void		fill_light(t_obj **obj, t_bool *bool)
{
  if (bool->color == 0)
    (*obj)->src_col = 16777215;
  if (bool->video == 0)
    (*obj)->video.id = -1;
  if (bool->rot > 0 || bool->bri > 0 || bool->trans > 0 ||
      bool->bri > 0 || bool->trans > 0 || bool->reflex > 0 ||
      bool->angle > 0 || bool->rayon > 0 || bool->h_lim > 0 ||
      bool->b_lim > 0 || bool->damier > 0 || bool->focus > 0 ||
      bool->size > 0 || bool->xpm > 0 || bool->dis > 0 ||
      bool->circonference > 0 || bool->spec > 0 || bool->rempli > 0 ||
      bool->lumos > 0 || bool->sheet > 0)
    error_setting(bool);
}
