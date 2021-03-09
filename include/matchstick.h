/*
** EPITECH PROJECT, 2021
** B-CPE-200-STG-2-1-bsmatchstick-sylvian.burn
** File description:
** matchstick
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_

typedef struct s_data {
    int nb_lines;
    int nb_matches;
    char **map;
} data_t;

void init_game_board(data_t *);
void print_game_board(data_t *);
int print_updated_board_game(int, int, data_t *);
void print_usage(void);
int error_handling(int ac, char **av);

#endif /* !MATCHSTICK_H_ */