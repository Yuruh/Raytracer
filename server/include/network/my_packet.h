/*
** my_packet.h for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer/pas_touche_vasseu_g_tests/server/include/network
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Wed May 27 09:45:53 2015 Adrien Vasseur
** Last update Thu Jun  4 16:44:32 2015 Adrien Vasseur
*/

#ifndef		MY_PACKET_H_
# define	MY_PACKET_H_

int		new_packet(t_socket *);
int		recv_packet(t_socket *, t_packet *);
int		treat_packet(t_socket *, t_packet *, t_scene **);
int		send_packet(int, t_packet *);

#endif		/* !MY_PACKET_H_ */
