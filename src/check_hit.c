/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** check hit
*/

#include "../include/struct.h"
#include "../include/lib.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

int check_hit(map_t *map)
{
    if (map->map[map->pos[1] - '0' + 1][(map->pos[0] - 'A') * 2 + 2] == 'x'
    || map->map[map->pos[1] - '0' + 1][(map->pos[0] - 'A') * 2 + 2] == 'o') {
        my_putstr("missed\n");
        return (0);
    }
    if (map->map[map->pos[1] - '0' + 1][(map->pos[0] - 'A') * 2 + 2] != '.') {
        my_putstr("hit\n");
        map->map[map->pos[1] - '0' + 1][(map->pos[0] - 'A') * 2 + 2] = 'x';
        return (1);
    }
    else {
        my_putstr("missed\n");
        map->map[map->pos[1] - '0' + 1][(map->pos[0] - 'A') * 2 + 2] = 'o';
    }
    return (0);
}

void check_end(map_t *map)
{
    int count_me = 0;
    int count_ennemy = 0;

    for (int i = 0; map->map[i] != NULL; i++) {
        for (int a = 0; map->map[i][a] != '\0'; a++)
            (map->map[i][a] == 'x') ? count_me++ : count_me;
    }
    for (int i = 0; map->map_two[i] != NULL; i++) {
        for (int a = 0; map->map_two[i][a] != '\0'; a++)
            (map->map_two[i][a] == 'x') ? count_ennemy++ : count_ennemy;
    }
    if (count_me == 14) {
        map->end = 1;
        map->winner = 1;
    }
    if (count_ennemy == 14) {
        map->end = 1;
        map->winner = 2;
    }
}
