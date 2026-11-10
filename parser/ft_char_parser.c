/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adallari <adrien.allaria@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 18:17:15 by adallari          #+#    #+#             */
/*   Updated: 2026/11/07 17:05:28 by adallari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			ft_char_parser(va_list *params, t_flags flags);

int	ft_char_parser(va_list *params, t_flags flags)
{
	int		c;
	char	arg;

	c = 0;
	arg = va_arg(*params, int);
	if (flags.minus)
	{
		c += ft_putchar(arg);
		c += ft_putnchar(' ', flags.width - 1);
	}
	else
	{
		if (flags.zero)
			c += ft_putnchar('0', flags.width - 1);
		else
			c += ft_putnchar(' ', flags.width - 1);
		c += ft_putchar(arg);
	}
	return (c);
}
