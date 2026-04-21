/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** Special flag printing functions (base, pointer)
*/
#include "../include/my.h"

static int get_prefix_len(char format, unsigned long nb, const flags_t *flags)
{
    int prefix_len = 0;

    if (flags->hashtag == 1 && nb != 0) {
        if (format == 'o')
            prefix_len = 1;
        if (format == 'x' || format == 'X')
            prefix_len = 2;
    }
    return prefix_len;
}

static void print_base_prefix(char format, unsigned long nb,
    const flags_t *flags)
{
    if (flags->hashtag == 1 && nb != 0) {
        if (format == 'o')
            my_putchar('0');
        if (format == 'x')
            my_putstr("0x");
        if (format == 'X')
            my_putstr("0X");
    }
}

static void do_base_padding(const flags_t *flags, int padding)
{
    if (flags->minus == 0 && flags->zero == 0)
        print_spaces(padding);
    if (flags->zero == 1 && flags->precision < 0 && flags->minus == 0)
        print_zeros(padding);
}

static int calc_precision_zeros(const flags_t *flags, int num_len)
{
    int precision_zeros = 0;

    if (flags->precision >= 0 && flags->precision > num_len)
        precision_zeros = flags->precision - num_len;
    return precision_zeros;
}

int print_with_flags_base(unsigned int nb, char const *base,
    const flags_t *flags, char format)
{
    int base_len = 0;
    int num_len = 0;
    int precision_zeros = 0;
    int total_len = 0;
    int padding = 0;

    while (base[base_len])
        base_len++;
    num_len = count_base_digits(nb, base_len);
    precision_zeros = calc_precision_zeros(flags, num_len);
    total_len = num_len + precision_zeros + get_prefix_len(format, nb, flags);
    if (flags->width > total_len)
        padding = flags->width - total_len;
    do_base_padding(flags, padding);
    print_base_prefix(format, nb, flags);
    print_zeros(precision_zeros);
    my_putbase(nb, base);
    if (flags->minus == 1)
        print_spaces(padding);
    return total_len + padding;
}

static int get_pointer_len(unsigned long address)
{
    unsigned long tmp = address;
    int len = 2;

    if (tmp == 0) {
        len = len + 1;
    } else {
        while (tmp > 0) {
            tmp = tmp / 16;
            len = len + 1;
        }
    }
    return len;
}

int print_with_flags_pointer(void *ptr, const flags_t *flags)
{
    unsigned long address = (unsigned long)ptr;
    int len = get_pointer_len(address);
    int padding = 0;

    if (flags->width > len)
        padding = flags->width - len;
    if (flags->minus == 0)
        print_spaces(padding);
    my_putpointer(ptr);
    if (flags->minus == 1)
        print_spaces(padding);
    return len + padding;
}

int print_with_flags_base_long(unsigned long nb, char const *base,
    const flags_t *flags, char format)
{
    int base_len = 0;
    int num_len = 0;
    int precision_zeros = 0;
    int total_len = 0;
    int padding = 0;

    while (base[base_len])
        base_len++;
    num_len = count_base_digits_long(nb, base_len);
    precision_zeros = calc_precision_zeros(flags, num_len);
    total_len = num_len + precision_zeros + get_prefix_len(format, nb, flags);
    if (flags->width > total_len)
        padding = flags->width - total_len;
    do_base_padding(flags, padding);
    print_base_prefix(format, nb, flags);
    print_zeros(precision_zeros);
    my_putbase(nb, base);
    if (flags->minus == 1)
        print_spaces(padding);
    return total_len + padding;
}
