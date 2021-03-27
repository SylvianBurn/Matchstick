/*
** EPITECH PROJECT, 2020
** B-CPE-200-STG-2-1-matchstick-sylvian.burn
** File description:
** ai_scans.c
*/

#include "../include/my.h"
#include "../include/matchstick.h"

int check_if_line_contains_matches(data_t *data, int line)
{
    for (int y = 0; data->map[line][y] != '\0'; y++) {
        if (data->map[line][y] == '|')
            return (1);
    }
    return (0);
}