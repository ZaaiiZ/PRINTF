/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrien <kikiripou@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 09:44:13 by adrien            #+#    #+#             */
/*   Updated: 2026/05/04 09:44:13 by adrien            ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf_putstr(char *str)
{
	int	count;

	count = 0;
	while (*str)
		count += write(1, str++, 1);
	return (count);
}
