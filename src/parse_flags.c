/*
** EPITECH PROJECT, 2025
** parse_flags
** File description:
** Parse flags.
*/
#include "../include/my.h"

static void parse_flag_chars(const char *format, int *i, flags_t *flags)
{
    while (format[*i] && (format[*i] == '-' || format[*i] == '+'
            || format[*i] == ' ' || format[*i] == '0' || format[*i] == '#')) {
        if (format[*i] == '-')
            flags->minus = 1;
        if (format[*i] == '+')
            flags->plus = 1;
        if (format[*i] == ' ')
            flags->space = 1;
        if (format[*i] == '0')
            flags->zero = 1;
        if (format[*i] == '#')
            flags->hashtag = 1;
        (*i)++;
    }
}

static void parse_width(const char *format, int *i, flags_t *flags)
{
    while (format[*i] >= '0' && format[*i] <= '9') {
        flags->width = flags->width * 10 + (format[*i] - '0');
        (*i)++;
    }
}

static void parse_precision(const char *format, int *i, flags_t *flags)
{
    if (format[*i] == '.') {
        (*i)++;
        flags->precision = 0;
        while (format[*i] >= '0' && format[*i] <= '9') {
            flags->precision = flags->precision * 10 + (format[*i] - '0');
            (*i)++;
        }
    }
}

int parse_flags(const char *format, int *i, flags_t *flags)
{
    flags->width = 0;
    flags->precision = -1;
    flags->minus = 0;
    flags->plus = 0;
    flags->space = 0;
    flags->zero = 0;
    flags->hashtag = 0;
    flags->length = 0;
    parse_flag_chars(format, i, flags);
    parse_width(format, i, flags);
    parse_precision(format, i, flags);
    if (format[*i] == 'l') {
        flags->length = 1;
        (*i)++;
    }
    return 0;
}
