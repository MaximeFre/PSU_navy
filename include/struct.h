/*
** EPITECH PROJECT, 2019
** Epitech
** File description:
** struct define
*/

#ifndef STRUCT_H
    #define STRUCT_H

typedef struct map_s {
    char **map;
    char **map_two;
    int pid;
    char *pos;
    int win;
    int end;
    int winner;
} map_t;

#endif /* STRUCT_H_ */
