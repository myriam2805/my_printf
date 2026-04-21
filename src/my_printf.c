/*
** EPITECH PROJECT, 2025
** mini_printf
** File description:
** A function that mimics the printf funtion, but simpler.
*/
#include "../include/my.h"
#include <stdio.h>

static int handle_format_spec(const char *format, int *i,
    va_list *args, flags_t *flags)
{
    int printed = 0;

    (*i)++;
    parse_flags(format, i, flags);
    printed = if_helper_format(format[*i], args, flags);
    return printed;
}

int my_printf(const char *format, ...)
{
    int i = 0;
    int count = 0;
    int printed = 0;
    va_list args;
    flags_t flags;

    va_start(args, format);
    while (format[i] != '\0') {
        if (format[i] == '%')
            printed = handle_format_spec(format, &i, &args, &flags);
        else
            printed = my_putchar(format[i]);
        if (printed < 0)
            return (-1);
        count += printed;
        i++;
    }
    va_end(args);
    return count;
}
