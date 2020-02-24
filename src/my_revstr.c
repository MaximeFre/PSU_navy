/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** c
*/

#include "../include/lib.h"

void my_swap(char *a, char *b)
{
    char c = 0;

    c = *a;
    *a = *b;
    *b = c;
}

char *my_revstr(char *str)
{
    int len = my_strlen(str);

    for (int i = 0; i < len / 2; ++i) {
        my_swap(str + i, str + len - 1 - i);
    }
    return (str);
}
