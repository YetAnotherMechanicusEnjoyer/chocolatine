/*
** EPITECH PROJECT, 2024
** B-PSU-100-BDX-1-1-myls-ahmed.al-rawi
** File description:
** write.c
*/

#include "my.h"

int write_mess(const char *mess)
{
    if (!mess)
        return EXIT_FAIL;
    write(COUT, mess, get_len(mess));
    return EXIT_SUCCESS;
}

int write_error(const char *mess)
{
    if (!mess)
        return EXIT_FAIL;
    write(CERR, mess, get_len(mess));
    return EXIT_ERROR;
}
