*This activity has been created as part of the 42 curriculum by adallari.*

<div align="center">

<pre>
██████╗ ██████╗ ██╗███╗   ██╗████████╗███████╗
██╔══██╗██╔══██╗██║████╗  ██║╚══██╔══╝██╔════╝
██████╔╝██████╔╝██║██╔██╗ ██║   ██║   █████╗  
██╔═══╝ ██╔══██╗██║██║╚██╗██║   ██║   ██╔══╝  
██║     ██║  ██║██║██║ ╚████║   ██║   ██║     
╚═╝     ╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝   ╚═╝   ╚═╝     
</pre>

**A custom printf implementation in C — built from scratch at 42.**

[![42](https://img.shields.io/badge/42-School-000000?style=for-the-badge&logo=42&logoColor=white)](https://42.fr)
[![Norminette](https://img.shields.io/badge/Norminette-passing-brightgreen?style=for-the-badge)](https://github.com/42School/norminette)
[![Discord](https://img.shields.io/badge/Discord-iiz2416-5865F2?style=for-the-badge&logo=discord&logoColor=white)](https://discord.com/users)

---

Every conversion has been **hand-built** with full flag support, clean recursion, and minimal memory usage.

</div>

## Description

ft_printf is a reimplementation of the C standard library's `printf` function. The goal is to understand variadic functions, format string parsing, and output formatting by coding everything from scratch. This project produces a static library (`libftprintf.a`) that can be used as a drop-in replacement for `printf` throughout the 42 curriculum.

The implementation is split into three layers:
- **Parsing** — Reads the format string, extracts flags, width, precision, and specifier into a `t_flags` structure.
- **Display** — Low-level output functions for characters, strings, numbers, and hexadecimal values.
- **Formatting** — Applies flags (width, precision, padding, prefixes) to each conversion before output.

## Supported conversions

> Format specifiers handled by `ft_printf`.

| Specifier | Description |
|-----------|-------------|
| `%c` | Prints a single character |
| `%s` | Prints a string |
| `%d` / `%i` | Prints a signed decimal integer |
| `%u` | Prints an unsigned decimal integer |
| `%x` | Prints a number in lowercase hexadecimal |
| `%X` | Prints a number in uppercase hexadecimal |
| `%p` | Prints a pointer address in hexadecimal |
| `%%` | Prints a literal percent sign |

## Flags

> Bonus flags supported for all applicable conversions.

| Flag | Syntax | Description |
|------|--------|-------------|
| `-` | `%-10d` | Left-aligns the output within the given width |
| `0` | `%010d` | Pads with zeros instead of spaces (ignored if `-` is present) |
| `.` | `%.5d` | Sets the minimum number of digits (integers) or max characters (strings) |
| `#` | `%#x` | Adds `0x` / `0X` prefix for hexadecimal conversions |
| `+` | `%+d` | Forces a `+` sign for positive numbers |
| ` ` | `% d` | Adds a space before positive numbers (ignored if `+` is present) |

### Flag usage examples

```c
ft_printf("%-10d", 42);       // "42        "  — left-aligned in 10-wide field
ft_printf("%010d", 42);       // "0000000042"  — zero-padded
ft_printf("%.5d", 42);        // "00042"       — minimum 5 digits
ft_printf("%#x", 255);        // "0xff"        — hex with 0x prefix
ft_printf("%+d", 42);         // "+42"         — explicit positive sign
ft_printf("% d", 42);         // " 42"         — space before positive
ft_printf("%.3s", "hello");   // "hel"         — truncate string to 3 chars
ft_printf("%10.5d", 42);      // "     00042"  — width + precision combined
```

## Project structure

```
ft_printf/
├── ft_printf.c            # Entry point — variadic setup
├── ft_printf.h            # Header — prototypes and t_flags struct
├── parser/
│   ├── ft_parser.c        # Format string parser and shared width/precision logic
│   ├── ft_char_parser.c   # %c conversion
│   ├── ft_string_parser.c # %s conversion
│   ├── ft_int_parser.c    # %d / %i conversion
│   ├── ft_uint_parser.c   # %u conversion
│   ├── ft_hexa_parser.c   # %x / %X conversion
│   ├── ft_ptr_parser.c    # %p conversion
│   └── ft_percent_parser.c# %% conversion
├── display/
│   ├── ft_putchar.c       # Character output + repeated char output
│   ├── ft_putstr.c        # String output
│   ├── ft_putnbr.c        # Decimal number output (recursive)
│   └── ft_puthexa.c       # Hexadecimal number output (recursive)
├── flags/
│   ├── ft_fill.c          # Flag/width/precision/specifier extraction
│   └── ft_utils.c         # Helper functions (isdigit, strlen, etc.)
└── Makefile
```

## Instructions

```bash
make        # Compile the library (libftprintf.a)
make clean  # Remove object files
make fclean # Remove object files and libftprintf.a
make re     # Recompile everything
```

To use the library in your project, include the header and compile with the archive:

```c
#include "ft_printf.h"
```

```bash
cc -Wall -Wextra -Werror your_file.c -L. -lftprintf
```

## Resources

- [C Standard Library Reference — cppreference.com](https://en.cppreference.com/w/c)
- [printf format string — Wikipedia](https://en.wikipedia.org/wiki/Printf_format_string)
- [42 Norminette](https://github.com/42School/norminette)

**AI usage:** Claude was used to generate this README.

---

<div align="center">

*Made with patience and seg faults at 42.*

</div>
