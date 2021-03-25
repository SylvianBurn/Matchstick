/*
** EPITECH PROJECT, 2020
** B-CPE-200-STG-2-1-matchstick-sylvian.burn
** File description:
** game.c
*/

#include "../include/my.h"
#include "../include/matchstick.h"

int get_random_shot(data_t *data)
{
    int random_line = random() % data->nb_lines;
    int random_matches = 0;

    random_matches = random() % data->nb_matches;
    return (0);
}



int game_ia(data_t *data)
{
    int nb = is_one_line(data);

    srandom(time);
    if (check_if_one_shot(data, nb) == 0)
        return (1);
    else
        get_random_shot(data);
    return (0);
}

int your_turn(data_t *data, size_t buffersize)
{
    my_printf("Lines: ");
    if (getline(&data->lines, &buffersize,stdin) == -1)
        return (0);
    if (check_nb_line(data, data->lines) == -1)
        your_turn(data, buffersize);
    my_printf("Matches: ");
    if (getline(&data->matches, &buffersize,stdin) == -1)
        return (0);
    if (check_nb_matches_on_line(data, data->game_line) == -1)
        your_turn(data, buffersize);
    print_updated_board_game(data->game_line, data->game_matches, data);
}

int game_loop(data_t *data)
{
    size_t buffersize = 4096;
    data->lines = malloc(sizeof(char) * buffersize);
    data->matches = malloc(sizeof(char) * buffersize);

    while (1) {
        my_printf("Your turn:\n");
        if (your_turn(data, buffersize) == 0)
            return (1);
        my_printf("AI's turn..\n");
        game_ia(data);
        print_game_board(data);
    }
    return (0);
}