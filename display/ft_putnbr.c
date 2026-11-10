/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adallari <adrien.allaria@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 15:35:02 by adallari          #+#    #+#             */
/*   Updated: 2026/11/07 17:01:21 by adallari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

//Factorisation en long pour gerer les int, uint et long
int	ft_putnbr(long n)
{
	int	c;

	c = 0;
	if (n < 10)
		c += ft_putchar(n + '0');
	else
	{
		c += ft_putnbr(n / 10);
		c += ft_putchar(n % 10 + '0');
	}
	return (c);
}
