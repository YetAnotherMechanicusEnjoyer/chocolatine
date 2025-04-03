/*
** EPITECH PROJECT, 2024
** header
** File description:
** my.h
*/

#ifndef MY
    #define MY
    #include <stdarg.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <dirent.h>
    #include <sys/stat.h>

enum {
    EXIT_ERROR = 84,
    EXIT_FAIL = -1,
    EXIT_HELP = 2029,
    COUT = 1,
    CERR = 2,
};

// Initialise
int initialise(const int argc, const char *argv[]);

// Lib
size_t get_len(const char *str);
size_t get_array_len(const char **array);
size_t get_nb_len(const int nb);
char *str_dup(const char *str);
char *strn_dup(const char *str, const size_t n);
void str_cpy(const char *a, char *b);
void strn_cpy(const char *a, char *b, const size_t n);
char *str_cat(char *dest, char const *src);
int write_mess(const char *mess);
int write_error(const char *mess);
int str_cmp(const char *a, const char *b);
int strn_cmp(char const *s1, char const *s2, const size_t n);
char **slice(const char *str, const char *separators, const size_t reverse);
int str_to_int(const char *str);
char *int_str(int nb);
char *read_file(const char *path);
void swap_int(int *a, int *b);
void swap_str(char **a, char **b);
#endif
