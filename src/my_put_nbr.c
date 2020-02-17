/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** display the number in parameter
*/

#include "../include/lib.h"

void my_min(void)
{
    my_putchar('-');
    my_putchar('2');
    my_putchar('1');
    my_putchar('4');
    my_putchar('7');
    my_putchar('4');
    my_putchar('8');
    my_putchar('3');
    my_putchar('6');
    my_putchar('4');
    my_putchar('8');
}

int my_put_nbr(int nb)
{
    int cp;

    if (nb == -2147483648) {
        my_min();
        return (0);
    }
    if (nb < 0) {
        nb = nb * -1;
        my_putchar('-');
    }
    if (nb >= 10) {
        cp = nb % 10;
        nb = nb - cp;
        nb = nb / 10;
        my_put_nbr(nb);
        my_putchar(cp + '0');
    }
    else
        my_putchar(nb + '0');
    return (0);
}
