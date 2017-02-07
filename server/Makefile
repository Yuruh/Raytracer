##
## Makefile for rtracer in /home/vasseu_g/rendu/MUL_2014_rtracer/pas_touche_vasseu_g_tests
## 
## Made by Adrien Vasseur
## Login   <vasseu_g@epitech.net>
## 
## Started on  Mon Mar 16 23:13:31 2015 Adrien Vasseur
## Last update Sun Jun  7 21:20:26 2015 Adrien Vasseur
##

SRC	=	src/main.c \
		src/network/my_server_utils.c \
		src/network/my_server.c \
		src/network/my_server_daemon.c \
		src/network/my_server_signal.c \
		src/network/my_add_client.c \
		src/network/my_receiver.c \
		src/network/my_fd_readable.c \
		src/network/my_packet.c \
		src/network/my_scene.c \
		src/network/calc_task.c \
		src/network/my_tasks.c \
		src/network/packets/helloconnect.c \
		src/network/packets/asktask.c \
		src/network/packets/recvscene.c \
		src/network/packets/recvidscene.c \
		src/network/packets/newtask.c \
		src/network/packets/askscene.c \
		src/network/packets/sendscene.c \
		src/network/packets/recvresult.c \
		src/network/packets/sendresult.c

OBJ	=	$(SRC:.c=.o)

NAME	=	server

CFLAGS	=	-I./include/ -I../include/ -lpthread -D_REENTRANT

ifeq ($(CC), clang)
CFLAGS	+=	-Weverything
else
CC	=	gcc
CFLAGS	+=	-Wall -Wextra -g
endif

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
