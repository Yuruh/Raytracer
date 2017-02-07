/*
** calc_video_pos.c for azer in /home/lemper_a/rendu/igraph/MUL_2014_rtracer
**
** Made by Antoine LEMPEREUR
** Login   <lemper_a@epitech.net>
**
** Started on  Mon Jun  1 13:22:49 2015 Antoine LEMPEREUR
** Last update Sat Jun  6 15:22:54 2015 Raphael Thiebault
*/

#include	"my.h"
#include	"modif.h"

t_pos		get_img_pos(t_pos *pos, t_pos *vid_pos, int i, double nb_img)
{
  t_pos		ret;

  ret.x = pos->x + (i / nb_img * (vid_pos->x - pos->x));
  ret.y = pos->y + (i / nb_img * (vid_pos->y - pos->y));
  ret.z = pos->z + (i / nb_img * (vid_pos->z - pos->z));
  return (ret);
}

t_dir		get_rot_pos_vid(t_dir *old_pos, t_video *tmp,
				int i, double nb_img)
{
  t_dir		ret;

  if (!tmp->rot_cent.bool)
    {
      ret.init = get_img_pos(&old_pos->init, &tmp->rot, i, nb_img);
      ret.vec = get_img_pos(&old_pos->vec, &tmp->pos, i, nb_img);
    }
  else
    {
      ret.vec = old_pos->vec;
      ret.init = get_img_pos(&old_pos->init, &tmp->rot_cent.ang, i, nb_img);
      rotate_x(&ret.vec.y, &ret.vec.z, tmp->rot_cent.ang.x * i / nb_img);
      rotate_y(&ret.vec.x, &ret.vec.z, tmp->rot_cent.ang.y * i / nb_img);
      rotate_z(&ret.vec.x, &ret.vec.y, tmp->rot_cent.ang.z * i / nb_img);
    }
  return (ret);
}

void		calc_list_pos_eye(t_video *vid, t_list_pos **list, double time,
                                  t_data *d)
{
  t_video	*tmp;
  int		i;
  t_dir		old_pos;
  t_dir		pos;
  double	nb_img;

  *list = NULL;
  old_pos.vec = d->eye;
  old_pos.init = d->rot;
  tmp = vid;
  while (tmp)
    {
      nb_img = (IMG_SEC * time * tmp->ratio);
      i = -1;
      while (++i < nb_img)
        {
	  pos = get_rot_pos_vid(&old_pos, tmp, i, nb_img);
	  my_put_end_list(list, &pos.vec, &pos.init);
        }
      old_pos.vec = pos.vec;
      old_pos.init = pos.init;
      tmp = tmp->next;
    }
}

void		calc_list_pos(t_video *vid, t_list_pos **list, t_obj *obj,
				  double time)
{
  t_video	*tmp;
  int		i;
  t_dir		old_pos;
  t_dir		pos;
  double	nb_img;

  *list = NULL;
  old_pos.vec = obj->pos;
  old_pos.init = obj->rot;
  tmp = vid;
  while (tmp)
    {
      nb_img = (IMG_SEC * time * tmp->ratio);
      i = -1;
      while (++i < nb_img)
        {
	  pos = get_rot_pos_vid(&old_pos, tmp, i, nb_img);
	  my_put_end_list(list, &pos.vec, &pos.init);
        }
      old_pos.vec = pos.vec;
      old_pos.init = pos.init;
      tmp = tmp->next;
    }
}
