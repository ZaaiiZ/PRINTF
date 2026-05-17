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

int	ft_printf_puthexa(unsigned int n, char *base)
{
	int	count;

	count = 0;
	if (n < 16)
		count += ft_printf_putchar(base[n]);
	else
	{
		count += ft_printf_puthexa(n / 16, base);
		count += ft_printf_puthexa(n % 16, base);
	}
	return (count);
}
int	ft_printf_puthexa_ptr(unsigned long n, char *base)
{
	int	count;

	count = 0;
	if (n < 16)
		count += ft_printf_putchar(base[n]);
	else
	{
		count += ft_printf_puthexa_ptr(n / 16, base);
		count += ft_printf_puthexa_ptr(n % 16, base);
	}
	return (count);
}
