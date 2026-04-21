/*
** EPITECH PROJECT, 2025
** my_putbase
** File description:
** A function that prints a number with a given base
** as a parameter (only unsigned integers).
*/
#include "../include/my.h"

int my_putbase(unsigned long nb, char const *base)
{
    int count = 0;
    unsigned long len = 0;

    while (base[len] != '\0')
        len++;
    if (nb >= len)
        count += my_putbase(nb / len, base);
    count += my_putchar(base[nb % len]);
    return count;
}
