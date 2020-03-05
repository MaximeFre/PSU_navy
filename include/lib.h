/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** lib
*/

#pragma once

#include "../include/struct.h"

#define ABS(x, y) (((x) < (y)) ? ((y) - (x)) : ((x) - (y)))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
#define MINL(x, y) (((x) < (y)) ? (2) : (5))
#define MAX(x, y) (((x) < (y)) ? (y) : (x))
#define MAXL(x, y) (((x) < (y)) ? (5) : (2))

void my_putstr(char const *str);
void my_putchar(char c);
void init_game(int ac, char **av, map_t *map);
int my_put_nbr(int nb);
char *open_file(char const *filepath);
char **str_to_arr(char *file);
int my_strcmp(char const *s1, char const *s2);
int my_strlen(char const *str);
int init_map(char *input, map_t *map);
void fill_line(char **map, int i, char **info);
void fill_col(char **map, int i, char **info);
char **initial_map(void);
int my_getnbr(char const *str);
void first_loop(map_t *map);
void sec_loop(map_t *map);
char *my_revstr(char *str);
char *convertbase(long long int expr, long long int base);
char *malloc_str(int lenght);
void receive_pos(map_t *map);
int check_hit(map_t *map);
void receive_touch(map_t *map, char *pos);
void send_bin(char *input, map_t *map);
int check_valide(char *input);
void check_end(map_t *map);
void attack(map_t *map);
void waiting(map_t *map);
void disp_maps(map_t *map);
int *get_global(void);
