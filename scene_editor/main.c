/*
** main.c for rt in /home/descam_d/rendu/IGRAPH/MUL_2014_rtracer/scene_editor
** 
** Made by Corentin Descamps
** Login   <descam_d@epitech.net>
** 
** Started on  Mon May 11 19:18:43 2015 Corentin Descamps
** Last update Wed Jun  3 12:04:28 2015 Corentin Descamps
*/

#include	<stdlib.h>
#include	<gtk/gtk.h>
#include	"data.h"
#include	"menu.h"
#include	"define.h"

t_def		g_def;

int		main(int argc, char **argv)
{
  t_data	data;

  gtk_init(&argc, &argv);
  data.MainWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(data.MainWindow), "Scene Editor");
  gtk_window_set_default_size(GTK_WINDOW(data.MainWindow), 800, 600);
  gtk_window_set_position(GTK_WINDOW(data.MainWindow), GTK_WIN_POS_CENTER);
  g_signal_connect(G_OBJECT(data.MainWindow), "destroy",
		   G_CALLBACK(gtk_main_quit), NULL);
  data.table = gtk_grid_new();
  gtk_container_add(GTK_CONTAINER(data.MainWindow), data.table);
  menu_bar(&data);
  gtk_widget_show_all(data.MainWindow);
  gtk_main();
  return (EXIT_SUCCESS);
}
