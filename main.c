/*
** EPITECH PROJECT, 2020
** B-CPE-200-STG-2-1-bsmatchstick-sylvian.burn
** File description:
** main.c
*/

#include "include/matchstick.h"
#include "include/my.h"

void my_freeing(data_t *data)
{
    for (int i = 0; data->map[i]; i++)
        free(data->map[i]);
    free(data->map);
    free(data);
}

int bridge(int ac, char **av, data_t *data)
{
    if (error_handling(ac, av) == 84) {
        free(data);
        return (84);
    }
    if (av[1][0] == '-' && av[1][1] == 'h' && av[2] == NULL) {
        print_usage();
        return (0);
    }
    return (1);
}

int main(int ac, char **av)
{
    data_t *data = malloc(sizeof(data_t));
    int status_bridge = bridge(ac, av, data);

    if (status_bridge == 1) {
        data->nb_lines = my_getnbr(av[1]);
        data->nb_matches = my_getnbr(av[2]);
        if (data->nb_lines == 0 || data->nb_matches == 0) {
            free(data);
            return (84);
        }
        init_game_board(data);
        //print_updated_board_game(3, 5,data);
        my_freeing(data);
    } else
        return (status_bridge);
    return (0);
}