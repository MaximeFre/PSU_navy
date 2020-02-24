/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** init_game
*/

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include "../include/lib.h"
#include "../include/struct.h"

int global = 0;

void which_sig(int signum, siginfo_t *sig, void *oldact)
{
    if (signum == 10)
        global = 1;
    if (signum == 12)
        global = -1;
}

void stop(int sig)
{
    global = global;
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
        map->map_two[pos[1] - '0' + 1][(pos[0] - 'A') * 2 + 2] = 'o';
    }
}


void receive_pos(map_t *map)
{
    int stop = 0;
    int letter = 0;
    int nb = 0;
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
    stop = 0;
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

void send_sig(int signum, siginfo_t *sig, void *oldact)
{
    my_putstr("ennemy connected\n");
    global = sig->si_pid;
    kill(sig->si_pid, SIGUSR1);
}

void its_co(int signum, siginfo_t *sig, void *oldact)
{
    my_putstr("successfully connected\n");
}

int init_game(int ac, char **av, map_t *map)
{
    pid_t my_pid = getpid();
    struct sigaction sig = {0};

    sig.sa_flags = SA_SIGINFO;
    my_putstr("my_pid:\t");
    my_put_nbr(my_pid);
    my_putchar('\n');
    if (ac == 2) {
        sig.sa_sigaction = send_sig;
        my_putstr("waiting for ennemy connection...\n\n");
        sigaction(SIGUSR1, &sig, NULL);
        pause();
        map->pid = global;
    } if (ac == 3) {
        sig.sa_sigaction = its_co;
        kill(my_getnbr(av[1]), SIGUSR1);
        sigaction(SIGUSR1, &sig, NULL);
        pause();
        map->pid = my_getnbr(av[1]);
    }
    return (0);
}
