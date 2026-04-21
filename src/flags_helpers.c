/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** Helper functions for flag printing
*/
#include "../include/my.h"

void print_spaces(int count)
{
    int i = 0;

    while (i < count) {
        my_putchar(' ');
        i++;
    }
}

void print_zeros(int count)
{
    int i = 0;

    while (i < count) {
        my_putchar('0');
        i++;
    }
}

int count_digits(int nb)
{
    int len = 0;
    int tmp = nb;

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

int count_unsigned_digits(unsigned int nb)
{
    int len = 0;
    unsigned int tmp = nb;

    if (tmp == 0)
        return 1;
    while (tmp > 0) {
        tmp = tmp / 10;
        len++;
    }
    return len;
}

int count_base_digits(unsigned int nb, int base)
{
    int len = 0;
    unsigned int tmp = nb;

    if (tmp == 0)
        return 1;
    while (tmp > 0) {
        tmp = tmp / base;
        len++;
    }
    return len;
}
