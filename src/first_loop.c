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
    char *input = malloc(sizeof(char) * 4);
    size_t count = 4;
    int valid = 0;

    while (map->end == 0) {
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
        my_putstr("\nattack: ");
        read(0, input, count);
        valid = check_valide(input);
        while (input[0] == '\0' || input[1] == '\0' || valid == 84) {
            my_putstr("wrong position\nattack: ");
            read(0, input, count);
            valid = check_valide(input);
        }
        my_putstr(input);
        my_putchar(':');
        send_bin(input, map);
        receive_touch(map, input);
        if (map->win == 1)
            my_putstr("hit\n");
        else
            my_putstr("missed");
        check_end(map);
        if (map->end == 1)
            break;
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
    if (map->winner == 2)
        my_putstr("\nI won\n");
    else
        my_putstr("\nEnemy won\n");
}
