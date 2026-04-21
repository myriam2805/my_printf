/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** Float rounding helpers for significant figures
*/
#include "../include/my.h"

int count_int_digits(long nb)
{
    int count = 0;

    if (nb < 0)
        nb = -nb;
    if (nb == 0)
        return 0;
    while (nb > 0) {
        nb = nb / 10;
        count++;
    }
    return count;
}

int count_leading_zeros(double nb)
{
    int count = 0;
    double frac = nb - (long)nb;

    if (frac < 0)
        frac = -frac;
    while (frac > 0 && frac < 0.1) {
        frac = frac * 10.0;
        count++;
    }
    return count;
}

static int calc_total_decimals(int int_digits, int leading_zeros, int sig_figs)
{
    int total_decimals = 0;

    if (int_digits == 0)
        total_decimals = leading_zeros + sig_figs - 1;
    else {
        total_decimals = sig_figs - int_digits;
        if (total_decimals < 0)
            total_decimals = 0;
    }
    return total_decimals;
}

static double calc_multiplier(int total_decimals)
{
    double multiplier = 1.0;
    int i = 0;

    while (i < total_decimals) {
        multiplier = multiplier * 10.0;
        i++;
    }
    return multiplier;
}

static double do_rounding(double abs_nb, double multiplier)
{
    abs_nb = abs_nb * multiplier;
    if (abs_nb - (long)abs_nb >= 0.499999)
        abs_nb = (long)abs_nb + 1;
    else
        abs_nb = (long)abs_nb;
    return abs_nb / multiplier;
}

double round_sig_figs(double nb, int sig_figs)
{
    double abs_nb = 0.0;
    int int_digits = 0;
    int leading_zeros = 0;
    int total_decimals = 0;
    double multiplier = 0.0;

    if (nb < 0)
        abs_nb = -nb;
    else
        abs_nb = nb;
    int_digits = count_int_digits((long)abs_nb);
    if (int_digits == 0)
        leading_zeros = count_leading_zeros(abs_nb);
    total_decimals = calc_total_decimals(int_digits, leading_zeros, sig_figs);
    multiplier = calc_multiplier(total_decimals);
    abs_nb = do_rounding(abs_nb, multiplier);
    if (nb < 0)
        return (-abs_nb);
    return abs_nb;
}
