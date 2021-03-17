/*
** EPITECH PROJECT, 2021
** B-CPE-200-STG-2-1-bsmatchstick-sylvian.burn
** File description:
** matchstick
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <stdint.h>

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_

typedef struct s_data {
    int nb_lines;
    int nb_matches;
    char *lines;
    char *matches;
    char **map;
    int game_matches;
    int game_line;
} data_t;

void init_game_board(data_t *);
void print_game_board(data_t *);
int print_updated_board_game(int, int, data_t *);
void print_usage(void);
int error_handling(int ac, char **av);
int game_loop(data_t *);
int check_nb_line(data_t *, char *);
int check_nb_matches_on_line(data_t *, int);

#endif /* !MATCHSTICK_H_ */