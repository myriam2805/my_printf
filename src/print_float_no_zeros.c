/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** Float printing without trailing zeros (for %g/%G)
*/
#include "../include/my.h"

static void fill_decimal_buffer(double nb, int dec_places, char *buf)
{
    int i = 0;

    nb = nb - (long)nb;
    if (nb < 0)
        nb = -nb;
    while (i < dec_places) {
        nb = nb * 10.0;
        buf[i] = (int)nb + '0';
        nb = nb - (int)nb;
        i++;
    }
    buf[dec_places] = '\0';
}

static int trim_and_print_decimal(double nb, int dec_places)
{
    char buffer[50];
    int len = dec_places;
    int count = 0;
    int i = 0;

    fill_decimal_buffer(nb, dec_places, buffer);
    while (len > 0 && buffer[len - 1] == '0')
        len--;
    if (len == 0)
        return 0;
    my_putchar('.');
    count = 1;
    while (i < len) {
        my_putchar(buffer[i]);
        i++;
        count++;
    }
    return count;
}

static int calc_dec_places(int int_digits, double rounded, int sig_figs)
{
    int leading_zeros = 0;
    int dec_places = 0;

    if (int_digits == 0) {
        leading_zeros = count_leading_zeros(rounded);
        dec_places = leading_zeros + sig_figs - 1;
    } else {
        dec_places = sig_figs - int_digits;
        if (dec_places < 0)
            dec_places = 0;
    }
    return dec_places;
}

int print_float_no_trailing_zeros(double nb, int sig_figs)
{
    double rounded = round_sig_figs(nb, sig_figs);
    long int_part = (long)rounded;
    int int_digits = count_int_digits(int_part);
    int dec_places = 0;
    int count = 0;

    dec_places = calc_dec_places(int_digits, rounded, sig_figs);
    if (rounded < 0) {
        my_putchar('-');
        int_part = -int_part;
        count++;
    }
    count = count + my_putnbr((int)int_part);
    count = count + trim_and_print_decimal(rounded, dec_places);
    return count;
}

static int calc_base_len(int int_digits, double rounded, int sig_figs,
    int *dec)
{
    int leading_zeros = 0;
    int len = 0;

    if (int_digits == 0) {
        leading_zeros = count_leading_zeros(rounded);
        *dec = leading_zeros + sig_figs - 1;
        len = 1;
    } else {
        *dec = sig_figs - int_digits;
        if (*dec < 0)
            *dec = 0;
        len = int_digits;
    }
    if (rounded < 0)
        len++;
    return len;
}

static int get_len_no_zeros(double nb, int sig_figs)
{
    double rounded = round_sig_figs(nb, sig_figs);
    long int_part = (long)rounded;
    int int_digits = count_int_digits(int_part);
    int dec_places = 0;
    char buffer[50];
    int len = 0;

    len = calc_base_len(int_digits, rounded, sig_figs, &dec_places);
    fill_decimal_buffer(rounded, dec_places, buffer);
    while (dec_places > 0 && buffer[dec_places - 1] == '0')
        dec_places--;
    if (dec_places > 0)
        len = len + 1 + dec_places;
    return len;
}

int print_with_flags_float_no_zeros(double nb, const flags_t *flags)
{
    int sig_figs = 6;
    int len = get_len_no_zeros(nb, sig_figs);
    int padding = 0;

    if (flags->width > len)
        padding = flags->width - len;
    if (flags->minus == 0 && flags->zero == 0)
        print_spaces(padding);
    if (flags->minus == 0 && flags->zero == 1)
        print_zeros(padding);
    print_float_no_trailing_zeros(nb, sig_figs);
    if (flags->minus == 1)
        print_spaces(padding);
    return len + padding;
}
