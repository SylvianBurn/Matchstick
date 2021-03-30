##
## EPITECH PROJECT, 2020
## B-PSU-100-STG-1-1-bsmyls-sylvian.burn
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/error.c	\
		src/print_game_board.c	\
		src/game.c	\
		src/scanning.c	\
		src/scanning2.c	\
		src/ai_scans.c	\
		src/asks.c

OBJ	=	$(SRC:.c=.o)

NAME	=	matchstick

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C ./lib/my
	gcc -g	$(OBJ)	-o	$(NAME) -L./lib/my -lmy

clean:
	make clean -C ./lib/my
	rm -f $(OBJ)

fclean: clean
	make fclean -C ./lib/my
	rm -f $(NAME)

re: fclean all