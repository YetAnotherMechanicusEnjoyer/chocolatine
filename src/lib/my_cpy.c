/*
** EPITECH PROJECT, 2025
** template
** File description:
** my_cpy.c
*/

#include "my.h"

void str_cpy(const char *a, char *b)
{
    size_t i = 0;

    for (; a[i] != '\0'; i++)
        b[i] = a[i];
    b[i] = '\0';
}

void strn_cpy(const char *a, char *b, const size_t n)
{
    size_t i = 0;

    for (; a[i] != '\0' && i < n; i++)
        b[i] = a[i];
    b[i] = '\0';
}

char *str_cat(char *dest, char const *src)
{
    size_t len = get_len(dest);

    str_cpy(src, &dest[len]);
    return dest;
}
