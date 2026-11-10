/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adallari <adrien.allaria@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 18:24:47 by adallari          #+#    #+#             */
/*   Updated: 2026/11/10 12:18:00 by adallari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			ft_int_parser(va_list *params, t_flags flags);
int			ft_intlen(long n);
static int	ft_write_sign(int arg, t_flags flags);
//static int	ft_int_precision(int arg, t_flags flags);
//static int	ft_int_width(int arg, t_flags flags);

int	ft_intlen(long n)
{
	int	c;

	c = 0;
	if (!n)
		return (1);
	if (n < 0)
		n = -n;
	while (n)
	{
		n /= 10;
		c++;
	}
	return (c);
}

static int	ft_write_sign(int arg, t_flags flags)
{
	if (arg < 0)
		return (ft_putchar('-'));
	else if (flags.plus)
		return (ft_putchar('+'));
	else if (flags.space)
		return (ft_putchar(' '));
	return (0);
}

int	ft_int_parser(va_list *params, t_flags flags)
{
	int	c;
	int	arg;

	c = 0;
	arg = va_arg(*params, int);
	if (flags.minus)
	{
		c += ft_write_sign(arg, flags);
		c += ft_parse_precision(arg, flags, 1);
		c += ft_parse_width(arg, flags, 1);
	}
	else if (flags.zero && flags.precision < 0)
	{
		c += ft_write_sign(arg, flags);
		c += ft_parse_width(arg, flags, 1);
		c += ft_parse_precision(arg, flags, 1);
	}
	else
	{
		c += ft_parse_width(arg, flags, 1);
		c += ft_write_sign(arg, flags);
		c += ft_parse_precision(arg, flags, 1);
	}
	return (c);
}
