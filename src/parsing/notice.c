/*
** notice.c for rt in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtracer
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Thu Mar 19 13:46:16 2015 Antoine Zanardi
** Last update Sat Jun  6 18:44:13 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my.h"
#include	"notice.h"
#include	"cut_str.h"
#include	"fc_base.h"
#include	"parsing_rt.h"
#include	"parsing_obj.h"
#include	"error_parsing.h"
#include	"pass_x.h"
#include	"my_realloc.h"
#include	"error_obj.h"
#include	"my_free.h"

static int	notice_form(char *str)
{
  long		ret;
  int		fd;
  char		*buffer;
  char		*final;

  final = NULL;
  if ((buffer = malloc(sizeof(char) * BUFFER_SIZE + 1)) == NULL)
    my_putstr_error('b', 0, 0);
  open_file(my_strcat("notice/", str), &fd);
  while ((ret = read(fd, buffer, BUFFER_SIZE - 1)) != 0)
    {
      if (ret == -1)
	error_file(str);
      buffer[ret] = '\0';
      final = my_realloc(buffer, final);
    }
  if (final == NULL)
    return (1);
  my_putstr(final);
  close(fd);
  free_str(buffer);
  return (0);
}

static void	free_notice(char *final, int *fd, char *buffer)
{
  my_putstr(final);
  close(*fd);
  free_str(buffer);
}

int		my_notice(char *str)
{
  long		ret;
  int		fd;
  char		*buffer;
  char		*final;

  final = NULL;
  if (!str)
    {
      if ((buffer = malloc(sizeof(char) * BUFFER_SIZE + 1)) == NULL)
	my_putstr_error('b', 0, 0);
      open_file("notice/notice", &fd);
      while ((ret = read(fd, buffer, BUFFER_SIZE - 1)) != 0)
	{
	  if (ret == -1)
	    error_file("notice");
	  buffer[ret] = '\0';
	  final = my_realloc(buffer, final);
	}
      if (final == NULL)
	return (1);
      free_notice(final, &fd, buffer);
    }
  if (str != NULL && notice_form(str) == 1)
    return (1);
  exit(0);
}

int		my_help(void)
{
  my_putstr("How to launch the Raytracer.\n");
  my_putstr("./rt 'config_file' [-o 'output file'] [-i 'IP of the server']");
  my_putstr("[-p 'Port of the server'].\n");
  my_putstr("-o followed by a file_name export the result into a bmp.\n");
  my_putstr("--config -> Show you the notice.\n");
  my_putstr("--config [form] -> Show you the notice of the form.\n");
  exit(0);
}
