/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** returns the number of characters found in the string
*/

int my_strlen(char const *str)
{
    int nb_char = 0;

    while (*str != '\0') {
        str++;
        nb_char++;
    }
    return (nb_char);
}

int my_arrlen(char **str)
{
    int nb_line = 0;

    for (int i = 0; str[i]; i++) {
        nb_line++;
    }
    return (nb_line);
}
