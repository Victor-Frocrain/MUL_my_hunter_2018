##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c		\
		src/manage_mouse.c	\
		src/manage_ships.c	\
		src/convert_int_str.c	\
		src/loop.c		\
		src/init.c		\
		src/init_textures.c	\
		src/display_text.c	\
		src/init_sprites.c	\
		src/manage_pause.c	\
		src/init_audio.c	\
		src/manage_scenes.c	\
		src/change_buttons.c	\

OBJ	=	$(SRC:%.c=%.o)

CFLAGS	=	-Wshadow -I ./include

LIB	=	-L ./lib/my -lmy -lcsfml-graphics -lcsfml-window -lcsfml-system  -lcsfml-audio -lm

NAME	=	my_hunter

CC	=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
		make -C ./lib/my
		$(CC) -o $(NAME) $(OBJ) $(LIB)

clean:
	make -C ./lib/my clean
	rm -f $(OBJ)
	rm -f *.gcno *.gcda

fclean:	clean
	make -C ./lib/my fclean
	rm -f $(NAME)

re:	fclean all
	make -C ./lib/my re
