##
## Makefile for rt in /home/descam_d/rendu/IGRAPH/MUL_2014_rtracer/scene_editor
## 
## Made by Corentin Descamps
## Login   <descam_d@epitech.net>
## 
## Started on  Mon May 11 19:20:02 2015 Corentin Descamps
## Last update Sun Jun  7 21:35:03 2015 Corentin Descamps
##

NAME	=	scene_editor

SRC	=	main.c \
		menu.c \
		list.c \
		new_file.c \
		verif.c \
		set_form.c \
		save.c \
		fill_object.c \
		init_form.c \
		shapes/sphere.c \
		shapes/cone.c \
		shapes/plan.c \
		shapes/cylindre.c \
		shapes/save_sphere.c \
		shapes/save_cyl.c \
		shapes/save_cone.c \
		shapes/save_plan.c \
		writer.c \
		write_color.c \
		write_light.c \
		view.c \
		shapes/color.c \
		shapes/save_color.c \
		light.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

RM	=	rm -f

INC	=	-I ./include

CFLAGS	+=	-W -Wall -g $(INC) `pkg-config --cflags gtk+-3.0`

LDFLAGS	+=	`pkg-config --libs gtk+-3.0`

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LDFLAGS)
clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
