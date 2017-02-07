/*
** my_texture.c for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Sun Jun  7 15:16:36 2015 Adrien Vasseur
** Last update Sun Jun  7 15:31:14 2015 Adrien Vasseur
*/

#include	<stdlib.h>
#include	"my.h"
#include	"net/my_texture.h"

static t_obj	*already_exist(t_obj *list, t_obj *acc)
{
  while (list != acc && list != NULL)
    {
      if (list->xpm.xpm == acc->xpm.xpm)
	return (list);
      list = list->next;
    }
  return (NULL);
}

unsigned int	net_tex_list(t_obj *list, t_obj *acc, int fd, int send)
{
  t_obj		*exist;
  unsigned int	size;
  unsigned int	img_size;

  size = 0;
  if (acc->xpm.xpm_path == NULL)
    return (size);
  size = sizeof(*(acc->xpm.xpm_img));
  if ((exist = already_exist(list, acc)) == NULL)
    {
      img_size = acc->xpm.xpm_img->height * acc->xpm.xpm_img->size_line;
      size += img_size;
    }
  if (send == 1)
    {
      write(fd, acc->xpm.xpm_img, sizeof(*(acc->xpm.xpm_img)));
      if (exist == NULL)
	write(fd, acc->xpm.xpm_img->data, img_size);
    }
  return (size);
}

void		net_tex_read(t_obj *list, t_obj *acc, char **data)
{
  t_obj		*exist;
  unsigned int	img_size;

  if (acc->xpm.xpm_path == NULL)
    return ;
  acc->xpm.xpm_img = (t_img *) (*data);
  acc->texture.img = (t_img *) (*data);
  (*data) += sizeof(*(acc->xpm.xpm_img));
  if ((exist = already_exist(list, acc)) == NULL)
    {
      img_size = acc->xpm.xpm_img->height * acc->xpm.xpm_img->size_line;
      acc->xpm.xpm_img->data = (*data);
      acc->texture.img->data = (*data);
      acc->texture.text_data = (*data);
      (*data) += img_size;
    }
  else
    {
      acc->xpm.xpm_img->data = exist->xpm.xpm_img->data;
      acc->texture.img->data = exist->texture.img->data;
      acc->texture.text_data = exist->texture.text_data;
    }
}
