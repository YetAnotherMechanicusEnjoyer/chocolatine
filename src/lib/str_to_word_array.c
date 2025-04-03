/*
** EPITECH PROJECT, 2024
** lib
** File description:
** str_to_word_array.c
*/

#include "my.h"

static size_t is_separator(const char c, const char *separators)
{
    for (size_t i = 0; separators[i] != '\0'; i++) {
        if (c == separators[i])
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

static size_t count_words(const char *str, const size_t len)
{
    size_t i = 0;
    size_t nb_word = 0;

    for (; i < len; i++) {
        if (str[i] != '\0')
            nb_word += 1;
        for (; str[i] != '\0'; i++);
    }
    return nb_word;
}

static char *handle_sep(const char *str, const char *sep, const size_t reverse)
{
    char *cpy = malloc(sizeof(char) * get_len(str) + 1);
    size_t i = 0;

    for (; str[i] != '\0'; i++) {
        if (is_separator(str[i], sep) && !reverse)
            cpy[i] = '\0';
        else
            cpy[i] = str[i];
    }
    cpy[i] = '\0';
    return cpy;
}

static char **str_to_word_array(char *string, const size_t len)
{
    size_t word_len = 0;
    size_t i = 0;
    size_t count = count_words(string, len);
    char **array = malloc(sizeof(char *) * (count + 1));

    if (!array)
        return NULL;
    for (size_t index = 0; index < len; index++) {
        if (!(string[index] == '\0')) {
            word_len = get_len(&string[index]);
            array[i] = strn_dup(&string[index], word_len);
            array[i][word_len] = '\0';
            index += word_len;
            i++;
        }
    }
    free(string);
    array[i] = NULL;
    return array;
}

char **slice(const char *str, const char *separators, const size_t reverse)
{
    size_t len = 0;
    char *string = NULL;
    char **arr = NULL;
    char *new_str = NULL;

    if (!str || !separators)
        return NULL;
    len = get_len(str);
    new_str = str_dup(str);
    string = handle_sep(new_str, separators, reverse);
    free(new_str);
    if (!string)
        return NULL;
    arr = str_to_word_array(string, len);
    return arr;
}
