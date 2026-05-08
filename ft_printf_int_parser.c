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

static int	ft_len_int(int arg)
{
	int	len;

	len = 0;
	if (arg == -2147483648)
		return (10);
	else if (arg < 0)
	{
		len += ft_len_int(-arg);
		return (len);
	}
	else
	{
		while (arg > 0)
		{
			arg /= 10;
			len++;
		}
	}
	if (len == 0)
		return (++len);
	else
		return (len);
}

static int	ft_printf_width_putint(int arg, t_flags flags)
{
	int	count;
	int	i;

	count = 0;
	if (flags.precision == 0 && arg == 0)
		i = flags.width - (flags.plus || flags.space);
	else if (flags.precision < ft_len_int(arg))
		i = flags.width - ft_len_int(arg) - (flags.plus || flags.space);
	else
		i = flags.width - flags.precision - (flags.plus || flags.space);
	while (i-- > 0)
	{
		if (flags.precision == -1 && flags.zero && !flags.minus)
			count += ft_printf_putchar('0');
		else
			count += ft_printf_putchar(' ');
	}
	return (count);
}

static int	ft_printf_precision_putint(int arg, t_flags flags)
{
	int	count;
	int	i;

	count = 0;
	i = flags.precision - ft_len_int(arg);
	while (i-- > 0)
		count += ft_printf_putchar('0');
	if (!(flags.precision == 0 && arg == 0))
		count += ft_printf_putnbr(arg);
	return (count);
}

static int	ft_write_flags(t_flags flags)
{
	if (flags.plus)
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
		count += ft_write_flags(flags);
		count += ft_printf_precision_putint(arg, flags);
		count += ft_printf_width_putint(arg, flags);	
	}
	else
	{
		if (flags.zero && flags.precision == -1)
			count += ft_write_flags(flags);
		count += ft_printf_width_putint(arg, flags);
		if (flags.precision >= 0 || !flags.zero)
			count += ft_write_flags(flags);
		count += ft_printf_precision_putint(arg, flags);
	}
	return (count);
}
