/*
** EPITECH PROJECT, 2025
** my_putstr
** File description:
** A function that prints strings.
*/
#include "../include/my.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    write(1, str, i);
    return i;
}
