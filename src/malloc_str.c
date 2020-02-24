/*
** EPITECH PROJECT, 2019
** Epitech
** File description:
** malloc fct
*/

#include "../include/lib.h"
#include <stdlib.h>

char *malloc_str(int lenght)
{
    char *str = malloc(sizeof(char) * (lenght + 1));

    if (str == NULL) {
        return (NULL);
    }
    for (int i = 0; i < lenght; i++) {
        str[i] = '\0';
    }
    return (str);
}
