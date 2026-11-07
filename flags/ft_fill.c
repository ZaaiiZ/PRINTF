/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adallari <adrien.allaria@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 00:23:38 by adallari          #+#    #+#             */
/*   Updated: 2026/11/07 16:15:56 by adallari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_fill_flags(const char *s, t_flags *flags)
{
	int	c;

	c = 0;
	while (ft_isflags(*s))
	{
		if (*s == '-')
			flags->minus = 1;
		else if (*s == '+')
			flags->plus = 1;
		else if (*s == ' ')
			flags->space = 1;
		else if (*s == '#')
			flags->sharp = 1;
		else if (*s == '0')
			flags->zero = 1;
		s++;
		c++;
	}
	return (c);
}

int	ft_fill_width(const char *s, t_flags *flags, va_list *params)
{
	int	c;

	c = 0;
	if (ft_isdigit(*s))
		flags->width = 0;
	while (ft_isdigit(*s))
	{
		flags->width = flags->width * 10 + (*s - '0');
		s++;
		c++;
	}
	if (*s == '*')
	{
		flags->width = va_arg(*params, int);
		if (flags->width < 0)
		{
			flags->minus = 1;
			flags->width = -flags->width;
		}
		c++;
	}
	return (c);
}

int	ft_fill_precision(const char *s, t_flags *flags, va_list *params)
{
	int	c;

	c = 0;
	if (*s++ == '.')
	{
		flags->precision = 0;
		c = 1;
	}
	while (ft_isdigit(*s))
	{
		flags->precision = flags->precision * 10 + (*s - '0');
		s++;
		c++;
	}
	if (*s == '*')
	{
		flags->precision = va_arg(*params, int);
		if (flags->precision < 0)
			flags->precision = -1;
		c++;
	}
	return (c);
}

int	ft_fill_spec(const char *s, t_flags *flags)
{
	flags->spec = *s;
	if (flags->spec == 'p')
		flags->sharp = 1;
	return (1);
}

int	ft_fill_struct(const char *s, t_flags *flags, va_list *params)
{
	int	c;
	int	tmp;

	c = 0;
	tmp = 0;
	tmp = ft_fill_flags(s, flags);
	s += tmp;
	c += tmp;
	tmp = ft_fill_width(s, flags, params);
	s += tmp;
	c += tmp;
	tmp = ft_fill_precision(s, flags, params);
	s += tmp;
	c += tmp;
	tmp = ft_fill_spec(s, flags);
	c += tmp;
	return (c);
}
