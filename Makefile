##
## Makefile for wolf in /home/lemper_a/rendu/MUL_2014_wolf3d
##
## Made by Antoine LEMPEREUR
## Login   <lemper_a@epitech.net>
##
## Started on  Tue Nov 25 11:37:16 2014 Antoine LEMPEREUR
## Last update Sun Jun  7 21:24:02 2015 Raphael Thiebault
##

NAME	=	rt

ifeq ($(DEBUG), yes)
CFLAGS	+=	-g -Wextra -pedantic -Wall -O3
endif

LIB	=	-lmlx -lgsl -lgslcblas -L./lib -L/usr/local/lib -lXext -lX11

SRCS    =	src/main.c \
		src/go.c \
		src/calc/ray.c \
		src/calc/modif.c \
		src/calc/calc.c \
		src/calc/get_k.c \
		src/calc/get_k_complex.c \
		src/calc/get_blur_color.c \
		src/calc/vec_func.c \
		src/calc/get_dif.c \
		src/shapes/sphere.c \
		src/shapes/cyl.c \
		src/shapes/cone.c \
		src/shapes/plan.c \
		src/shapes/paraboloid.c \
		src/shapes/hyperboloid.c \
		src/shapes/ellipsoid.c \
		src/shapes/tore.c \
		src/shapes/cube.c \
		src/shapes/dingdong.c \
		src/shapes/mobius.c \
		src/shapes/star.c \
		src/obj/triangle.c \
		src/obj/algo_tri.c \
		src/obj/inter_box.c \
		src/obj/create_tri_list.c \
		src/effect/sphere_text.c \
		src/effect/trans.c \
		src/effect/damier.c \
		src/effect/mirror.c \
		src/effect/blur.c \
		src/color/pixel.c \
		src/color/color.c \
		src/color/init_color.c \
		src/light/light.c \
		src/light/phong.c \
		src/light/shadow.c \
		src/light/light_vec.c \
		src/bmp/bmp_exporter.c \
		src/bmp/bmp_importer.c \
		src/bmp/bmp_fileheader.c \
		src/bmp/bmp_imgheader.c \
		src/bmp/bmp_content.c \
		src/bmp/bmp_utils.c \
		src/video/video.c \
		src/video/calc_video_pos.c \
		src/threads/my_threads.c \
		src/threads/calc_task.c \
		src/threads/my_task_list.c \
		src/net/my_client.c \
		src/net/my_packet.c \
		src/net/my_receiver.c \
		src/net/my_sender.c \
		src/net/my_reader.c \
		src/net/my_scene.c \
		src/net/my_texture.c \
		src/net/my_calculator.c \
		src/net/my_fd_readable.c \
		src/net/packets/helloconnect.c \
		src/net/packets/asktask.c \
		src/net/packets/sendscene.c \
		src/net/packets/recvidscene.c \
		src/net/packets/newtask.c \
		src/net/packets/askscene.c \
		src/net/packets/recvscene.c \
		src/net/packets/sendresult.c \
		src/net/packets/recvresult.c \
		src/tools/my_lib.c \
		src/tools/linked_list.c \
		src/tools/init.c \
		src/tools/fc_base.c \
		src/tools/fc_str.c \
		src/tools/cut_str.c \
		src/tools/my_getnbr.c \
		src/tools/my_getnbr_hexa.c \
		src/tools/my_put_nbr.c \
		src/tools/my_lists.c \
		src/tools/my_realloc.c \
		src/tools/my_strncmp.c \
		src/tools/my_free.c \
		src/parsing/go_parsing.c \
		src/parsing/init_bool.c \
		src/parsing/parsing_rt.c \
		src/parsing/parsing_video.c \
		src/parsing/check/check_def.c \
		src/parsing/check/check_basic.c \
		src/parsing/check/check_form.c \
		src/parsing/check/check_pos.c \
		src/parsing/check/check_rot_lim.c \
		src/parsing/check/check_simple_num.c \
		src/parsing/check/check_color.c \
		src/parsing/check/check_percent.c \
		src/parsing/check/check_focus.c \
		src/parsing/check/check_id.c \
		src/parsing/check/check_size.c \
		src/parsing/check/check_distorsion.c \
		src/parsing/check/check_circonference.c \
		src/parsing/check/check_remplissage.c \
		src/parsing/check/check_points.c \
		src/parsing/check/check_normale.c \
		src/parsing/check/check_texture.c \
		src/parsing/check/check_tab.c \
		src/parsing/check/check_xpm.c \
		src/parsing/check/check_video.c \
		src/parsing/check/check_balise_vid.c \
		src/parsing/check/check_percent_time.c \
		src/parsing/check/check_translation.c \
		src/parsing/check/check_rotate_video.c \
		src/parsing/check/check_sum_time.c \
		src/parsing/check/check_rotate_centrale.c \
		src/parsing/check/check_bool.c \
		src/parsing/fill/fill_obj_list.c \
		src/parsing/fill/fill_form.c \
		src/parsing/fill/fill_pos.c \
		src/parsing/fill/fill_rayangle.c \
		src/parsing/fill/fill_percent.c \
		src/parsing/fill/fill_color.c \
		src/parsing/fill/fill_default.c \
		src/parsing/fill/fill_ign_obj.c \
		src/parsing/fill/fill_define.c \
		src/parsing/fill/fill_xpm.c \
		src/parsing/fill/fill_xpm_in_obj.c \
		src/parsing/fill/fill_time.c \
		src/parsing/fill/fill_pos_video.c \
		src/parsing/fill/fill_specularite.c \
		src/parsing/fill/fill_complex_obj.c \
		src/parsing/fill/fill_view_light.c \
		src/parsing/fill/fill_obj_name.c \
		src/parsing/fill/fill_texture_mtl.c \
		src/parsing/fill/fill_xpm_name.c \
		src/parsing/fill/fill_points_tab.c \
		src/parsing/fill/fill_normale_tab.c \
		src/parsing/fill/fill_texture_tab.c \
		src/parsing/fill/fill_obj_tab.c \
		src/parsing/fill/fill_rolim.c \
		src/parsing/fill/fill_distorsion.c \
		src/parsing/fill/fill_video_list.c \
		src/parsing/fill/fill_rot_centrale.c \
		src/parsing/fill/fill_sheet.c \
		src/parsing/error/error_parsing.c \
		src/parsing/error/error_obj.c \
		src/parsing/error/error_video.c \
		src/parsing/error/error_setting.c \
		src/parsing/notice.c \
		src/parsing/comments.c \
		src/parsing/define.c \
		src/parsing/pass_x.c \
		src/parsing/is_x.c \
		src/parsing/is_double.c \
		src/parsing/parsing_obj.c \
		src/parsing/correct_tab.c \
		src/parsing/video_list.c \
		src/parsing/find_video_list.c \
		src/parsing/face_in_tab.c \
		src/parsing/parse_ip.c

OBJS	=	$(SRCS:.c=.o)

RM	=	rm -f

INC	= 	-I./include \
		-I ./include/parsing \
		-I/usr/local/include/gsl \
		-I/usr/include/gsl

CFLAGS		+= $(INC) -W -Wall

LDFLAGS		= -lm -lpthread -D_REENTRANT

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LIB) $(CFLAGS) $(LDFLAGS)

clean :
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all
