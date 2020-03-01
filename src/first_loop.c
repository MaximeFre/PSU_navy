/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** first loop
*/

#include "../include/struct.h"
#include "../include/lib.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

int check_valide(char *input)
{
    if (input[0] > 'H' || input[0] < 'A')
        return (84);
    if (input[1] > '8' || input[1] < '1')
        return (84);
    if (input[2] == '\n')
        input[2] = '\0';
    return (0);
}

void send_bin(char *input, map_t *map)
{
    int letter = input[0] - 'A';
    int nb = input[1] - '0';

    for (int i = 0; i < letter; i++) {
        usleep(10000);
        kill(map->pid, SIGUSR1);
    }
    usleep(10000);
    kill(map->pid, SIGUSR2);
    for (int i = 0; i < nb; i++) {
        usleep(10000);
        kill(map->pid, SIGUSR1);
    }
    usleep(10000);
    kill(map->pid, SIGUSR2);
}

void first_loop(map_t *map)
{
    while (map->end == 0) {
        disp_maps(map);
        attack(map);
        if (map->win == 1)
            my_putstr("hit\n");
        else
            my_putstr("missed");
        check_end(map);
        if (map->end == 1)
            break;
        waiting(map);
    }
    disp_maps(map);
    if (map->winner == 2)
        my_putstr("\nI won\n");
    else
        my_putstr("\nEnemy won\n");
}
