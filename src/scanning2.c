/*
** EPITECH PROJECT, 2020
** B-CPE-200-STG-2-1-matchstick-sylvian.burn
** File description:
** scanning2.c
*/

#include "../include/my.h"
#include "../include/matchstick.h"

void value_set(data_t *data, int line)
{
    data->game_line = line;
    data->game_status = 1;
    data->error_status = 0;
}

int check_nb_line(data_t *data, char *buffer_line)
{
    int line = 0;

    for (int i = 0; buffer_line[i] != '\0'; i++) {
        if ((buffer_line[i] < 48 || buffer_line[i] > '9') &&
        buffer_line[i] != '\n') {
            write(1, "Error: invalid input (positive number expected)\n", 49);
            return (-1);
        }
    }
    line = my_getnbr(buffer_line);
    if (line == 0 || line > data->nb_lines) {
        write(1, "Error: this line is out of range\n", 34);
        return (-1);
    }
    if (line < 1) {
        write(1, "Error: invalid input (positive number expected)\n", 49);
        return (-1);
    }
    value_set(data, line);
    return (0);
}