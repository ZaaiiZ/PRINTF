/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrien <kikiripou@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 17:02:51 by adrien            #+#    #+#             */
/*   Updated: 2026/05/04 17:02:51 by adrien            ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_printf_specifier_parser(t_flags flags, va_list *lparam)
{
	int	count;

	count = 0;
	if (flags.specifier == 's')
		count += ft_printf_string_parser(flags, lparam);
	else if (flags.specifier == 'd' || flags.specifier == 'i')
		count += ft_printf_int_parser(flags, lparam);
	else if (flags.specifier == 'u')
		count += ft_printf_uint_parser(flags, lparam);
	else if (flags.specifier == 'x' || flags.specifier == 'X')
		count += ft_printf_hexa_parser(flags, lparam);
	else if (flags.specifier == 'c')
		count += ft_printf_char_parser(flags, lparam);
	else if (flags.specifier == 'p')
		count += ft_printf_ptr_parser(lparam);
	else if (flags.specifier == '%')
		count += ft_printf_putchar('%');
	else
	{
		count += ft_printf_putchar('%');
		count += ft_printf_putchar(flags.specifier);
	}
	return (count);
}

int	ft_printf_general_parser(const char *str, va_list *lparam)
{
	int		count;
	t_flags	flags;

	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			flags = ft_init_flags();
			str += ft_fill_struct(str, &flags);
			count += ft_printf_specifier_parser(flags, lparam);
		}
		else
		{
			count += ft_printf_putchar(*str);
			str++;
		}
	}
	return (count);
}

