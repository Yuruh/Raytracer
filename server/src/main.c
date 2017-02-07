/*
** main.c for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer/pas_touche_vasseu_g_tests/server
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Mon Mar 23 20:01:56 2015 Adrien Vasseur
** Last update Sun Jun  7 18:19:50 2015 Adrien Vasseur
*/

#include		<stdlib.h>
#include		<signal.h>
#include		"network/define_server.h"
#include		"network/my_server.h"
#include		"network/my_server_signal.h"

char			g_running;

int			main(void)
{
  unsigned short	port;

  port = 2300;
  signal(SIGINT, &my_ctrl_c);
  signal(SIGPIPE, SIG_IGN);
  return (my_server(port));
}
