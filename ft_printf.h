/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adallari <adrien.allaria@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 15:17:14 by adallari          #+#    #+#             */
/*   Updated: 2026/11/07 16:36:03 by adallari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

//STRUCTURE

typedef struct s_flags
{
	char	spec;
	char	minus;
	char	plus;
	char	zero;
	char	space;
	char	sharp;
	int		width;
	int		precision;
}			t_flags;

//FT_PRINTF.C

int	ft_printf(const char *format, ...);

//DISPLAY

int	ft_putchar(char c);
int	ft_putnchar(char c, int n);
int	ft_putnbr(long n);
int	ft_putstr(char *s);
int	ft_puthexa(unsigned long n, int caps);

//PARSER

int	ft_general_parser(va_list *params, t_flags flags);
int	ft_parser(const char *s, va_list *params);
int	ft_parse_width(long long arg, t_flags flags, int mode);
int	ft_parse_precision(long long arg, t_flags flags, int mode);
int	ft_char_parser(va_list *params, t_flags flags);
int	ft_string_parser(va_list *params, t_flags flags);
int	ft_int_parser(va_list *params, t_flags flags);
int	ft_uint_parser(va_list *params, t_flags flags);
int	ft_ptr_parser(va_list *params, t_flags flags);
int	ft_hexa_parser(va_list *params, t_flags flags);
int	ft_percent_parser(t_flags flags);

//FLAGS

int	ft_fill_struct(const char *s, t_flags *flags, va_list *params);
int	ft_fill_flags(const char *s, t_flags *flags);
int	ft_fill_width(const char *s, t_flags *flags, va_list *params);
int	ft_fill_precision(const char *s, t_flags *flags, va_list *params);
int	ft_fill_spec(const char *s, t_flags *flags);

//UTILS

int	ft_isflags(char c);
int	ft_isdigit(char c);
int	ft_isspec(char c);
int	ft_strlen(const char *s);
int	ft_intlen(long n);
int	ft_hexalen(unsigned long arg);

#endif