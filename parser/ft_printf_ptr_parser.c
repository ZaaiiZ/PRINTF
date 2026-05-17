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

static int	ft_len_ptr(unsigned long ptr)
{
	int	count;
 
	count = 0;
	if (ptr == 0)
		return (1);
	while (ptr > 0)
	{
		ptr /= 16;
		count++;
	}
	return (count);
}

static int	ft_printf_width_p(unsigned long ptr, t_flags flags)
{
	int	i;

	if (flags.precision == 0 && ptr == 0)
		i = flags.width - 2;
	else if (flags.precision > ft_len_ptr(ptr))
		i = flags.width - flags.precision - 2;
	else
		i = flags.width - ft_len_ptr(ptr) - 2;
	if (flags.zero && flags.precision == -1 && !flags.minus)
		return (ft_putnchar('0', i));
	return (ft_putnchar(' ', i));
}

static int	ft_printf_precision_p(unsigned long ptr, t_flags flags)
{
	int	i;

	if (flags.precision == 0 && ptr == 0)
		return (0);
	i = flags.precision - ft_len_ptr(ptr);
	return (ft_putnchar('0', i));
	
}

static int	ft_print_hex_part(unsigned long arg, t_flags flags)
{
	int	count;

	count = ft_printf_putstr("0x");
	count += ft_printf_precision_p(arg, flags);
	if (!(flags.precision == 0 && arg == 0))
		count += ft_printf_puthexa_ptr(arg, "0123456789abcdef");
	return (count);
}

int	ft_printf_ptr_parser(t_flags flags, va_list *lparam)
{
	int				count;
	unsigned long	arg;

	count = 0;
	arg = (unsigned long)va_arg(*lparam, void*);
	if (flags.minus)
	{
		count += ft_print_hex_part(arg, flags);
		count += ft_printf_width_p(arg, flags);
	}
	else if (flags.zero && flags.precision == -1)
	{
		count += ft_printf_putstr("0x");
		count += ft_printf_width_p(arg, flags);
		if (!(flags.precision == 0 && arg == 0))
			count += ft_printf_puthexa_ptr(arg, "0123456789abcdef");
	}
	else
	{
		count += ft_printf_width_p(arg, flags);
		count += ft_print_hex_part(arg, flags);
	}
	return (count);
}
