/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adallari <adrien.allaria@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 15:28:31 by adallari          #+#    #+#             */
/*   Updated: 2026/11/10 12:17:31 by adallari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int		c;
	va_list	params;

	if (!s)
		return (-1);
	va_start(params, s);
	c = ft_parser(s, &params);
	va_end(params);
	return (c);
}
