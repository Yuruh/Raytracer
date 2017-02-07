/*
** menu.c for rt in /home/descam_d/rendu/IGRAPH/MUL_2014_rtracer/scene_editor
** 
** Made by Corentin Descamps
** Login   <descam_d@epitech.net>
** 
** Started on  Tue May 12 15:51:31 2015 Corentin Descamps
** Last update Sun Jun  7 21:41:50 2015 Corentin Descamps
*/

#include	<stdlib.h>
#include	<gtk/gtk.h>
#include	"data.h"
#include	"menu.h"
#include	"new_file.h"

void		menu_item_new(GtkMenu *Menu, const gchar *title,
			      GCallback callback, gpointer data)
{
  GtkWidget	*item;

  item = gtk_menu_item_new_with_mnemonic(title);
  gtk_menu_shell_append(GTK_MENU_SHELL(Menu), item);
  g_signal_connect(G_OBJECT(item), "activate", callback, data);
}

void		create_menu(GtkWidget *MenuBar, const gchar *title,
			    t_menu **list)
{
  GtkWidget	*Menu;
  GtkWidget	*MenuItem;
  t_menu	*tmp;

  Menu = gtk_menu_new();
  MenuItem = gtk_menu_item_new_with_mnemonic(title);
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(MenuItem), Menu);
  gtk_menu_shell_append(GTK_MENU_SHELL(MenuBar), MenuItem);
  tmp = *list;
  while (tmp)
    {
      menu_item_new(GTK_MENU(Menu), tmp->title, tmp->callback, tmp->data);
      tmp = tmp->next;
    }
}

void		file_bar(GtkWidget *MenuBar, t_data *data)
{
  t_menu	*file;

  file = NULL;
  add_stack(&file, "_Quitter", G_CALLBACK(gtk_main_quit), NULL);
  add_stack(&file, "_Nouveau", G_CALLBACK(new_file), data);
  create_menu(MenuBar, "_Fichier", &file);
}

int		menu_bar(t_data *data)
{
  GtkWidget	*MenuBar;

  MenuBar = gtk_menu_bar_new();
  gtk_grid_attach(GTK_GRID(data->table), MenuBar,
		  0, 0, 1, 1);
  file_bar(MenuBar, data);
  return (EXIT_SUCCESS);
}
