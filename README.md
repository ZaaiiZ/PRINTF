# ft_printf

A custom implementation of the C standard library function `printf`, developed as part of the 42 School cursus.

## Overview

`ft_printf` replicates the behavior of the standard `printf` function, handling formatted output conversion and writing to the standard output. The function returns the total number of characters printed.

```c
int ft_printf(const char *format, ...);
```

## Supported Conversions

| Specifier | Description |
|-----------|-------------|
| `%c` | Prints a single character |
| `%s` | Prints a string (or `(null)` if NULL) |
| `%p` | Prints a pointer address in hexadecimal with `0x` prefix |
| `%d` | Prints a signed decimal integer |
| `%i` | Prints a signed decimal integer |
| `%u` | Prints an unsigned decimal integer |
| `%x` | Prints an unsigned hexadecimal integer (lowercase) |
| `%X` | Prints an unsigned hexadecimal integer (uppercase) |
| `%%` | Prints a literal percent sign |

## Supported Flags

| Flag | Description |
|------|-------------|
| `-` | Left-justify the output within the given field width |
| `0` | Pad with zeros instead of spaces (ignored when `-` is present) |
| `+` | Forces a plus sign for positive numbers (`%d`, `%i`) |
| ` ` (space) | Prints a space before positive numbers (ignored when `+` is present) |
| `#` | Adds `0x`/`0X` prefix for non-zero hexadecimal values (`%x`, `%X`) |

## Width and Precision

| Feature | Syntax | Description |
|---------|--------|-------------|
| Minimum width | `%5d` | Minimum number of characters to output |
| Dynamic width | `%*d` | Width specified as an argument |
| Precision | `%.5d` | Minimum digits for integers, max characters for strings |
| Dynamic precision | `%.*d` | Precision specified as an argument |

## Compilation

```bash
make        # Compiles libftprintf.a
make clean  # Removes object files
make fclean # Removes object files and the library
make re     # Full recompile
```

## Usage

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("String: %s\n", "Hello, World!");
    ft_printf("Integer: %d\n", 42);
    ft_printf("Hex: %#x\n", 255);
    ft_printf("Pointer: %p\n", &main);
    ft_printf("Width: %10d\n", 42);
    ft_printf("Precision: %.5d\n", 42);
    ft_printf("Flags: %+05d\n", 42);
    return (0);
}
```

Compile with:
```bash
gcc main.c -L. -lftprintf -o my_program
```

## Project Structure

```
.
├── ft_printf.c                 # Core ft_printf and ft_vprintf functions
├── ft_printf.h                 # Header file with prototypes and structures
├── ft_printf_parser.c          # Format string parsing and specifier dispatch
├── ft_fill_struct.c            # Flags, width, precision parsing into t_flags
├── ft_printf_utils.c           # Utility functions (is_flags, is_digit, etc.)
├── ft_printf_char_parser.c     # %c conversion handling
├── ft_printf_string_parser.c   # %s conversion handling
├── ft_printf_int_parser.c      # %d and %i conversion handling
├── ft_printf_uint_parser.c     # %u conversion handling
├── ft_printf_hexa_parser.c     # %x and %X conversion handling
├── ft_printf_ptr_parser.c      # %p conversion handling
├── ft_printf_percent_parser.c  # %% conversion handling
├── ft_printf_putchar.c         # Single character output
├── ft_printf_putstr.c          # String output
├── ft_printf_putnbr.c          # Integer output (signed/unsigned)
├── ft_printf_puthexa.c         # Hexadecimal output
├── Makefile                    # Build configuration
└── tester/                     # Test suite
```

## Testing

The project includes a comprehensive test suite covering all conversions and flag combinations.

```bash
# Compile the tester
gcc tester/*.c -L. -lftprintf -Ltester/LIBFT -lft -o test_runner

# Run all tests
./test_runner

# Run specific conversion tests
./test_runner d    # Test %d
./test_runner s    # Test %s
./test_runner p    # Test %p
```

### Test Results

```
%c  : 102/102 passed
%s  : 262/262 passed
%p  : 220/220 passed
%d  : 429/429 passed
%i  :  55/55  passed
%u  : 182/182 passed
%x  : 257/257 passed
%X  :  60/60  passed
%%  :  75/75  passed
─────────────────────────
Total: 1642/1642 (100%)
```

## Author

**Adrien Allaria** - 42 Student
