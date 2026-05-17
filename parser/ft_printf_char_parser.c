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
	char	pad;

	count = 0;
	arg = va_arg(*lparam, int);
	if (flags.zero && !flags.minus)
		pad = '0';
	else
		pad = ' ';
	if (flags.minus)
	{
		count += ft_printf_putchar(arg);
		count += ft_putnchar(pad, flags.width - 1);
	}
	else
	{
		count += ft_putnchar(pad, flags.width - 1);
		count += ft_printf_putchar(arg);
	}
	return (count);
}
