/*
** modif.c for rtv in /home/lemper_a/rendu/igraph/MUL_2014_rtv1
**
** Made by Antoine LEMPEREUR
** Login   <lemper_a@epitech.net>
**
** Started on  Wed Feb  4 10:39:28 2015 Antoine LEMPEREUR
** Last update Thu May 28 14:38:44 2015 Antoine LEMPEREUR
*/

#include	<math.h>
#include	"calc.h"
#include	"modif.h"
#include	"my.h"

void		launch_modif(t_pos *eye, t_pos *vec, t_obj *obj)
{
  mod_pos(eye, &obj->pos, '-');
  if (obj->rot.x != 0.0 || obj->rot.y != 0.0 || obj->rot.z != 0.0)
    {
      go_rotate(&eye->x, &eye->y, &eye->z, &obj->rot);
      go_rotate(&vec->x, &vec->y, &vec->z, &obj->rot);
    }
}

int		mod_pos(t_pos *pos1, t_pos *pos2, char op)
{
  if (op == '+')
    {
      pos1->x += pos2->x;
      pos1->y += pos2->y;
      pos1->z += pos2->z;
    }
  else if (op == '-')
    {
      pos1->x -= pos2->x;
      pos1->y -= pos2->y;
      pos1->z -= pos2->z;
    }
  else
    return (-1);
  return (0);
}

int		rotate_x(double *y, double *z, double angle)
{
  double	sv_y;
  double	sv_z;

  sv_y = *y;
  sv_z = *z;
  *y = cos(angle) * sv_y - sin(angle) * sv_z;
  *z = sin(angle) * sv_y + cos(angle) * sv_z;
  return (0);
}

int		rotate_y(double *x, double *z, double angle)
{
  double	sv_x;
  double	sv_z;

  sv_x = *x;
  sv_z = *z;
  *x = cos(angle) * sv_x + sin(angle) * sv_z;
  *z = -1 * sin(angle) * sv_x + cos(angle) * sv_z;
  return (0);
}

int		rotate_z(double *x, double *y, double angle)
{
  double	sv_y;
  double	sv_x;

  sv_y = *y;
  sv_x = *x;
  *y = sin(angle) * sv_x + cos(angle) * sv_y;
  *x = cos(angle) * sv_x - sin(angle) * sv_y;
  return (0);
}
