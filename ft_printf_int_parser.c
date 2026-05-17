/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int_parser.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienallaria <adrienallaria@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 17:02:51 by adrien            #+#    #+#             */
/*   Updated: 2026/05/17 12:10:04 by adrienallar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen(int arg)
{
	int	len;

	if (arg == 0)
		return (1);
	len = 0;
	if (arg == -2147483648)
		return (10);
	if (arg < 0)
		arg = -arg;
	while (arg > 0)
	{
		arg /= 10;
		len++;
	}
	return (len);
}

static int	ft_printf_width_putint(int arg, t_flags flags)
{
	int	i;
	int	numlen;
	int	has_sign;

	numlen = ft_numlen(arg);
	has_sign = (arg < 0 || flags.plus || flags.space);
	if (flags.precision == 0 && arg == 0)
		i = flags.width - has_sign;
	else if (flags.precision > numlen)
		i = flags.width - flags.precision - has_sign;
	else
		i = flags.width - numlen - has_sign;
	if (flags.precision == -1 && flags.zero && !flags.minus)
		return (ft_putnchar('0', i));
	else
		return (ft_putnchar(' ', i));
}

static int	ft_printf_precision_putint(int arg, t_flags flags)
{
	int	count;
	int	i;

	count = 0;
	if (flags.precision == 0 && arg == 0)
		return (0);
	i = flags.precision - ft_numlen(arg);
	count += ft_putnchar('0', i);
	if (arg == -2147483648)
		count += ft_printf_putstr("2147483648");
	else if (arg < 0)
		count += ft_printf_putnbr(-arg);
	else
		count += ft_printf_putnbr(arg);
	return (count);
}

static int	ft_write_sign(t_flags flags, int arg)
{
	if (arg < 0)
		return (ft_printf_putchar('-'));
	else if (flags.plus)
		return (ft_printf_putchar('+'));
	else if (flags.space)
		return (ft_printf_putchar(' '));
	return (0);
}

int	ft_printf_int_parser(t_flags flags, va_list *lparam)
{
	int	count;
	int	arg;

	count = 0;
	arg = va_arg(*lparam, int);
	if (flags.minus)
	{
		count += ft_write_sign(flags, arg);
		count += ft_printf_precision_putint(arg, flags);
		count += ft_printf_width_putint(arg, flags);
	}
	else if (flags.zero && flags.precision == -1)
	{
		count += ft_write_sign(flags, arg);
		count += ft_printf_width_putint(arg, flags);
		count += ft_printf_precision_putint(arg, flags);
	}
	else
	{
		count += ft_printf_width_putint(arg, flags);
		count += ft_write_sign(flags, arg);
		count += ft_printf_precision_putint(arg, flags);
	}
	return (count);
}
