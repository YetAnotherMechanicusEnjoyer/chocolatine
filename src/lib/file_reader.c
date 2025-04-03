/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** file_reader.c
*/

#include "my.h"

char *read_file(const char *path)
{
    char *buffer = NULL;
    const int fd = open(path, O_RDONLY);
    struct stat st;

    if (fd == -1 || stat(path, &st) == -1)
        return NULL;
    buffer = malloc(sizeof(char) * st.st_size);
    read(fd, buffer, st.st_size);
    buffer[st.st_size] = '\0';
    close(fd);
    return buffer;
}
