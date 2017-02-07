/*
** my_tasks.h for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Sat May 30 18:52:05 2015 Adrien Vasseur
** Last update Sun Jun  7 21:26:45 2015 Adrien Vasseur
*/

#ifndef		MY_TASKS_H_
# define	MY_TASKS_H_

t_task		*create_tasks(t_data *);
int		my_add_task(t_task **, t_data *, t_vec2i);
int		free_task(t_task **, t_task *);

#endif		/* !MY_TASKS_H_ */
