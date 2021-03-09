##
## EPITECH PROJECT, 2020
## B-PSU-100-STG-1-1-bsmyls-sylvian.burn
## File description:
## Makefile
##

SRC	=	main.c	\
		error.c	\
		print_game_board.c	\
		print_updated_board_game.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	matchstick

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C ./lib/my
	gcc	$(OBJ)	-o	$(NAME) -g -L./lib/my -lmy

clean:
	make clean -C ./lib/my
	rm -f $(OBJ)

fclean: clean
	make fclean -C ./lib/my
	rm -f $(NAME)

re: fclean all