/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adallari <adrien.allaria@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 18:22:33 by adallari          #+#    #+#             */
/*   Updated: 2026/11/07 16:39:38 by adallari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			ft_string_parser(va_list *params, t_flags flags);
static int	ft_string_width(char *arg, t_flags flags);
static int	ft_string_precision(char *arg, t_flags flags);

static int	ft_string_width(char *arg, t_flags flags)
{
	int	pad;
	int	arg_len;

	arg_len = ft_strlen(arg);
	if (!arg && !flags.precision)
		pad = flags.width;
	else if (flags.precision >= 0 && flags.precision < arg_len)
		pad = flags.width - flags.precision;
	else
		pad = flags.width - arg_len;
	if (flags.zero && flags.precision < 0 && !flags.minus)
		return (ft_putnchar('0', pad));
	else
		return (ft_putnchar(' ', pad));
}

static int	ft_string_precision(char *arg, t_flags flags)
{
	int	c;

	c = 0;
	if (!flags.precision)
		return (0);
	if (flags.precision > -1 && flags.precision < ft_strlen(arg))
	{
		while (flags.precision--)
			c += ft_putchar(*arg++);
	}
	else
		c += ft_putstr(arg);
	return (c);
}

int	ft_string_parser(va_list *params, t_flags flags)
{
	int		c;
	char	*arg;

	c = 0;
	arg = va_arg(*params, char *);
	if (arg == NULL)
		arg = "(null)";
	if (flags.minus)
	{
		c += ft_string_precision(arg, flags);
		c += ft_string_width(arg, flags);
	}
	else
	{
		c += ft_string_width(arg, flags);
		c += ft_string_precision(arg, flags);
	}
	return (c);
}
