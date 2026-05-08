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

static int	ft_len_hexa(unsigned int arg)
{
	int	len;

	len = 0;
	while (arg > 0)
	{
		arg /= 16;
		len ++;
	}
	return (len);
}

static int	ft_printf_width_puthexa(unsigned int arg, t_flags flags)
{
	int	count;
	int	i;

	count = 0;
	if (flags.precision < ft_len_hexa(arg))
		i = flags.width - ft_len_hexa(arg) - 2 * flags.hash;
	else
		i = flags.width - flags.precision - 2 * flags.hash;
	while (i-- > 0)
	{
		if (flags.precision == -1 && flags.zero && !flags.minus)
			count += ft_printf_putchar('0');
		else
			count += ft_printf_putchar(' ');
	}
	return (count);
}

static int	ft_printf_precision_puthexa(unsigned int arg, t_flags flags)
{
	int	count;
	int	i;

	count = 0;
	i = flags.precision - ft_len_hexa(arg);
	while (i-- > 0)
		count += ft_printf_putchar('0');
	if (flags.specifier == 'X')
		count += ft_printf_puthexa(arg, "0123456789ABCDEF");
	else	
		count += ft_printf_puthexa(arg, "0123456789abcdef");
	return (count);
}

static int	ft_write_flags(t_flags flags)
{
	if (flags.hash)
	{
		if (flags.specifier == 'x')
			return (ft_printf_putstr("0x"));
		else
			return (ft_printf_putstr("0X"));
	}
	return (0);
}

int	ft_printf_hexa_parser(t_flags flags, va_list lparam)
{
	int				count;
	unsigned int	arg;

	count = 0;
	arg = va_arg(lparam, unsigned int);
	if (flags.minus)
	{
		count += ft_write_flags(flags);
		count += ft_printf_precision_puthexa(arg, flags);
		count += ft_printf_width_puthexa(arg, flags);
	}
	else
	{
		if (flags.zero && flags.precision == -1)
			count += ft_write_flags(flags);
		count += ft_printf_width_puthexa(arg, flags);
		if (flags.precision >= 0 || !flags.zero)
			count += ft_write_flags(flags);
		count += ft_printf_precision_puthexa(arg, flags);
	}
	return (count);
}
