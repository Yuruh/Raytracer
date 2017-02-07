/*
** init_bool.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Tue May 26 15:02:06 2015 Antoine Zanardi
** Last update Thu May 28 15:09:42 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"my.h"
#include	"object.h"
#include	"parsing_rt.h"
#include	"init_bool.h"
#include	"error_parsing.h"

static void	bool_zero(t_bool *bool)
{
  bool->form = 0;
  bool->pos = 0;
  bool->rot = 0;
  bool->bri = 0;
  bool->trans = 0;
  bool->color = 0;
  bool->reflex = 0;
  bool->angle = 0;
  bool->rayon = 0;
  bool->h_lim = 0;
  bool->b_lim = 0;
  bool->damier = 0;
  bool->focus = 0;
  bool->size = 0;
  bool->xpm = 0;
  bool->video = 0;
  bool->dis = 0;
  bool->circonference = 0;
  bool->spec = 0;
  bool->rempli = 0;
  bool->lumos = 0;
  bool->sheet = 0;
}

void		init_bool(t_bool *bool, t_obj **obj)
{
  (*obj)->texture.text_path = NULL;
  (*obj)->xpm.xpm_path = NULL;
  (*obj)->texture.is_normale = 0;
  (*obj)->texture.is_texture = 0;
  (*obj)->lim.is_lim = 1;
  bool_zero(bool);
}
