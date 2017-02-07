/*
** my_getnbr_hexa.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer/parsing_rt
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed Mar 18 23:47:01 2015 Antoine Zanardi
** Last update Thu Mar 19 00:09:53 2015 Antoine Zanardi
*/

#include	"my_getnbr_hexa.h"

int		my_getnbr_hexa(char *str)
{
  int		compt_str;
  int		nbr;

  compt_str = -1;
  nbr = 0;
  while ((str[++compt_str] >= '0' && str[compt_str] <= '9') ||
	 (str[compt_str] >= 'A' && str[compt_str] <= 'F'))
    {
      nbr = nbr * 16;
      if (str[compt_str] == 'A')
	nbr = nbr + (58 - '0');
      else if (str[compt_str] == 'B')
	nbr = nbr + (59 - '0');
      else if (str[compt_str] == 'C')
	nbr = nbr + (60 - '0');
      else if (str[compt_str] == 'D')
	nbr = nbr + (61 - '0');
      else if (str[compt_str] == 'E')
	nbr = nbr + (62 - '0');
      else if (str[compt_str] == 'F')
	nbr = nbr + (63 - '0');
      else
	nbr = nbr + (str[compt_str] - '0');
    }
  return (nbr);
}
