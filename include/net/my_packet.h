/*
** my_packet.h for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer/pas_touche_vasseu_g_tests/client/include/network
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Mon May 11 22:54:43 2015 Adrien Vasseur
** Last update Mon Jun  1 18:41:06 2015 Adrien Vasseur
*/

#ifndef		MY_PACKET_H_
# define	MY_PACKET_H_

int		new_packet(char *, size_t);
int		treat_packet(t_client *, t_packet *);
int		recv_packet(t_client *, t_packet *);
int		send_packet(int, t_packet *);

#endif		/* !MY_PACKET_H_ */
