/*
** define_server.h for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer/pas_touche_vasseu_g_tests/server
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Thu Mar 26 09:48:17 2015 Adrien Vasseur
** Last update Sun Jun  7 18:05:22 2015 Adrien Vasseur
*/

#ifndef			DEFINE_SERVER_H_
# define		DEFINE_SERVER_H_

# include		<netinet/in.h>
# include		"my.h"

# define		BUFFER_SIZE	524288

# define		PROTOCOL	1337

# define		CONNECTING	0
# define		WAITING		1
# define		WORKING		2

# define		FREE		0
# define		GIVEN		1

# define		ZONE_X		65
# define		ZONE_Y		65

typedef	struct		s_socket
{
  fd_set		fs;
  struct timeval	timeout;
  struct sockaddr_in	addr;
  struct s_socket	*next;
  char			*buff;
  size_t		buff_size;
  int			socket;
  int			state;
  int			connected;
  struct s_socket	**all;
}			t_socket;

typedef	struct		s_task
{
  size_t		state;
  t_vec2i		pt;
  t_vec2i		size;
  struct s_task		*next;
}			t_task;

typedef	struct		s_scene
{
  size_t		id;
  char			*raw;
  size_t		raw_size;
  t_data		*data;
  t_task		*tasks;
  t_socket		*client;
  struct s_scene	*next;
}			t_scene;

extern	char		g_running;

#endif			/* !DEFINE_SERVER_H_ */
