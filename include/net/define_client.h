/*
** define_client.h for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer/pas_touche_vasseu_g_tests/client
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Tue Mar 24 00:55:23 2015 Adrien Vasseur
** Last update Sun Jun  7 18:05:17 2015 Adrien Vasseur
*/

#ifndef			DEFINE_CLIENT_H_
# define		DEFINE_CLIENT_H_

# define		NET_BUFFER_SIZE	524288

# define		PROTOCOL	1337

typedef	struct		s_task
{
  size_t		id;
  t_vec2i		pt;
  t_vec2i		size;
  struct s_task		*next;
}			t_task;

typedef	struct		s_scene
{
  size_t		id;
  t_data		*data;
  struct s_scene	*next;
}			t_scene;

typedef	struct		s_client
{
  fd_set		fs;
  struct timeval	timeout;
  int			my_socket;
  int			connected;
  char			*buff;
  size_t		buff_size;
  t_task		*tasks;
  t_scene		*scenes;
}			t_client;

#endif			/* !DEFINE_CLIENT_H_ */
