/*
** my_lists.h for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer/parsing_rt
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed Mar 18 16:58:14 2015 Antoine Zanardi
** Last update Thu Mar 26 13:53:35 2015 Antoine Zanardi
*/

#ifndef		MY_LISTS_H_
# define	MY_LISTS_H_

# include	"my.h"
# include	"object.h"
# include	"define.h"

void		my_show_list(t_name *);
void		create_lists(t_lux **, t_obj *, t_obj **, t_obj **);
int		count_lux(t_lux *);
int		add_top_list(t_obj **);
int		add_exist_lux(t_lux **, t_obj *);
int		add_exist_list(t_obj **, t_obj *);

#endif		/* !MY_LISTS_H_ */
