/*
** EPITECH PROJECT, 2025
** lib
** File description:
** swap.c
*/

#include "my.h"

void swap_int(int *a, int *b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void swap_str(char **a, char **b)
{
    char *tmp = *a;

    *a = *b;
    *b = tmp;
}
