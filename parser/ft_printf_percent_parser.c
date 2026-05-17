/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percent_parser.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrien <kikiripou@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 18:28:18 by adrien            #+#    #+#             */
/*   Updated: 2026/05/17 18:28:18 by adrien            ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf_percent_parser(t_flags flags)
{
	int	count;

	count = 0;
	if (flags.minus)
	{
		count += ft_printf_putchar('%');
		count += ft_putnchar(' ', flags.width - 1);
	}
	else
	{
		if (flags.zero)
			count += ft_putnchar('0', flags.width - 1);
		else
			count += ft_putnchar(' ', flags.width - 1);
		count += ft_printf_putchar('%');
	}
	return (count);
}
