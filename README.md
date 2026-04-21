# my_printf

> A complete reimplementation of the C standard `printf` function — built from scratch in C, following the C99 standard.

## About

`my_printf` is an Epitech project that consists of fully recoding the `printf` function from the C standard library. The function handles all standard flags, format specifiers, and outputs to stdout using only a restricted set of allowed functions.

> Achieved **100% on the Epitech Moulinette** (automated grading system)

---

## Format specifiers

| Specifier | Description |
|-----------|-------------|
| `%s` | String |
| `%d` / `%i` | Signed decimal integer |
| `%u` | Unsigned decimal integer |
| `%c` | Character |
| `%o` | Octal |
| `%x` / `%X` | Hexadecimal (lower / upper) |
| `%p` | Pointer address |
| `%f` | Decimal float |
| `%e` / `%E` | Scientific notation |
| `%g` / `%G` | Shorter of `%e` or `%f` |
| `%%` | Literal `%` |

---

## Flags & modifiers

| Flag | Description |
|------|-------------|
| `-` | Left-align output |
| `+` | Force sign for numbers |
| `0` | Zero-padding |
| `#` | Alternate form |
| ` ` (space) | Space before positive numbers |
| `h` `l` `ll` | Length modifiers |

Width and precision modifiers are also fully supported.

---

## Constraints

The entire libC is forbidden, except:
`va_start` — `va_end` — `va_arg` — `malloc` — `free` — `write`

Everything else (number formatting, string handling, output) was implemented from scratch.

---

## Build

```bash
make        # Compiles and generates libmy.a
make clean  # Removes object files
make fclean # Removes object files and libmy.a
make re     # Rebuilds from scratch
```

---

## Usage

Link `libmy.a` with your project:

```bash
gcc main.c -L. -lmy -o my_program
```

Then use it just like `printf`:

```c
#include "my.h"

int main(void)
{
    my_printf("Hello, %s! You are %d years old.\n", "world", 21);
    return 0;
}
```

---

## Authors

> Built with ❤️ as part of the Epitech curriculum.
