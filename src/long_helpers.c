/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** Helper functions for long integer counting
*/
#include "../include/my.h"

int count_long_digits(long nb)
{
    int len = 0;
    long tmp = nb;

    if (tmp < 0)
        tmp = -tmp;
    if (tmp == 0)
        return 1;
    while (tmp > 0) {
        tmp = tmp / 10;
        len++;
    }
    return len;
}

int count_ulong_digits(unsigned long nb)
{
    int len = 0;
    unsigned long tmp = nb;

    if (tmp == 0)
        return 1;
    while (tmp > 0) {
        tmp = tmp / 10;
        len++;
    }
    return len;
}

int count_base_digits_long(unsigned long nb, int base)
{
    int len = 0;
    unsigned long tmp = nb;

    if (tmp == 0)
        return 1;
    while (tmp > 0) {
        tmp = tmp / base;
        len++;
    }
    return len;
}
