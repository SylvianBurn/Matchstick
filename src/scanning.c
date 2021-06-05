/*
** EPITECH PROJECT, 2020
** B-CPE-200-STG-2-1-matchstick-sylvian.burn
** File description:
** scanning.c
*/

#include "../include/my.h"
#include "../include/matchstick.h"

int get_nb_matches_on_line(data_t *data, int line)
{
    int nb = 0;

    for (int i = 0; data->map[line][i] != '\0'; i++) {
        if (data->map[line][i] == '|')
            nb++;
    }
    return (nb);
}

int check_nb_matches_on_line_conditions(data_t *data, int line)
{
    if (data->game_matches == 0) {
        my_printf("Error: you have to remove at least one match\n");
        return (-1);
    }
    if (data->game_matches > data->nb_matches) {
        my_printf("Error: you can not remove more than %d matches per turn\n",
        data->nb_matches);
        return (-1);
    }
    if (data->game_matches > get_nb_matches_on_line(data, line)) {
        my_printf("Error: not enough matches on this line\n");
        return (-1);
    }
    return (0);
}

int check_nb_matches_on_line(data_t *data, int line)
{
    for (int i = 0; data->matches[i] != '\0'; i++) {
        if ((data->matches[i] < '0' || data->matches[i] > '9')
        && data->matches[i] != '\n') {
            my_printf("Error: invalid input (positive number expected)\n");
            return (-1);
        }
    }
    data->game_matches = my_getnbr(data->matches);
    if (check_nb_matches_on_line_conditions(data, line) == -1)
        return (-1);
    data->game_status = 2;
    data->error_status = 0;
    return (0);
}

int is_one_line(data_t *data)
{
    int lines_with_matches = 0;

    for (int i = 0; data->map[i] != NULL; i++) {
        for (int y = 0;data->map[i][y] != '\0'; y++) {
            if (data->map[i][y] == '|') {
                lines_with_matches++;
                i++;
            }
        }
    }
    if (lines_with_matches > 1)
        return (lines_with_matches);
    else if (lines_with_matches == 1)
        return (1);
    else
        return (0);
}

int check_if_one_shot(data_t *data, int is_one_line)
{
    int line_to_check = 0;
    int matches = 0;

    for (int i = 1; data->map[i]; i++) {
        for (int y = 0; data->map[i][y]; y++) {
            if (data->map[i][y] == '|')
                line_to_check = i;
        }
    }
    matches = get_nb_matches_on_line(data, line_to_check);
    if (matches <= data->nb_matches && (matches - 1) > 0) {
        my_printf("AI removed %d match(es) from line %d\n", (matches - 1),
            line_to_check);
        print_updated_board_game(line_to_check, (matches -  1), data);
        return (1);
    } else {
        my_printf("AI removed 1 match(es) from line %d\n", line_to_check);
        print_updated_board_game(line_to_check, 1, data);
    }
    return (0);
}