/*
** EPITECH PROJECT, 2020
** B-CPE-200-STG-2-1-matchstick-sylvian.burn
** File description:
** asks.c
*/

#include "../include/matchstick.h"
#include "../include/my.h"

int ask_line(data_t *data, size_t buffersize)
{
    my_printf("Line: ");
    if (getline(&data->lines, &buffersize,stdin) == -1) {
        data->quit_status = 1;
        return (-1);
    }
    data->lines = rm_backline(data->lines);
    return (0);
}

int ask_matches(data_t *data, size_t buffersize)
{
    my_printf("Matches: ");
    if (getline(&data->matches, &buffersize,stdin) == -1) {
        data->quit_status = 1;
        return (-1);
    }
    return (0);
}