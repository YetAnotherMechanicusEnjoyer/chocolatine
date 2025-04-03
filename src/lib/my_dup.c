/*
** EPITECH PROJECT, 2024
** my_dup.c
** File description:
** strdup & arraydup
*/

#include "my.h"

char *str_dup(const char *str)
{
    char *cpy = malloc(sizeof(char) * (get_len(str) + 1));

    if (!cpy)
        return NULL;
    str_cpy(str, cpy);
    return cpy;
}

char *strn_dup(const char *str, const size_t n)
{
    char *cpy = malloc(sizeof(char) * (get_len(str) + 1));

    if (!cpy)
        return NULL;
    strn_cpy(str, cpy, n);
    return cpy;
}
