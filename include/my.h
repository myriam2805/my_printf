/*
** EPITECH PROJECT, 2025
** my header file
** File description:
** A header to connect all functions together.
*/
#ifndef MY_H_
    #define MY_H_

    #include <stdarg.h>
    #include <unistd.h>

int my_putstr(char const *str);
int my_putnbr(int nb);
int my_putnbr_long(long nb);
int my_putchar(char c);
int my_putbase(unsigned long nb, char const *base);
int my_unsignedint(int nb);
int my_unsignedlong(unsigned long nb);
int my_putpointer(void *pointer);
int my_printf(const char *format, ...);

typedef struct check_flags {
    int width;
    int precision;
    int minus;
    int plus;
    int space;
    int zero;
    int hashtag;
    int length;
} flags_t;

int if_helper_format(char format, va_list *args, const flags_t *flags);
int parse_flags(const char *format, int *i, flags_t *flags);
int print_with_flags_int(int nb, const flags_t *flags);
int print_with_flags_long(long nb, const flags_t *flags);
int print_with_flags_str(char const *str, const flags_t *flags);
int print_with_flags_char(char c, const flags_t *flags);
int print_with_flags_unsigned(unsigned int nb, const flags_t *flags);
int print_with_flags_ulong(unsigned long nb, const flags_t *flags);
int print_with_flags_base(unsigned int nb, char const *base,
    const flags_t *flags, char format);
int print_with_flags_base_long(unsigned long nb, char const *base,
    const flags_t *flags, char format);
int print_with_flags_pointer(void *ptr, const flags_t *flags);
void print_spaces(int count);
void print_zeros(int count);
int count_digits(int nb);
int count_long_digits(long nb);
int count_unsigned_digits(unsigned int nb);
int count_ulong_digits(unsigned long nb);
int count_base_digits(unsigned int nb, int base);
int count_base_digits_long(unsigned long nb, int base);
int print_with_flags_binary(unsigned int nb, const flags_t *flags);
int print_scientific_format(double nb, char exp_char, int precision);
int print_with_flags_scientific(double nb, const flags_t *flags,
    char exp_char);
int print_with_flags_general(double nb, const flags_t *flags, char exp_char);
int print_fixed_float(double nb, int precision);
int print_with_flags_float(double nb, const flags_t *flags);
int print_float_no_trailing_zeros(double nb, int precision);
int print_with_flags_float_no_zeros(double nb, const flags_t *flags);
int count_int_digits(long nb);
int count_leading_zeros(double nb);
double round_sig_figs(double nb, int sig_figs);

#endif
