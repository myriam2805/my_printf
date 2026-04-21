/*
** EPITECH PROJECT, 2025
** my_putnbr
** File description:
** A function that prints integers.
*/
#include "../include/my.h"

static int print_unsigned_nb(unsigned int nb)
{
    int count = 0;

    if (nb >= 10)
        count += print_unsigned_nb(nb / 10);
    count += my_putchar((nb % 10) + '0');
    return count;
}

int my_putnbr(int nb)
{
    int count = 0;
    unsigned int unsigned_nb = 0;

    if (nb < 0) {
        count += my_putchar('-');
        unsigned_nb = (unsigned int)(-nb);
    } else {
        unsigned_nb = (unsigned int)nb;
    }
    count += print_unsigned_nb(unsigned_nb);
    return count;
}

static int print_unsigned_long(unsigned long nb)
{
    int count = 0;

    if (nb >= 10)
        count += print_unsigned_long(nb / 10);
    count += my_putchar((nb % 10) + '0');
    return count;
}

int my_putnbr_long(long nb)
{
    int count = 0;
    unsigned long unsigned_nb = 0;

    if (nb < 0) {
        count += my_putchar('-');
        unsigned_nb = (unsigned long)(-nb);
    } else {
        unsigned_nb = (unsigned long)nb;
    }
    count += print_unsigned_long(unsigned_nb);
    return count;
}
