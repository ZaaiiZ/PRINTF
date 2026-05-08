/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrien <kikiripou@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 17:02:51 by adrien            #+#    #+#             */
/*   Updated: 2026/05/04 17:02:51 by adrien            ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_len_str(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

static int	ft_printf_precision_putstr(char *arg, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.precision == -1)
		return (ft_printf_putstr(arg));
	while (*arg && flags.precision-- > 0)
	{
		count += ft_printf_putchar(*arg);
		arg++;
	}
	return (count);
}

static int	ft_printf_width_putstr(char *arg, t_flags flags)
{
	int	count;
	int	i;

	count = 0;
	if (flags.precision == -1)
		i = flags.width - ft_len_str(arg);
	else if (flags.precision < ft_len_str(arg))
		i = flags.width - flags.precision;
	else
		i = flags.width - ft_len_str(arg);
	while (i-- > 0)
		count += ft_printf_putchar(' ');
	return (count);
}

int	ft_printf_string_parser(t_flags flags, va_list *lparam)
{
	int		count;
	char	*arg;

	count = 0;
	arg = va_arg(*lparam, char*);
	if (arg == (char*)NULL)
		arg = "(null)\0";
	if (flags.minus)
	{
		count += ft_printf_precision_putstr(arg, flags);
		count += ft_printf_width_putstr(arg, flags);
	}
	else
	{
		count += ft_printf_width_putstr(arg, flags);
		count += ft_printf_precision_putstr(arg, flags);
	}
	return (count);
}
