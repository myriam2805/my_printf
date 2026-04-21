##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## A Makefile to compile our library.
##

NAME = libmy.a

SRC = src/flags_helpers.c \
	src/float_rounding.c \
	src/if_helper_format.c \
	src/long_helpers.c \
	src/my_printf.c \
	src/my_putbase.c \
	src/my_putchar.c \
	src/my_putnbr.c \
	src/my_putpointer.c \
	src/my_putstr.c \
	src/my_unsignedint.c \
	src/parse_flags.c \
	src/print_float_formats.c \
	src/print_float_no_zeros.c \
	src/print_long_formats.c \
	src/print_scientific.c \
	src/print_with_flags_special.c \
	src/print_with_flags.c

OBJ = $(SRC:.c=.o)

HEADER = src/my.h

all:
	clang -c $(SRC)
	ar rc $(NAME) *.o
	cp $(HEADER) include/
clean:
	rm -f *.o
fclean: clean
	rm -f $(NAME)
compile: all
	clang -o test main.c -L. -lmy -Iinclude
re: fclean all
