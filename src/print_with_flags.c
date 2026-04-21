/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** Functions to help print flags
*/
#include "../include/my.h"

static int print_number_no_sign(unsigned int nb)
{
    int count = 0;

    if (nb >= 10)
        count = count + print_number_no_sign(nb / 10);
    count = count + my_putchar((nb % 10) + '0');
    return count;
}

static int print_int_sign(int is_negative, const flags_t *flags)
{
    if (is_negative) {
        my_putchar('-');
        return 1;
    }
    if (flags->plus) {
        my_putchar('+');
        return 1;
    }
    if (flags->space) {
        my_putchar(' ');
        return 1;
    }
    return 0;
}

static int calc_precision_zeros(const flags_t *flags, int num_len)
{
    int precision_zeros = 0;

    if (flags->precision >= 0 && flags->precision > num_len)
        precision_zeros = flags->precision - num_len;
    return precision_zeros;
}

static void print_int_output(unsigned int nb, int is_negative,
    const flags_t *flags, int precision_zeros)
{
    print_int_sign(is_negative, flags);
    print_zeros(precision_zeros);
    print_number_no_sign(nb);
}

static void print_int_padding(const flags_t *flags, int padding)
{
    if (flags->minus == 0 && flags->zero == 0)
        print_spaces(padding);
    if (flags->minus == 0 && flags->zero == 1 && flags->precision < 0)
        print_zeros(padding);
}

static int calc_int_total_len(int num_len, int precision_zeros,
    int is_negative, const flags_t *flags)
{
    int total_len = num_len + precision_zeros;

    if (is_negative || flags->plus || flags->space)
        total_len++;
    return total_len;
}

int print_with_flags_int(int nb, const flags_t *flags)
{
    int is_negative = 0;
    unsigned int unsigned_nb;
    int num_len;
    int precision_zeros;
    int total_len;
    int padding;

    unsigned_nb = (nb < 0) ? (unsigned int)(-nb) : (unsigned int)nb;
    if (nb < 0)
        is_negative = 1;
    num_len = count_unsigned_digits(unsigned_nb);
    precision_zeros = calc_precision_zeros(flags, num_len);
    total_len = calc_int_total_len(num_len, precision_zeros,
        is_negative, flags);
    padding = (flags->width > total_len) ? flags->width - total_len : 0;
    print_int_padding(flags, padding);
    print_int_output(unsigned_nb, is_negative, flags, precision_zeros);
    if (flags->minus == 1)
        print_spaces(padding);
    return total_len + padding;
}

int print_with_flags_str(char const *str, const flags_t *flags)
{
    int len = 0;
    int padding = 0;

    while (str && str[len])
        len++;
    if (flags->width > len)
        padding = flags->width - len;
    if (flags->minus == 0)
        print_spaces(padding);
    my_putstr(str);
    if (flags->minus == 1)
        print_spaces(padding);
    return len + padding;
}

int print_with_flags_char(char c, const flags_t *flags)
{
    int padding = 0;

    if (flags->width > 1)
        padding = flags->width - 1;
    if (flags->minus == 0)
        print_spaces(padding);
    my_putchar(c);
    if (flags->minus == 1)
        print_spaces(padding);
    return 1 + padding;
}

int print_with_flags_unsigned(unsigned int nb, const flags_t *flags)
{
    int len = count_unsigned_digits(nb);
    int precision_zeros = calc_precision_zeros(flags, len);
    int total_len = len + precision_zeros;
    int padding = 0;

    if (flags->width > total_len)
        padding = flags->width - total_len;
    if (flags->minus == 0 && flags->zero == 0)
        print_spaces(padding);
    if (flags->minus == 0 && flags->zero == 1 && flags->precision < 0)
        print_zeros(padding);
    print_zeros(precision_zeros);
    my_unsignedint(nb);
    if (flags->minus == 1)
        print_spaces(padding);
    return total_len + padding;
}
