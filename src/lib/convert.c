/*
** EPITECH PROJECT, 2025
** lib
** File description:
** convert.c
*/

#include "my.h"

static char *add_to_str(char *str, const char to_add)
{
    size_t i = 0;

    for (; str[i] != '\0'; i++);
    str[i] = to_add;
    str[i + 1] = '\0';
    return str;
}

static char *recursive_to_string(const size_t nb, char *result)
{
    if (nb >= 10)
        recursive_to_string(nb / 10, result);
    return add_to_str(result, (nb % 10 + 48));
}

char *int_str(int nb)
{
    size_t len = get_nb_len(nb);
    size_t i = 0;
    char *result = malloc(sizeof(char) * (len + 1));

    if (nb < 0) {
        nb *= -1;
        result[i] = '-';
        i++;
    }
    result[i] = '\0';
    return recursive_to_string(nb, result);
}

static size_t is_num(char c)
{
    if (c < 3)
        return 2;
    if (c >= '0' && c <= '9')
        return 1;
    return EXIT_SUCCESS;
}

int str_to_int(const char *str)
{
    int nb = 0;
    size_t check = 0;
    size_t num = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        num = is_num(str[i]);
        if (num == 0)
            return EXIT_FAIL;
        if (num == 1 && check == 1)
            nb *= 10;
        if (num == 1) {
            nb += (str[i] - 48);
            check = 1;
        }
    }
    return nb;
}
