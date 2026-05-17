/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrien <kikiripou@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 17:41:44 by adrien            #+#    #+#             */
/*   Updated: 2026/05/04 17:41:44 by adrien            ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnchar(char c, int n)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i++ < n)
		count += write(1, &c, 1);
	return (count);
}

int	is_flags(char c)
{
	if (c == '-' || c == '+' || c == ' ' ||
		c == '#' || c == '0')
		return (1);
	return (0);
}

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_specifier(char c)
{
	if (c == 'd' || c == 'i' || c == 'u' ||
		c == 'x' || c == 'X' || c == 'p' ||
		c == 'c' || c == 's' || c == '%')
		return (1);
	return (0);
}

