/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** Scientific notation format printing
*/
#include "../include/my.h"
#include <math.h>

static int get_exponent(double nb)
{
    int exp = 0;
    double tmp = nb;

    if (tmp < 0)
        tmp = -tmp;
    if (tmp == 0.0)
        return 0;
    while (tmp >= 10.0) {
        tmp = tmp / 10.0;
        exp++;
    }
    while (tmp < 1.0) {
        tmp = tmp * 10.0;
        exp--;
    }
    return exp;
}

static void print_mantissa(double mantissa, int precision)
{
    long int_part = (long)mantissa;
    int i = 0;

    my_putnbr((int)int_part);
    my_putchar('.');
    mantissa = mantissa - int_part;
    if (mantissa < 0)
        mantissa = -mantissa;
    while (i < precision) {
        mantissa = mantissa * 10.0;
        my_putchar((int)mantissa + '0');
        mantissa = mantissa - (int)mantissa;
        i++;
    }
}

static int print_exponent_part(int exp, char exp_char)
{
    int count = 0;

    count = count + my_putchar(exp_char);
    if (exp >= 0)
        count = count + my_putchar('+');
    else
        count = count + my_putchar('-');
    if (exp < 0)
        exp = -exp;
    if (exp < 10)
        count = count + my_putchar('0');
    count = count + my_putnbr(exp);
    return count;
}

static double normalize_mantissa(double nb, int exp)
{
    double mantissa = nb;
    int i = 0;

    if (mantissa < 0)
        mantissa = -mantissa;
    while (i < exp && exp > 0) {
        mantissa = mantissa / 10.0;
        i++;
    }
    i = 0;
    while (i < (-exp) && exp < 0) {
        mantissa = mantissa * 10.0;
        i++;
    }
    if (nb < 0)
        mantissa = -mantissa;
    return mantissa;
}

int print_scientific_format(double nb, char exp_char, int precision)
{
    int exp = get_exponent(nb);
    double mantissa = normalize_mantissa(nb, exp);
    int count = 0;

    if (precision < 0)
        precision = 6;
    if (nb < 0)
        count = count + my_putchar('-');
    print_mantissa(mantissa, precision);
    count = count + precision + 2;
    count = count + print_exponent_part(exp, exp_char);
    return count;
}

int print_with_flags_scientific(double nb, const flags_t *flags, char exp_char)
{
    int precision = 6;
    int len = 0;
    int padding = 0;

    len = print_scientific_format(nb, exp_char, precision);
    if (flags->width > len)
        padding = flags->width - len;
    if (flags->minus == 1)
        print_spaces(padding);
    return len + padding;
}

static int should_use_scientific(double nb, int precision)
{
    int exp = get_exponent(nb);

    if (precision <= 0)
        precision = 6;
    if (exp < -4 || exp >= precision)
        return 1;
    return 0;
}

int print_with_flags_general(double nb, const flags_t *flags, char exp_char)
{
    int precision = 6;

    if (should_use_scientific(nb, precision))
        return print_with_flags_scientific(nb, flags, exp_char);
    return print_with_flags_float_no_zeros(nb, flags);
}
