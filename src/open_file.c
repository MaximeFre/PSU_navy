/*
** EPITECH PROJECT, 2019
** CPE_BSQ_bootstrap_2019
** File description:
** open file
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>

int line_nb(char *file)
{
    int count = 0;

    for (int i = 0; file[i] != '\0'; i++) {
        if (file[i] == '\n')
            count++;
    }
    return (count);
}

int line_length(char *file)
{
    int i = 0;

    for (i = 0; file[i] != '\n'; i++);
    i++;
    return (i);
}

char **str_to_arr(char *file)
{
    int strpl = 0;
    int nb = line_nb(file);
    char **map = malloc(sizeof(char *) * (nb + 1));
    int length = 0;

    map[nb] = NULL;
    for (int a = 0; a < nb; a++) {
        length = line_length(&file[strpl]);
        map[a] = malloc(sizeof(char) * length);
        map[a][length - 1] = '\0';
        for (int z = 0; file[strpl] != '\n'; z++) {
            map[a][z] = file[strpl];
            strpl++;
        }
        strpl++;
    }
    return (map);
}

char *open_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    long long size;
    struct stat buf;
    char *map;

    if (fd == -1)
        return ("error");
    if (stat(filepath, &buf) == 0)
        size = buf.st_size;
    map = malloc(sizeof(char) * (size + 1));
    read(fd, map, size);
    map[size] = '\0';
    return (map);
}
