/*
** EPITECH PROJECT, 2020
** B-CPE-200-STG-2-1-matchstick-sylvian.burn
** File description:
** scanning.c
*/

#include "../include/my.h"
#include "../include/matchstick.h"

int check_nb_line(data_t *data, char *buffer_line)
{
    int line = 0;

    for (int i = 0; buffer_line[i] != '\n' && buffer_line[i] != '\0'; i++) {
        if (buffer_line[i] < 48 || buffer_line[i] > '9') {
            write(2, "Error: invalid input (positive number expected)\n", 49);
            return (-1);
        }
    }
    line = my_getnbr(buffer_line);
    if (line == 0 || line > data->nb_lines) {
        write(2, "Error: this line is out of range\n", 34);
        return (-1);
    }
    if (line < 1) {
        write(2, "Error: invalid input (positive number expected)\n", 49);
        return (-1);
    }
    data->game_line = line;
    return (0);
}

int get_nb_matches_on_line(data_t *data, int line)
{
    int nb = 0;

    for (int i = 0; data->map[line][i] != '\0'; i++) {
        if (data->map[line][i] == '|')
            nb++;
    }
    return (nb);
}

int check_nb_matches_on_line(data_t *data, int line)
{
    int matches = 0;

    for (int i = 0; data->matches[i] != '\n'; i++) {
        if (data->matches[i] < '0' || data->matches[i] > '9') {
            write(2, "Error: invalid input (positive number expected)\n", 49);
            return (-1);
        }
    }
    matches = my_getnbr(data->matches);
    if (matches == 0) {
        write(2, "Error: you have to remove at least one match\n", 46);
        return (-1);
    }
    if (matches > get_nb_matches_on_line(data, line)) {
        write(2, "Error: not enough matches on this line\n", 40);
        return (-1);
    }
    data->game_matches = matches;
    return (0);
}

int is_one_line(data_t *data)
{
    int lines_with_matches = 0;

    for (int i = 1; i <= data->nb_lines; i++) {
        for (int y = 0; data->map[i][y] != '|' && data->map[i][y]; y++) {
            if (data->map[i][y] == '|')
                lines_with_matches++;
        }
    }
    if (lines_with_matches > 1)
        return (2);
    else if (lines_with_matches == 1)
        return (1);
    else
        return (0);
}

int check_if_one_shot(data_t *data, int is_one_line)
{
    if (is_one_line == 1) {
        
    }

}