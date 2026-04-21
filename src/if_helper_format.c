/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** A function that mimics the printf funtion.
*/
#include "../include/my.h"

static int handle_signed(va_list *args, const flags_t *flags)
{
    if (flags->length == 1)
        return print_with_flags_long(va_arg(*args, long), flags);
    return print_with_flags_int(va_arg(*args, int), flags);
}

static int handle_base(va_list *args, const flags_t *flags, char format)
{
    if (flags->length == 1) {
        if (format == 'o')
            return print_with_flags_base_long(va_arg(*args, unsigned long),
                "01234567", flags, 'o');
        if (format == 'x')
            return print_with_flags_base_long(va_arg(*args, unsigned long),
                "0123456789abcdef", flags, 'x');
        return print_with_flags_base_long(va_arg(*args, unsigned long),
            "0123456789ABCDEF", flags, 'X');
    }
    if (format == 'o')
        return print_with_flags_base(va_arg(*args, unsigned int),
            "01234567", flags, 'o');
    if (format == 'x')
        return print_with_flags_base(va_arg(*args, unsigned int),
            "0123456789abcdef", flags, 'x');
    return print_with_flags_base(va_arg(*args, unsigned int),
        "0123456789ABCDEF", flags, 'X');
}

static int handle_float(va_list *args, const flags_t *flags, char format)
{
    if (format == 'f' || format == 'F')
        return print_with_flags_float(va_arg(*args, double), flags);
    if (format == 'e')
        return print_with_flags_scientific(va_arg(*args, double), flags, 'e');
    if (format == 'E')
        return print_with_flags_scientific(va_arg(*args, double), flags, 'E');
    if (format == 'g')
        return print_with_flags_general(va_arg(*args, double), flags, 'e');
    return print_with_flags_general(va_arg(*args, double), flags, 'E');
}

static int handle_special(va_list *args, const flags_t *flags, char format)
{
    int count = 0;
    
    if (format == 'o' || format == 'x' || format == 'X')
        return handle_base(args, flags, format);
    if (format == 'p')
        return print_with_flags_pointer(va_arg(*args, void *), flags);
    if (format == 'b')
        return print_with_flags_binary(va_arg(*args, unsigned int), flags);
    if (format == 'f' || format == 'F')
        return handle_float(args, flags, format);
    if (format == 'e' || format == 'E' || format == 'g' || format == 'G')
        return handle_float(args, flags, format);
    count += my_putchar('%');
    count += my_putchar(format);
    return count;
}

int if_helper_format(char format, va_list *args, const flags_t *flags)
{
    if (format == 'd' || format == 'i')
        return handle_signed(args, flags);
    if (format == 's')
        return print_with_flags_str(va_arg(*args, char const *), flags);
    if (format == 'c')
        return print_with_flags_char(va_arg(*args, int), flags);
    if (format == '%')
        return my_putchar('%');
    if (format == 'u') {
        if (flags->length == 1)
            return print_with_flags_ulong(va_arg(*args, unsigned long), flags);
        return print_with_flags_unsigned(va_arg(*args, unsigned int), flags);
    }
    return handle_special(args, flags, format);
}
