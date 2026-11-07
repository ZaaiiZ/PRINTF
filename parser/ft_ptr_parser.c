/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adallari <adrien.allaria@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 18:36:33 by adallari          #+#    #+#             */
/*   Updated: 2026/11/07 15:19:37 by adallari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_ptr_parser(va_list *params, t_flags flags);

int	ft_ptr_parser(va_list *params, t_flags flags)
{
	int				c;
	unsigned long	arg;

	c = 0;
	arg = (unsigned long)va_arg(*params, void *);
	if (flags.minus)
	{
		c += ft_putstr("0x");
		c += ft_parse_precision(arg, flags, 3);
		c += ft_parse_width(arg, flags, 3);
	}
	else if (flags.zero && flags.precision < 0)
	{
		c += ft_putstr("0x");
		c += ft_parse_width(arg, flags, 3);
		if (!(!flags.precision && !arg))
			c += ft_puthexa(arg, 0);
	}
	else
	{
		c += ft_parse_width(arg, flags, 3);
		c += ft_putstr("0x");
		c += ft_parse_precision(arg, flags, 3);
	}
	return (c);
}
