/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrien <kikiripou@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 09:44:13 by adrien            #+#    #+#             */
/*   Updated: 2026/05/04 09:44:13 by adrien            ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf_putnbr_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n < 10)
		count += ft_printf_putchar(n + '0');
	else
	{
		count += ft_printf_putnbr_unsigned(n / 10);
		count += ft_printf_putchar((n % 10) + '0');
	}
	return (count);
}

int	ft_printf_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		count += ft_printf_putstr("-2147483648");
	else if (n < 0)
	{
		count += ft_printf_putchar('-');
		count += ft_printf_putnbr(-n);
	}
	else if (n < 10)
		count += ft_printf_putchar(n + '0');
	else
	{
		count += ft_printf_putnbr(n / 10);
		count += ft_printf_putchar((n % 10) + '0');
	}
	return (count);
}
