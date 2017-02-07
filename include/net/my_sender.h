/*
** my_sender.h for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Sat May 30 01:38:35 2015 Adrien Vasseur
** Last update Sun Jun  7 15:17:14 2015 Adrien Vasseur
*/

#ifndef		MY_SENDER_H_
# define	MY_SENDER_H_

unsigned int	net_pos_list(t_list_pos *, int, int);
unsigned int	net_tri_list(t_triangle *, int, int);
unsigned int	net_lux_list(t_lux *, int, int);
unsigned int	net_obj_list(t_obj *, int, int);

#endif		/* !MY_SENDER_H_ */
