/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** init map
*/

#include "../include/struct.h"
#include "../include/lib.h"
#include <stdlib.h>
#include <unistd.h>

int check_valid(char **map)
{
    int error = 0;
    for (int i = 0; i < 4; i++) {
        if (map[i][2] != map[i][5] && map[i][3] != map[i][6])
            return (84);
        if (map[i][2] != map[i][5]) {
            (ABS(map[i][2], map[i][5]) != i + 1 ? error = 1 : 1);
        }
        if (map[i][3] != map[i][6]) {
            (ABS(map[i][3], map[i][6]) != i + 1 ? error = 1 : 1);
        }
    }
    if (error != 0)
        return (84);
    return (0);
}

int check_coor(char **map)
{
    for (int i = 0; i < 4; i++) {
        if (my_strlen(map[i]) != 7)
            return (84);
        if (map[i][0] - '0' != i + 2)
            return (84);
        if (map[i][1] != ':' && map[i][4] != ':')
            return (84);
        if ((map[i][2] > 'H' && map[i][2] < 'A') ||
        (map[i][5] > 'H' && map[i][5] < 'A'))
            return (84);
        if ((map[i][3] > '8' && map[i][3] < '1') ||
        (map[i][6] > '8' && map[i][6] < '1'))
            return (84);
    }
    if (map[4] != NULL)
        return (84);
    return (0);
}

char **initial_map(void)
{
    char **map = malloc(sizeof(char *) * 11);
    int count = 0;

    map[10] = NULL;
    for (int i = 0; i < 10; i++) {
        map[i] = malloc(sizeof(char) * 18);
        map[i][17] = '\0';
    }
    map[0][0] = ' ';
    map[0][1] = '|';
    for (int i = 0; i < 15; i++) {
        if ((i + 2) % 2 == 0) {
            map[0][i + 2] = count + 'A';
            count++;
        } else
            map[0][i + 2] = ' ';
    }
    for (int i = 0; i < 17; i++)
        map[1][i] = '-';
    map[1][1] = '+';
    for (int i = 2; i < 10; i++)
        map[i][0] = i + '0' - 1;
    for (int i = 2; i < 10; i++)
        map[i][1] = '|';
    for (int i = 2; i < 10; i++) {
        for (int a = 2; a < 17; a++) {
            (a % 2 == 0) ? (map[i][a] = '.') : (map[i][a] = ' ');
        }
    }
    return (map);
}

char **create_map(char **info)
{
    char **map = initial_map();

    for (int i = 0; i < 4; i++) {
        if (info[i][2] == info[i][5])
            fill_col(map, i, info);
        else
            fill_line(map, i, info);
    }
    return (map);
}

int init_map(char *input, map_t *map)
{
    char *file = open_file(input);
    char **mapinfo = str_to_arr(file);

    if (my_strcmp(file, "error") == 0)
        return (84);
    if (check_coor(mapinfo) == 84)
        return (84);
    if (check_valid(mapinfo) == 84)
        return (84);
    map->map = create_map(mapinfo);
    map->end = 0;
    return (0);
}
