/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** init_game
*/

#include <unistd.h>
#include <sys/types.h>
#include "../include/lib.h"

int init_game(int ac, char **av)
{
    pid_t pid = getpid();

    my_putstr("my_pid:\t");
    my_put_nbr(pid);
    my_putchar('\n');
    if (ac == 2) {
        my_putstr("waiting for ennemy connection...\n\n");
    } else if (ac == 3) {

    }
    
}
