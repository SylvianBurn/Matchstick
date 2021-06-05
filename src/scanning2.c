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
            my_printf("Error: invalid input (positive number expected)\n");
            return (-1);
        }
    }
    line = my_getnbr(buffer_line);
    if (line == 0 || line > data->nb_lines) {
        my_printf("Error: this line is out of range\n");
        return (-1);
    }
    if (line < 1) {
        my_printf("Error: invalid input (positive number expected)\n");
        return (-1);
    }
    value_set(data, line);
    return (0);
}
