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

    while (check_if_line_contains_matches(data, random_line) != 1)
        random_line = random() % data->nb_lines;
    random_matches = 1 + random() % get_nb_matches_on_line(data, random_line);
    my_printf("AI removed %d match(es) on line %d\n", random_matches,
        random_line);
    print_updated_board_game(random_line, random_matches, data);
    return (0);
}

int game_ia(data_t *data)
{
    int nb = is_one_line(data);

    srandom(time(NULL));
    if (nb == 1) {
        check_if_one_shot(data, nb);
    }
    else
        get_random_shot(data);
    data->last_player = AI;
    return (0);
}

int your_turn(data_t *data, size_t buffersize)
{
    data->game_status = 0;
    if (data->quit_status != 0 || data->game_status != 0) return (0);
        if (ask_line(data, buffersize) == -1) return (-1);
        if (check_nb_line(data, data->lines) == -1)
            your_turn(data, buffersize);
    if (data->game_status != 1 || data->error_status != 0) return (0);
        if (ask_matches(data, buffersize) == -1) return (-1);
        if (check_nb_matches_on_line(data, data->game_line) == -1)
            your_turn(data, buffersize);
    if (data->game_status != 2 || data->error_status != 0) return (0);
        my_printf("Player removed %d match(es) from line %d\n",
            data->game_matches, data->game_line);
        print_updated_board_game(data->game_line, data->game_matches, data);
        data->last_player = player;
        data->error_status = 1;
}

int game_loop(data_t *data)
{
    size_t buffersize = 4096;

    while (1) {
        if (data->quit_status == 1) return (0);
        my_printf("\nYour turn:\n");
        if (your_turn(data, buffersize) == -1) {
            data->quit_status = 1;
            return (0);
        }
        if (data->quit_status == 1) return (0);
        if (detect_end(data) == 2) return (-2);
        if (data->last_player == player) {
            my_printf("\nAI's turn...\n");
            game_ia(data);
            if (detect_end(data) == 1) return (-1);
        }
    }
    return (0);
}