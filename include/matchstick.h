/*
** EPITECH PROJECT, 2021
** B-CPE-200-STG-2-1-bsmatchstick-sylvian.burn
** File description:
** matchstick
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stddef.h>
#include <stdint.h>

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_
typedef enum enumplayer {
    player,
    AI
} playerenum;

typedef struct s_data {
    int nb_lines;
    int nb_matches;
    char *lines;
    char *matches;
    char **map;
    int game_matches;
    int game_line;
    int game_status;
    playerenum last_player;
} data_t;

void init_game_board(data_t *);
void print_game_board(data_t *);
int print_updated_board_game(int, int, data_t *);
void print_usage(void);
int error_handling(int ac, char **av);
int game_loop(data_t *);
int check_nb_line(data_t *, char *);
int check_nb_matches_on_line(data_t *, int);
int check_if_one_shot(data_t *, int);
int is_one_line(data_t *);
int get_nb_matches_on_line(data_t *, int);
int detect_end(data_t *);
int check_if_line_contains_matches(data_t *, int);

#endif /* !MATCHSTICK_H_ */