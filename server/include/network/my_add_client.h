/*
** my_add_client.h for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer/pas_touche_vasseu_g_tests/server
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Tue Mar 31 00:07:40 2015 Adrien Vasseur
** Last update Sun Jun  7 21:51:42 2015 Adrien Vasseur
*/

#ifndef		MY_ADD_CLIENT_H_
# define	MY_ADD_CLIENT_H_

int		my_add_client(t_socket **, t_socket *);
int		my_rem_client(t_socket **, t_socket *, t_scene *);
int		my_free_client(t_socket **);

#endif		/* !MY_ADD_CLIENT_H_ */
