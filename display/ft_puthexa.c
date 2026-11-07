/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adallari <adrien.allaria@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 15:49:13 by adallari          #+#    #+#             */
/*   Updated: 2026/11/07 15:08:03 by adallari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_recurs_hexa(unsigned long n, char *b)
{
	int	c;

	c = 0;
	if (n < 16)
		c += ft_putchar(b[n]);
	else
	{
		c += ft_recurs_hexa(n / 16, b);
		c += ft_recurs_hexa(n % 16, b);
	}
	return (c);
}

int	ft_puthexa(unsigned long n, int caps)
{
	int		c;
	char	*b;

	c = 0;
	if (!caps)
		b = "0123456789abcdef";
	else
		b = "0123456789ABCDEF";
	c += ft_recurs_hexa(n, b);
	return (c);
}
