/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** returns the number of characters found in the string
*/

int my_strlen(char const *str)
{
    int nbChar = 0;

    while (*str != '\0') {
        str++;
        nbChar++;
    }
    return (nbChar);
}
