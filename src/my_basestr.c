/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** reconvert into base str
*/

#include "../include/lib.h"
#include <stdlib.h>

char value(int num)
{
    if (num >= 0 && num <= 9)
        return ((char)(num + '0'));
    else
        return ((char)(num - 10 + 'a'));
}

char *convertbase(long long int expr, long long int base)
{
    char *result;
    long long int nb = expr;
    int i = 0;

    for (; nb > 0; i++)
        nb /= 10;
    result = malloc_str(i * 20);
    while (expr > 0) {
        result[nb] = value(expr % base);
        expr = expr / base;
        nb++;
    }
    result[nb] = '\0';
    return (my_revstr(result));
}

int val(char c)
{
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else
        return (int)c - 'A' + 10;
}

int toDeci(char *str, int base)
{
    int len = my_strlen(str);
    int power = 1;
    int num = 0;
    int i;

    for (i = len - 1; i >= 0; i--) {
        num += val(str[i]) * power;
        power = power * base;
    }
    return (num);
}
