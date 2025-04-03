/*
** EPITECH PROJECT, 2025
** template
** File description:
** my_cmp.c
*/

#include "my.h"

int str_cmp(const char *a, const char *b)
{
    for (size_t i = 0; a[i] && a[i] != '\0' && b[i] && b[i] != '\0'; i++) {
        if (a[i] != b[i])
            return a[i] - b[i];
    }
    return EXIT_SUCCESS;
}

int strn_cmp(char const *s1, char const *s2, const size_t n)
{
    for (size_t i = 0; i < n && s1[i] != '\0' && s2[i] != '\0'; i++){
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
    }
    return EXIT_SUCCESS;
}
