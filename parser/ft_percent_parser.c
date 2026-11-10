/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adallari <adrien.allaria@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 00:00:00 by adallari          #+#    #+#             */
/*   Updated: 2026/11/10 00:00:00 by adallari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_percent_parser(t_flags flags);

int	ft_percent_parser(t_flags flags)
{
	int	c;

	c = 0;
	if (flags.minus)
	{
		c += ft_putchar('%');
		c += ft_putnchar(' ', flags.width - 1);
	}
	else
	{
		if (flags.zero)
			c += ft_putnchar('0', flags.width - 1);
		else
			c += ft_putnchar(' ', flags.width - 1);
		c += ft_putchar('%');
	}
	return (c);
}
