/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienallaria <adrienallaria@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 09:44:13 by adrien            #+#    #+#             */
/*   Updated: 2026/05/17 12:02:49 by adrienallar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_init_flags(void)
{
	t_flags flags;

	flags.minus = 0;
	flags.plus = 0;
	flags.zero = 0;
	flags.space = 0;
	flags.hash = 0;
	flags.width = -1;
	flags.precision = -1;
	flags.specifier = '\0';
	return (flags);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list lparam;

	va_start(lparam, str);
	count = ft_printf_general_parser(str, &lparam);
	va_end(lparam);
	return (count);
}

int	ft_vprintf(const char *str, va_list *lparam)
{
	int	count;

	count = ft_printf_general_parser(str, lparam);
	return (count);
}


