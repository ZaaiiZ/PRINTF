/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 19:15:26 by nil               #+#    #+#             */
/*   Updated: 2026/05/07 19:15:26 by nil               ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_fill_flags(const char *str, t_flags *flags)
{
	int	count;

	count = 0;
	while (is_flags(*str))
	{
		if (*str == '-')
			flags->minus = 1;
		else if (*str == '+')
			flags->plus = 1;
		else if (*str == ' ')
			flags->space = 1;
		else if (*str == '#')
			flags->hash = 1;
		else if (*str == '0')
			flags->zero = 1;
		str++;
		count++;
	}
	return (count);
}

static int	ft_fill_width(const char *str, t_flags *flags, va_list *lparam)
{
	int	count;

	count = 0;
	if (is_digit(*str))
	{
		flags->width = 0;
		while (is_digit(*str))
		{
			flags->width = flags->width * 10 + (*str - '0');
			str++;
			count++;
		}
	}
	else if (*str == '*')
	{
		flags->width = va_arg(*lparam, int);
		if (flags->width < 0)
		{
			flags->minus = 1;
			flags->width = -flags->width;
		}
		count++;
	}
	return (count);
}

static int	ft_fill_precision(const char *str, t_flags *flags, va_list *lparam)
{
	int	count;

	count = 0;
	if (*str == '.')
	{
		flags->precision = 0;
		str++;
		count++;
		if (*str == '*')
		{
			flags->precision = va_arg(*lparam, int);
			if (flags->precision < 0)
				flags->precision = -1;
			count++;
		}
		else
		{
			while (is_digit(*str))
			{
				flags->precision = flags->precision * 10 + (*str - '0');
				str++;
				count++;
			}
		}
	}
	return (count);
}

static int	ft_fill_specifier(const char *str, t_flags *flags)
{
	if (is_specifier(*str))
	{
		flags->specifier = *str;
		return (1);
	}
	return (0);
}

int	ft_fill_struct(const char *str, t_flags *flags, va_list *lparam)
{
	int	count;
	int	n;

	count = 0;

	n = ft_fill_flags(str, flags);
	str += n;
	count += n;

	n = ft_fill_width(str, flags, lparam);
	str += n;
	count += n;

	n = ft_fill_precision(str, flags, lparam);
	str += n;
	count += n;

	n = ft_fill_specifier(str, flags);
	count += n;
	return (count);
}
