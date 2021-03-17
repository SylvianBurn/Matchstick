/*
** EPITECH PROJECT, 2020
** B-CPE-200-STG-2-1-matchstick-sylvian.burn
** File description:
** error.c
*/

#include "include/matchstick.h"
#include "include/my.h"

void print_usage(void)
{
    my_printf("USAGE\n\t./matchstick nb_lines matches\n");
    my_printf("DESCRIPTION\n\tnb_lines representing the number of lines.\n");
    my_printf("\tmatches representing the maximum number of matches you can");
    my_printf(" remove on a line.\n");
}

int check_args(int ac, char **av)
{
    for (int i = 1; av[i] != NULL; i++) {
        for (int x = 0; av[i][x] != '\0'; x++) {
            if (av[i][x] < 48 || av[i][x] > 59) {
                write(2, "Error: Invalid input (positive number expected)\n",
                49);
                return (84);
            }
        }
    }
    return (0);
}

int error_handling(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        print_usage();
        return (1);
    }
    if (ac != 3) {
        write(2, "Error: Wrong numbers of arguments\n", 35);
        return (84);
    }
    if (ac == 3) {
        if (check_args(ac, av) != 0)
            return (84);
        else
            return (0);
    }
    return (0);
}