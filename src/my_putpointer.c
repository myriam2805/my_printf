/*
** EPITECH PROJECT, 2025
** my_putpointer
** File description:
** A function that prints pointers.
*/
#include "../include/my.h"

int my_putpointer(void *pointer)
{
    unsigned long address = (unsigned long)pointer;
    int count = 0;

    count += my_putstr("0x");
    count += my_putbase(address, "0123456789abcdef");
    return count;
}
