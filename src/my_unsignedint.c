/*
** EPITECH PROJECT, 2025
** my_unsignedint
** File description:
** A function that prints unsigned integers.
*/
#include "../include/my.h"

int my_unsignedint(int nb)
{
    int count = 0;

    if (nb >= 10)
        count += my_unsignedint(nb / 10);
    count += my_putchar((nb % 10) + '0');
    return count;
}

int my_unsignedlong(unsigned long nb)
{
    int count = 0;

    if (nb >= 10)
        count += my_unsignedlong(nb / 10);
    count += my_putchar((nb % 10) + '0');
    return count;
}
