/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** returns a number, sent to the function as a string
*/

long readnb(char const *str, int i, long nb)
{
    int a = 0;

    for (; ('0' <= str[i] && '9' >= str[i]); i++) {
        if (a == 0)
            nb = nb + (str[i] - '0');
        else
            nb = (nb * 10) + (str[i] - '0');
        a++;
    }
    return (nb);
}

int my_getnbr(char const *str)
{
    int i = 0;
    long nb = 0;
    int nb2;
    int b = 0;

    nb = readnb(str, i, nb);
    if (b == 1)
        nb = nb * -1;
    if (nb > 2147483647 || nb < -2147483647)
        return (0);
    else {
        nb2 = nb;
        return (nb2);
    }
}
