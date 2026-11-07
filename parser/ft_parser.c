/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adallari <adrien.allaria@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 18:48:47 by adallari          #+#    #+#             */
/*   Updated: 2026/11/07 16:38:20 by adallari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static t_flags	ft_init_flags(void);
int				ft_parser(const char *s, va_list *params);
int				ft_general_parser(va_list *params, t_flags flags);
int				ft_parse_width(long long arg, t_flags flags, int mode);
int				ft_parse_precision(long long arg, t_flags flags, int mode);

/*
MODE = 0 : uint
MODE = 1 : int
MODE = 2 : hexa
MODE = 3 : ptr
*/
int	ft_parse_width(long long arg, t_flags flags, int mode)
{
	int	arg_len;
	int	prefix;
	int	pad;

	prefix = 0;
	if (mode == 2 || mode == 3)
		arg_len = ft_hexalen(arg);
	else
		arg_len = ft_intlen(arg);
	if (mode == 1)
		prefix = (arg < 0 || flags.space || flags.plus);
	else if (mode == 2)
		prefix = 2 * (flags.sharp && arg);
	else if (mode == 3)
		prefix = 2 * flags.sharp;
	if (!arg && !flags.precision)
		pad = flags.width - prefix;
	else if (flags.precision > arg_len)
		pad = flags.width - flags.precision - prefix;
	else
		pad = flags.width - arg_len - prefix;
	if (flags.zero && flags.precision < 0 && !flags.minus)
		return (ft_putnchar('0', pad));
	else
		return (ft_putnchar(' ', pad));
}

/*
MODE = 0 : uint
MODE = 1 : int
MODE = 2 : hexa
MODE = 3 : ptr
*/
int	ft_parse_precision(long long arg, t_flags flags, int mode)
{
	int	c;

	c = 0;
	if (!arg && !flags.precision)
		return (0);
	if (!mode || mode == 1)
		c += ft_putnchar('0', flags.precision - ft_intlen(arg));
	else if (mode == 2 || mode == 3)
		c += ft_putnchar('0', flags.precision - ft_hexalen(arg));
	if (mode == 2 && flags.spec == 'X')
		c += ft_puthexa(arg, 1);
	else if (mode == 2 || mode == 3)
		c += ft_puthexa(arg, 0);
	else if (arg < 0)
		c += ft_putnbr(-arg);
	else
		c += ft_putnbr(arg);
	return (c);
}

static t_flags	ft_init_flags(void)
{
	t_flags	flags;

	flags.minus = 0;
	flags.plus = 0;
	flags.precision = -1;
	flags.sharp = 0;
	flags.space = 0;
	flags.spec = 0;
	flags.width = -1;
	flags.zero = 0;
	return (flags);
}

int	ft_general_parser(va_list *params, t_flags flags)
{
	int	c;

	c = 0;
	if (flags.spec == 'c')
		c += ft_char_parser(params, flags);
	else if (flags.spec == 's')
		c += ft_string_parser(params, flags);
	else if (flags.spec == 'd' || flags.spec == 'i')
		c += ft_int_parser(params, flags);
	else if (flags.spec == 'u')
		c += ft_uint_parser(params, flags);
	else if (flags.spec == 'p')
		c += ft_ptr_parser(params, flags);
	else if (flags.spec == 'x' || flags.spec == 'X')
		c += ft_hexa_parser(params, flags);
	else if (flags.spec == '%')
		c += ft_percent_parser(flags);
	else
	{
		c += ft_putchar('%');
		c += 1 + ft_putchar(flags.spec);
	}
	return (c);
}

int	ft_parser(const char *s, va_list *params)
{
	int		c;
	t_flags	flags;

	c = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			flags = ft_init_flags();
			s += ft_fill_struct(s, &flags, params);
			c += ft_general_parser(params, flags);
		}
		else
			c += ft_putchar(*s++);
	}
	return (c);
}
