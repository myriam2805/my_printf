/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** Float and binary format printing functions
*/
#include "../include/my.h"
#include <math.h>

static int print_binary_digits(unsigned long nb)
{
    int count = 0;

    if (nb >= 2)
        count = count + print_binary_digits(nb / 2);
    count = count + my_putchar((nb % 2) + '0');
    return count;
}

static void print_binary_with_padding(unsigned int nb, const flags_t *flags,
    int padding, int precision_zeros)
{
    if (flags->minus == 0 && flags->zero == 0)
        print_spaces(padding);
    if (flags->hashtag == 1 && nb != 0)
        my_putstr("0b");
    if (flags->minus == 0 && flags->zero == 1 && flags->precision < 0)
        print_zeros(padding);
    print_zeros(precision_zeros);
    print_binary_digits(nb);
    if (flags->minus == 1)
        print_spaces(padding);
}

int print_with_flags_binary(unsigned int nb, const flags_t *flags)
{
    int len = count_base_digits(nb, 2);
    int prefix_len = 0;
    int precision_zeros = 0;
    int padding = 0;
    int total_len = len;

    if (flags->hashtag == 1 && nb != 0)
        prefix_len = 2;
    if (flags->precision >= 0 && flags->precision > len)
        precision_zeros = flags->precision - len;
    total_len = len + precision_zeros + prefix_len;
    if (flags->width > total_len)
        padding = flags->width - total_len;
    print_binary_with_padding(nb, flags, padding, precision_zeros);
    return total_len + padding;
}

static void print_float_decimal(double nb, int precision)
{
    int i = 0;

    nb = nb - (long)nb;
    if (nb < 0)
        nb = -nb;
    my_putchar('.');
    while (i < precision) {
        nb = nb * 10.0;
        my_putchar((int)nb + '0');
        nb = nb - (int)nb;
        i++;
    }
}

static int get_float_length(double nb, int precision)
{
    long int_part = (long)nb;
    int len = 0;

    if (int_part < 0)
        int_part = -int_part;
    if (int_part == 0)
        len = 1;
    while (int_part > 0) {
        int_part = int_part / 10;
        len++;
    }
    if (nb < 0)
        len++;
    len = len + 1 + precision;
    return len;
}

int print_fixed_float(double nb, int precision)
{
    long int_part = (long)nb;
    int count = 0;

    if (precision < 0)
        precision = 6;
    if (nb < 0) {
        my_putchar('-');
        int_part = -int_part;
        count++;
    }
    count = count + my_putnbr((int)int_part);
    print_float_decimal(nb, precision);
    count = count + 1 + precision;
    return count;
}

int print_with_flags_float(double nb, const flags_t *flags)
{
    int precision = 6;
    int len = get_float_length(nb, precision);
    int padding = 0;

    if (flags->width > len)
        padding = flags->width - len;
    if (flags->minus == 0 && flags->zero == 0)
        print_spaces(padding);
    if (flags->minus == 0 && flags->zero == 1)
        print_zeros(padding);
    print_fixed_float(nb, precision);
    if (flags->minus == 1)
        print_spaces(padding);
    return len + padding;
}
