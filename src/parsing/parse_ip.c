/*
** parse_ip.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Sat Jun  6 12:00:47 2015 Antoine Zanardi
** Last update Sat Jun  6 14:33:43 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	<string.h>
#include	"parse_ip.h"
#include	"is_x.h"
#include	"my_getnbr.h"

void		parse_ip(t_ip *ip, char **argv)
{
  int		compt_argv;

  compt_argv = 1;
  ip->ip = NULL;
  ip->port = 0;
  while (argv[compt_argv] != NULL)
    {
      if (strcmp("-i", argv[compt_argv]) == 0)
	ip->ip = argv[compt_argv + 1];
      if (strcmp("-p", argv[compt_argv]) == 0)
	if (argv[compt_argv + 1] != NULL &&
	    is_num_posi(argv[compt_argv + 1]) == 0)
	  ip->port = my_getnbr(argv[compt_argv + 1]);
      compt_argv++;
    }
}
