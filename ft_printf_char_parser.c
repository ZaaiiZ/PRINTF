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

int	ft_printf_char_parser(t_flags flags, va_list *lparam)
{
	int		count;
	char	arg;

	count = 0;
	arg = va_arg(*lparam, int);
	if (flags.minus)
	{
		count += ft_printf_putchar(arg);
		while (--flags.width > 0)
			count += ft_printf_putchar(' ');
	}
	else
	{
		while (flags.width-- > 1)
			count += ft_printf_putchar(' ');
		count += ft_printf_putchar(arg);
	}
	return (count);
}
