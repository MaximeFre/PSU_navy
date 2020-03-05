/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** sig handler
*/

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include "../include/lib.h"
#include "../include/struct.h"

void which_sig(int signum, siginfo_t *sig, void *oldact)
{
    if (signum == 10)
        global = 1;
    if (signum == 12)
        global = -1;
}

void receive_touch(map_t *map, char *pos)
{
    struct sigaction sig = {0};

    sig.sa_sigaction = which_sig;
    sig.sa_flags = SA_SIGINFO;
    global = 0;
    while (global == 0) {
        sigaction(SIGUSR1, &sig, NULL);
        sigaction(SIGUSR2, &sig, NULL);
        pause();
    }
    if (global == 1) {
        map->win = 1;
        map->map_two[pos[1] - '0' + 1][(pos[0] - 'A') * 2 + 2] = 'x';
    }
    if (global == -1) {
        map->win = 0;
        if (map->map_two[pos[1] - '0' + 1][(pos[0] - 'A') * 2 + 2] != 'x')
            map->map_two[pos[1] - '0' + 1][(pos[0] - 'A') * 2 + 2] = 'o';
    }
}

void receive_nb(map_t *map, int letter)
{
    int stop = 0;
    int nb = 0;
    struct sigaction sig = {0};

    sig.sa_sigaction = which_sig;
    sig.sa_flags = SA_SIGINFO;
    while (stop == 0) {
        sigaction(SIGUSR1, &sig, NULL);
        sigaction(SIGUSR2, &sig, NULL);
        pause();
        if (global == 1)
            nb += 1;
        if (global == -1)
            stop = 1;
    }
    map->pos[0] = 'A' + letter;
    map->pos[1] = '0' + nb;
}

void receive_pos(map_t *map)
{
    int stop = 0;
    int letter = 0;
    struct sigaction sig = {0};

    map->pos = malloc(sizeof(char) * 3);
    map->pos[2] = '\0';
    sig.sa_sigaction = which_sig;
    sig.sa_flags = SA_SIGINFO;
    global = 0;
    while (stop == 0) {
        sigaction(SIGUSR1, &sig, NULL);
        sigaction(SIGUSR2, &sig, NULL);
        pause();
        if (global == 1)
            letter += 1;
        if (global == -1)
            stop = 1;
    }
    receive_nb(map, letter);
}
