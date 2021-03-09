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

int error_handling(int ac, char **av)
{
    if (ac != 3 && (ac == 2 && av[1][0] != '-' && av[1][1] != 'h')) {
        write(2, "Error: Wrong numbers of arguments\n", 35);
        return (84);
    }
    return (0);
}