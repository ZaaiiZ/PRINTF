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
	if (flags.specifier == 's')
		return (ft_printf_string_parser(flags, lparam));
	else if (flags.specifier == 'd' || flags.specifier == 'i')
		return (ft_printf_int_parser(flags, lparam));
	else if (flags.specifier == 'u')
		return (ft_printf_uint_parser(flags, lparam));
	else if (flags.specifier == 'x' || flags.specifier == 'X')
		return (ft_printf_hexa_parser(flags, lparam));
	else if (flags.specifier == 'c')
		return (ft_printf_char_parser(flags, lparam));
	else if (flags.specifier == 'p')
		return (ft_printf_ptr_parser(flags, lparam));
	else if (flags.specifier == '%')
		return (ft_printf_percent_parser(flags));
	else
	{
		ft_printf_putchar('%');
		return (ft_printf_putchar(flags.specifier) + 1);
	}
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
			str += ft_fill_struct(str, &flags, lparam);
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

