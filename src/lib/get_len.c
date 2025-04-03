/*
** EPITECH PROJECT, 2024
** get_len.c
** File description:
** get string's length
*/

#include "my.h"

size_t get_len(const char *str)
{
    size_t i = 0;

    if (!str)
        return i;
    for (; str[i]; i++);
    return i;
}

size_t get_array_len(const char **array)
{
    size_t i = 0;

    if (!array)
        return i;
    for (; array[i]; i++);
    return i;
}

size_t get_nb_len(int nb)
{
    size_t len = 1;

    if (nb < 0)
        nb *= -1;
    for (; nb > 9; len++)
        nb /= 10;
    return len;
}
