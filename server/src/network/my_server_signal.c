/*
** my_server_signal.c for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer/pas_touche_vasseu_g_tests/server
** 
** Made by Adrien Vasseur
** Login   <vasseu_g@epitech.net>
** 
** Started on  Mon Mar 30 09:29:54 2015 Adrien Vasseur
** Last update Wed May 27 09:50:20 2015 Adrien Vasseur
*/

#include	<stdio.h>
#include	<signal.h>
#include	"network/define_server.h"
#include	"network/my_server_signal.h"

void		my_ctrl_c(int sig)
{
  printf("\n");
  if (sig == SIGINT)
    g_running = 1;
}
