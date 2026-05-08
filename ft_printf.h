#ifndef PRINTF_H
#define PRINTF_H

#include <unistd.h>
#include <stdarg.h>

/*
  STRUCTURES
*/

typedef struct	s_flags
{
	int		minus; //bool 0 ou 1
	int		plus;
	int		zero;
	int		space;
	int		hash;
	int		width; //int -1 si absent
	int		precision; //int -1 si absent
	char	specifier;
}			t_flags;

/*
  PROTOTYPES
*/

int		ft_printf_putchar(char c);
int		ft_printf_putstr(char *str);
int		ft_printf_puthexa(unsigned int n, char *base);
int		ft_printf_puthexa_ptr(unsigned long n, char *base);
int		ft_printf_putnbr(int n);
int		ft_printf_putnbr_unsigned(unsigned int n);

t_flags	ft_init_flags(void);
int		ft_printf(const char *str, ...);

int		is_flags(char c);
int		is_digit(char c);
int		is_specifier(char c);

int		ft_fill_struct(const char *str, t_flags *flags);

int		ft_printf_char_parser(t_flags flags, va_list *lparam);

int		ft_printf_string_parser(t_flags flags, va_list *lparam);

int		ft_printf_uint_parser(t_flags flags, va_list *lparam);

int		ft_printf_hexa_parser(t_flags flags, va_list *lparam);

int		ft_printf_ptr_parser(va_list *lparam);

int		ft_printf_int_parser(t_flags flags, va_list *lparam);

int		ft_printf_general_parser(const char *str, va_list *lparam);

#endif
