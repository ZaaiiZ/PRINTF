/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_tester_format.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor.horel@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:40:35 by victor            #+#    #+#             */
/*   Updated: 2026/05/16 09:32:53 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tester.h"

static void			ft_init_tester_format(t_tester_format *frm);
static const char	*ft_parse_width(const char *format,
						t_tester_format *frm, va_list *arg);
static const char	*ft_parse_precision(const char *format,
						t_tester_format *frm, va_list *arg);

const char	*ft_parse_tester_format(const char *format, t_tester_format *frm, va_list *arg)
{
	ft_init_tester_format(frm);
	while (ft_isflag(*format))
		format++;
	if (!ft_isdigit(*format) && *format != '*'
		&& *format != '.' && !ft_isspecifier(*format))
		return (NULL);
	if (ft_isdigit(*format) || *format == '*')
		format = ft_parse_width(format, frm, arg);
	if (*format != '.' && !ft_isspecifier(*format))
		return (NULL);
	if (*format == '.')
	{
		format++;
		if (!ft_isdigit(*format) && *format != '*' && !ft_isspecifier(*format))
			return (NULL);
		else
			format = ft_parse_precision(format, frm, arg);
	}
	if (!ft_isspecifier(*format))
		return (NULL);
	else
		frm->specifier = *format;
	format++;
	return (format);
}

static void	ft_init_tester_format(t_tester_format *frm)
{
	frm->width_is_star = 0;
	frm->star_width = 0;
	frm->precision_is_star = 0;
	frm->star_precision = 0;
	frm->specifier = 0;
	return ;
}

static const char	*ft_parse_width(const char *format,
						t_tester_format *frm, va_list *arg)
{
	if (*format == '*')
	{
		frm->width_is_star = 1;
		frm->star_width = va_arg(*arg, int);
		format++;
	}
	else
	{
		while (ft_isdigit(*format))
			format++;
	}
	return (format);
}

static const char	*ft_parse_precision(const char *format,
						t_tester_format *frm, va_list *arg)
{
	if (*format == '*')
	{
		frm->precision_is_star = 1;
		frm->star_precision = va_arg(*arg, int);
		format++;
	}
	else if (ft_isdigit(*format))
	{
		while (ft_isdigit(*format))
			format++;
	}
	return (format);
}
