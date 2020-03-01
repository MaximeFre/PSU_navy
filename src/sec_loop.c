/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** second loop
*/

#include "../include/struct.h"
#include "../include/lib.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

void disp_maps(map_t *map)
{
    my_putstr("\nmy positions:\n");
    for (int i = 0; i < 10; i++) {
        my_putstr(map->map[i]);
        my_putchar('\n');
    }
    my_putstr("\nenemy's positions:\n");
    for (int i = 0; i < 10; i++) {
        my_putstr(map->map_two[i]);
        my_putchar('\n');
    }
}

void waiting(map_t *map)
{
    my_putstr("\nwaiting for enemy's attack...\n");
    receive_pos(map);
    my_putstr(map->pos);
    my_putchar(':');
    if (check_hit(map) == 1) {
        usleep(10000);
        kill(map->pid, SIGUSR1);
    } else {
        usleep(10000);
        kill(map->pid, SIGUSR2);
    }
    check_end(map);
}

void attack(map_t *map)
{
    char *input;
    size_t count;
    int valid = 0;

    my_putstr("\nattack: ");
    getline(&input, &count, stdin);
    valid = check_valide(input);
    while (input[0] == '\0' || input[1] == '\0' || valid == 84) {
        my_putstr("wrong position\nattack: ");
        getline(&input, &count, stdin);
        valid = check_valide(input);
    }
    my_putstr(input);
    my_putchar(':');
    send_bin(input, map);
    receive_touch(map, input);
}

void sec_loop(map_t *map)
{
    while (map->end == 0) {
        disp_maps(map);
        waiting(map);
        if (map->end == 1)
            break;
        attack(map);
        if (map->win == 1)
            my_putstr("hit\n");
        else
            my_putstr("missed");
        check_end(map);
    }
    disp_maps(map);
    if (map->winner == 2)
        my_putstr("\nI won\n");
    else
        my_putstr("\nEnemy won\n");
}
