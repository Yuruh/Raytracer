/*
** define_threads.h for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Fri Mar 27 14:29:10 2015 Adrien Vasseur
** Last update Sat Jun  6 15:17:48 2015 Raphael Thiebault
*/

#ifndef			DEFINE_THREADS_H_
# define		DEFINE_THREADS_H_

# define		NBR_THREAD	3
# define		ZONE_X		65
# define		ZONE_Y		65

typedef struct		s_my_task
{
  t_vec2i		pt;
  t_vec2i		size;
  struct s_my_task	*next;
}			t_my_task;

typedef struct		s_my_thread
{
  pthread_t		uid_pthread;
  unsigned int		uid;
  t_data		*data;
  t_my_task		**list;
}			t_my_thread;

int			up_in_x(t_vec2i *, int, t_data *, t_my_task **);
int			up_in_y(t_vec2i *, int, t_data *, t_my_task **);
int		        down_in_x(t_vec2i *, int, t_data *, t_my_task **);
int			down_in_y(t_vec2i *, int, t_data *, t_my_task **);

#endif /* !DEFINE_THREADS_H_ */
