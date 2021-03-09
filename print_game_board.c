/*
** EPITECH PROJECT, 2021
** B-CPE-200-STG-2-1-bsmatchstick-sylvian.burn
** File description:
** main.c
*/

#include "include/my.h"
#include "include/matchstick.h"

void fill_in_outlines(data_t *data)
{
    int x = 1;
    int length = data->nb_lines * 2 + 1;

    for (int i = 0; i < length; i++)
        data->map[0][i] = '*';
    data->map[0][length] = '\0';
    for (int i = 0; i < length; i++)
        data->map[data->nb_lines + 1][i] = '*';
    data->map[data->nb_lines + 1][length] = '\0';
    for (; x <= data->nb_lines; x++) {
        data->map[x][0] = '*';
        for (int y = 1; y < length; y++)
            data->map[x][y] = ' ';
        data->map[x][length - 1] = '*';
        data->map[x][length] = '\0';
    }
    data->map[x + 1] = NULL;
}

void fill_in_map(data_t *data)
{
    int offset = 0;
    int max_matches = 1;
    int count = 0;

    for (int x = 1; x <= data->nb_lines; x++) {
        for (int y = data->nb_lines; count < max_matches; count++) {
            data->map[x][y - offset] = '|';
            y++;
        }
        count = 0;
        max_matches += 2;
        offset++;
    }
}

void init_game_board(data_t *data)
{
    data->map = malloc(sizeof(char *) * (data->nb_lines + 3));
    for (int i = 0; i < (data->nb_lines + 3); i++)
        data->map[i] = malloc(sizeof(char) * (data->nb_lines * 2 + 2));
    fill_in_outlines(data);
    fill_in_map(data);
    print_game_board(data);
}

void print_game_board(data_t *data)
{
    for (int i = 0; data->map[i]; i++)
        printf("%s\n", data->map[i]);
}