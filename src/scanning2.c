/*
** EPITECH PROJECT, 2020
** B-CPE-200-STG-2-1-matchstick-sylvian.burn
** File description:
** scanning2.c
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
    data->game_status = 1;
    return (0);
}
