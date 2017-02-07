/*
** fill_rolim.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Mon Mar 30 10:28:37 2015 Antoine Zanardi
** Last update Sat Jun  6 18:07:59 2015 Raphael Thiebault
*/

#include	<float.h>
#include	"my.h"
#include	"object.h"
#include	"parsing_rt.h"
#include	"fill_rolim.h"

void		rolim_h_lim(t_bool *bool, t_obj **obj)
{
  if (bool->h_lim == 0)
    {
      (*obj)->lim.top.x = DBL_MAX;
      (*obj)->lim.top.y = DBL_MAX;
      (*obj)->lim.top.z = DBL_MAX;
      (*obj)->lim.is_lim = 0;
    }
}

void		rolim_b_lim(t_bool *bool, t_obj **obj)
{
  if (bool->b_lim == 0)
    {
      (*obj)->lim.bot.x = -DBL_MAX;
      (*obj)->lim.bot.y = -DBL_MAX;
      (*obj)->lim.bot.z = -DBL_MAX;
      (*obj)->lim.is_lim = 0;
    }
}

void		rolim_rot(t_bool *bool, t_obj **obj)
{
  if (bool->rot == 0)
    {
      (*obj)->rot.x = 0.0;
      (*obj)->rot.y = 0.0;
      (*obj)->rot.z = 0.0;
    }
}

void		rolim_dis(t_bool *bool, t_obj **obj)
{
  if (bool->dis == 0)
    {
      (*obj)->dis.x = 1.0;
      (*obj)->dis.y = 1.0;
      (*obj)->dis.z = 1.0;
    }
}
