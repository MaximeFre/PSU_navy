/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** c
*/

#include "../include/lib.h"

void my_putstr(char const *str)
{
    int n = 0;

    while (str[n] != '\0') {
        n++;
    }
    for (int i = 0; i < n; i++) {
        my_putchar(str[i]);
    }
}
