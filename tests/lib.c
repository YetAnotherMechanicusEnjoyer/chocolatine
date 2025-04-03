/*
** EPITECH PROJECT, 2025
** template
** File description:
** lib.c
*/

#include "my.h"
#include <criterion/criterion.h>

Test(str_to_int, test) {
    cr_expect(str_to_int("") == 0);
    cr_expect(str_to_int("9") == 9);
    cr_expect(str_to_int("a") == -1);
    cr_expect(str_to_int("\n") == -1);
    cr_expect(str_to_int("915648") == 915648);
}

Test(int_str, test) {
    cr_expect(str_cmp(int_str(12), "12") == 0);
    cr_expect(str_cmp(int_str(12344), "12344") == 0);
    cr_expect(str_cmp(int_str(41), "41") == 0);
    cr_expect(str_cmp(int_str(0), "0") == 0);
    cr_expect(str_cmp(int_str(-52), "-52") == 0);
}

Test(read_file, test) {
    cr_expect(str_cmp(read_file("tests/example.txt"), "abcdefg\n") == 0);
}

Test(get_len, test) {
    cr_expect(get_len("") == 0);
    cr_expect(get_len("a") == 1);
    cr_expect(get_len("ab") == 2);
    cr_expect(get_len("abc") == 3);
    cr_expect(get_len("abcd") == 4);
}

Test(get_array_len, test) {
    const char *arr1[5] = {NULL, NULL, NULL, NULL, NULL};
    const char *arr2[5] = {"a", NULL, NULL, NULL, NULL};
    const char *arr3[5] = {"a", "b", NULL, NULL, NULL};
    const char *arr4[5] = {"a", "b", "c", NULL, NULL};
    const char *arr5[5] = {"a", "b", "c", "d", NULL};

    cr_expect(get_array_len(arr1) == 0);
    cr_expect(get_array_len(arr2) == 1);
    cr_expect(get_array_len(arr3) == 2);
    cr_expect(get_array_len(arr4) == 3);
    cr_expect(get_array_len(arr5) == 4);
}

Test(get_nb_len, test) {
    cr_expect(get_nb_len(0) == 1);
    cr_expect(get_nb_len(1) == 1);
    cr_expect(get_nb_len(12) == 2);
    cr_expect(get_nb_len(-42) == 2);
    cr_expect(get_nb_len(2452) == 4);
}

Test(str_cmp, test) {
    cr_expect(str_cmp("", "") == 0);
    cr_expect(str_cmp("a", "") == 0);
    cr_expect(str_cmp("", "b") == 0);
    cr_expect(str_cmp("a", "b") == -1);
    cr_expect(str_cmp("a", "a") == 0);
}

Test(str_dup, test) {
    cr_expect(str_cmp(str_dup(""), "") == 0);
    cr_expect(str_cmp(str_dup("a"), "a") == 0);
    cr_expect(str_cmp(str_dup("ab"), "ab") == 0);
    cr_expect(str_cmp(str_dup("abc"), "abc") == 0);
    cr_expect(str_cmp(str_dup("abcd"), "abcd") == 0);
}

Test(str_to_word_array, test) {
    const char *str = "slice ->\ttest successfull\n";
    const char *sep = " \t";
    char **array = slice(str, sep, 0);

    cr_expect(str_cmp(array[0], "slice") == 0);
    cr_expect(str_cmp(array[1], "->") == 0);
    cr_expect(str_cmp(array[2], "test") == 0);
    cr_expect(str_cmp(array[3], "successfull") == 0);
}

Test(write_mess, test) {
    cr_expect(write_mess("write_mess -> test successfull\n") == 0);
    cr_expect(write_mess(NULL) == -1);
}

Test(write_error, test) {
    cr_expect(write_error("write_error -> test successfull\n") == 84);
    cr_expect(write_error(NULL) == -1);
}

Test(swap_int, test) {
    int a = 15;
    int b = 20;

    swap_int(&a, &b);
    cr_expect(a == 20 && b == 15);
}

Test(swap_str, test) {
    char *a = "Hello";
    char *b = ", World!";

    swap_str(&a, &b);
    cr_expect(str_cmp(a, ", World!") == 0 && str_cmp(b, "Hello") == 0);
}
