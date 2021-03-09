/*
** EPITECH PROJECT, 2020
** B-CPE-200-STG-2-1-bsmatchstick-sylvian.burn
** File description:
** print_updated_board_game.c
*/

#include "include/my.h"
#include "include/matchstick.h"

int check_nb_sticks(data_t *data, int line)
{
    int nb_matches = 0;

    for (int i = 0; data->map[line][i] != '\0'; i++) {
        if (data->map[line][i] == '|') {
            nb_matches++;
        }
    }
    return (0);
}

int print_updated_board_game(int line, int nb_matches, data_t *data)
{
    int nb_matches_removed = 0;

    if (check_nb_sticks(data, line) < nb_matches) {
        write(2, "Error: not enough matches on this line\n", 40);
        return (84);
    }
    for (int i = 0; data->map[line][i]; i++) {
        if (data->map[line][i] == '|' && nb_matches_removed < nb_matches) {
            data->map[line][i] = ' ';
            nb_matches_removed++;
        }
    }
    print_game_board(data);
    return (0);
}