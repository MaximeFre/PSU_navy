/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** main
*/

#include "../include/struct.h"
#include "../include/lib.h"
#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
    map_t *map = malloc(sizeof(map_t));

    global = 0;
    if (ac == 2) {
        if (init_map(av[1], map) == 84)
            return (84);
        map->map_two = initial_map();
        init_game(ac, av, map);
        first_loop(map);
    }
    if (ac == 3) {
        if (init_map(av[2], map) == 84)
            return (84);
        map->map_two = initial_map();
        init_game(ac, av, map);
        sec_loop(map);
    }
    return (0);
}
