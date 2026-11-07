/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adallari <adrien.allaria@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 19:47:58 by adallari          #+#    #+#             */
/*   Updated: 2026/11/07 15:36:32 by adallari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			ft_hexa_parser(va_list *params, t_flags flags);
int			ft_hexalen(unsigned long arg);
static int	ft_write_prefix(unsigned int arg, t_flags flags);

int	ft_hexalen(unsigned long arg)
{
	int	c;

	c = 0;
	if (!arg)
		return (1);
	while (arg)
	{
		arg /= 16;
		c++;
	}
	return (c);
}

static int	ft_write_prefix(unsigned int arg, t_flags flags)
{
	if (flags.sharp && arg)
	{
		if (flags.spec == 'x')
			return (ft_putstr("0x"));
		else if (flags.spec == 'X')
			return (ft_putstr("0X"));
	}
	return (0);
}

int	ft_hexa_parser(va_list *params, t_flags flags)
{
	int				c;
	unsigned int	arg;

	c = 0;
	arg = va_arg(*params, unsigned int);
	if (flags.minus)
	{
		c += ft_write_prefix(arg, flags);
		c += ft_parse_precision(arg, flags, 2);
		c += ft_parse_width(arg, flags, 2);
	}
	else
	{
		if (flags.zero && flags.precision < 0)
			c += ft_write_prefix(arg, flags);
		c += ft_parse_width(arg, flags, 2);
		if (flags.precision >= 0 || !flags.zero)
			c += ft_write_prefix(arg, flags);
		c += ft_parse_precision(arg, flags, 2);
	}
	return (c);
}
