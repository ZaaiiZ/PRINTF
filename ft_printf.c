/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adallari <adrien.allaria@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 15:28:31 by adallari          #+#    #+#             */
/*   Updated: 2026/11/04 19:01:11 by adallari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vprintf(const char *s, va_list *params)
{
	if (!s)
		return (-1);
	return (ft_parser(s, params));
}

int	ft_printf(const char *s, ...)
{
	int		c;
	va_list	params;

	if (!s)
		return (-1);
	c = 0;
	va_start(params, s);
	c += ft_vprintf(s, &params);
	va_end(params);
	return (c);
}
