##
## EPITECH PROJECT, 2020
## B-PSU-100-STG-1-1-bsmyls-sylvian.burn
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/error.c	\
		src/print_game_board.c	\
		src/print_updated_board_game.c	\
		src/game.c	\
		src/scanning.c

OBJ	=	$(SRC:.c=.o)

NAME	=	matchstick

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C ./lib/my
	gcc	$(OBJ)	-o	$(NAME) -L./lib/my -lmy -g

clean:
	make clean -C ./lib/my
	rm -f $(OBJ)

fclean: clean
	make fclean -C ./lib/my
	rm -f $(NAME)

re: fclean all