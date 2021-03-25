/*
** EPITECH PROJECT, 2020
** B-CPE-200-STG-2-1-bsmatchstick-sylvian.burn
** File description:
** main.c
*/

#include "../include/matchstick.h"
#include "../include/my.h"

void my_freeing(data_t *data)
{
    for (int i = 0; data->map[i]; i++)
        free(data->map[i]);
    free(data->map);
    free(data->matches);
    free(data->lines);
    free(data);
}

int bridge(int ac, char **av, data_t *data)
{
    int status = error_handling(ac, av);

    if (status == 84) {
        free(data);
        return (84);
    }
    if (status == 1) {
        free(data);
        return (1);
    }
    return (0);
}

int main(int ac, char **av)
{
    data_t *data = malloc(sizeof(data_t));
    int status_bridge = bridge(ac, av, data);
    int game_status = 0;

    if (status_bridge == 0) {
        data->nb_lines = my_getnbr(av[1]);
        data->nb_matches = my_getnbr(av[2]);
        if (data->nb_lines == 0 || data->nb_matches == 0) {
            write(2, "Error: Invalide input (positive number expected)\n", 50);
            free(data);
            return (84);
        }
        init_game_board(data);
        game_status = game_loop(data);
        my_freeing(data);
        return (game_status);
    } else if (status_bridge == 1) {
        return (0);
    } else
        return (status_bridge);
    return (0);
}