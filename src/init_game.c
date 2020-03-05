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

int *get_global(void)
{
    return (&global);
}

void its_co(int signum, siginfo_t *sig, void *oldact)
{
    my_putstr("successfully connected\n");
}

void stop(int sig)
{
    global = global;
}

void send_sig(int signum, siginfo_t *sig, void *oldact)
{
    my_putstr("enemy connected\n");
    global = sig->si_pid;
    kill(sig->si_pid, SIGUSR1);
}

void init_game(int ac, char **av, map_t *map)
{
    pid_t my_pid = getpid();
    struct sigaction sig = {0};

    sig.sa_flags = SA_SIGINFO;
    my_putstr("my_pid:\t");
    my_put_nbr(my_pid);
    my_putchar('\n');
    if (ac == 2) {
        sig.sa_sigaction = send_sig;
        my_putstr("waiting for enemy connection...\n\n");
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
}
