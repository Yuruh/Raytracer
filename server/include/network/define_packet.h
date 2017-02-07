/*
** define_packet.h for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer/pas_touche_vasseu_g_tests
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Mon May 11 13:43:33 2015 Adrien Vasseur
** Last update Thu Jun  4 22:20:26 2015 Adrien Vasseur
*/

#ifndef		DEFINE_PACKET_H_
# define	DEFINE_PACKET_H_

# define	HELLOCONNECT_MESSAGE	1
# define	ASKSCENE_MESSAGE	2
# define	ASKTASK_MESSAGE		3
# define	SENDSCENE_MESSAGE	4
# define	RECVIDSCENE_MESSAGE	5
# define	NEWSCENE_MESSAGE	6
# define	NEWTASK_MESSAGE		7
# define	SENDRESULT_MESSAGE	8
# define	RECVRESULT_MESSAGE	9

typedef union	u_write_data
{
  long		m_long;
  int		m_int[2];
  char		m_char[8];
}		t_write_data;

typedef struct	s_packet
{
  t_write_data	id;
  t_write_data	size;
  char		*data;
}		t_packet;

#endif		/* !DEFINE_PACKET_H_ */
