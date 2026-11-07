/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adallari <adrien.allaria@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 15:29:06 by adallari          #+#    #+#             */
/*   Updated: 2026/11/07 14:52:42 by adallari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putchar(char c)
{
	return ((int)write(1, &c, 1));
}

int	ft_putnchar(char arg, int n)
{
	int	c;

	c = 0;
	while (n-- > 0)
		c += write(1, &arg, 1);
	return (c);
}
