/*
** parse_ip.h for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Sat Jun  6 11:56:05 2015 Antoine Zanardi
** Last update Sat Jun  6 18:44:57 2015 Antoine Zanardi
*/

#ifndef		PARSE_IP_H_
# define	PARSE_IP_H_

typedef struct	s_ip
{
  char		*ip;
  unsigned int	port;
}		t_ip;

void		parse_ip(t_ip *, char **);

#endif		/* !PARSE_IP_H_ */
