/*
** find_video_list.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed May 20 18:15:07 2015 Antoine Zanardi
** Last update Thu May 28 18:13:46 2015 Antoine LEMPEREUR
*/

#include	<stdlib.h>
#include	"my.h"
#include	"object.h"
#include	"find_video_list.h"

int		is_video_list(t_obj **obj, t_lux **lux)
{
  t_lux		*tmp_lux;
  t_obj		*tmp;

  tmp = *obj;
  if (*lux == NULL || *obj == NULL)
    return (EXIT_FAILURE);
  while (tmp->next != NULL)
    {
      if (tmp->type != OBJ && tmp->video.id != -1)
	return (EXIT_SUCCESS);
      tmp = tmp->next;
    }
  tmp_lux = *lux;
  while (tmp_lux->next != NULL)
    {
      if (tmp_lux->video.id != -1)
	return (EXIT_SUCCESS);
      tmp_lux = tmp_lux->next;
    }
  return (EXIT_FAILURE);
}
