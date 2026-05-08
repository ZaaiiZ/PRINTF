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

int	ft_printf_ptr_parser(va_list lparam)
{
	int				count;
	unsigned long	arg;

	count = 0;
	arg = (unsigned long)va_arg(lparam, void*);
	count += ft_printf_putstr("0x");
	count += ft_printf_puthexa_ptr(arg, "0123456789abcdef");
	count += ft_printf_putchar(' ');
	return (count);
}
