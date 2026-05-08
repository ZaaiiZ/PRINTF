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

static int	ft_len_uint(unsigned int arg)
{
	int	len;

	len = 0;
	while (arg > 0)
	{
		arg /= 10;
		len ++;
	}
	return (len);
}

static int	ft_printf_width_putuint(unsigned int arg, t_flags flags)
{
	int	count;
	int	i;

	count = 0;
	if (flags.precision < ft_len_uint(arg))
		i = flags.width - ft_len_uint(arg);
	else
		i = flags.width - flags.precision;
	while (i-- > 0)
	{
		if (flags.precision == -1 && flags.zero && !flags.minus)
			count += ft_printf_putchar('0');
		else
			count += ft_printf_putchar(' ');
	}
	return (count);
}

static int	ft_printf_precision_putuint(unsigned int arg, t_flags flags)
{
	int	count;
	int	i;

	count = 0;
	i = flags.precision - ft_len_uint(arg);
	while (i-- > 0)
		count += ft_printf_putchar('0');
	count += ft_printf_putnbr_unsigned(arg);
	return (count);
}

int	ft_printf_uint_parser(t_flags flags, va_list lparam)
{
	int				count;
	unsigned int	arg;

	count = 0;
	arg = va_arg(lparam, unsigned int);
	if (flags.minus)
	{
		count += ft_printf_precision_putuint(arg, flags);
		count += ft_printf_width_putuint(arg, flags);	
	}
	else
	{
		count += ft_printf_width_putuint(arg, flags);
		count += ft_printf_precision_putuint(arg, flags);
	}
	return (count);
}
