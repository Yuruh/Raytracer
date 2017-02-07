/*
** my_reader.h for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Wed Jun  3 23:49:50 2015 Adrien Vasseur
** Last update Fri Jun  5 15:25:37 2015 Adrien Vasseur
*/

#ifndef		MY_READER_H_
# define	MY_READER_H_

unsigned int	net_read_uint(char **);
t_list_pos	*net_pos_read(char **);
t_obj		*net_obj_read(char **);
t_lux		*net_lux_read(char **);

#endif		/* !MY_READER_H_ */
