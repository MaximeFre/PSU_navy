/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** fill map
*/

#include "../include/struct.h"
#include "../include/lib.h"
#include <stdlib.h>
#include <unistd.h>

void fill_col(char **map, int i, char **info)
{
    int a = 0;
    int line = MIN(info[i][3], info[i][6]) - '0' + 1;

    for (a = 0; a < 17; a++) {
        if (map[0][a] == info[i][2])
            break;
    }
    while (line < (MAX(info[i][3], info[i][6]) - '0' + 2)) {
        map[line][a] = info[i][0];
        line++;
    }
}

void fill_line(char **map, int i, char **info)
{
    int a = 0;
    int col = 0;
    int max = 0;

    for (col = 0; col < 17; col++) {
        if (map[0][col] == info[i][MINL(info[i][2], info[i][5])])
            break;
    }
    for (max = 0; max < 17; max++) {
        if (map[0][max] == info[i][MAXL(info[i][2], info[i][5])])
            break;
    }
    for (a = 0; a < 10; a++) {
        if (map[a][0] == info[i][3])
            break;
    }
    while (col <= max) {
        map[a][col] = info[i][0];
        col += 2;
    }
}
