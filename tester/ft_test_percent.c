/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor.horel@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 18:47:34 by victor            #+#    #+#             */
/*   Updated: 2026/05/16 08:41:39 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tester.h"

void	ft_test_percent(void)
{
	int	count;

	count = 0;

	count += ft_tester('%', "%%");
	count += ft_tester('%', "%1%");
	count += ft_tester('%', "%2%");
	count += ft_tester('%', "%5%");
	count += ft_tester('%', "%10%");
	count += ft_tester('%', "%20%");
	count += ft_tester('%', "%-1%");
	count += ft_tester('%', "%-2%");
	count += ft_tester('%', "%-5%");
	count += ft_tester('%', "%-10%");
	count += ft_tester('%', "%-20%");
	count += ft_tester('%', "%01%");
	count += ft_tester('%', "%02%");
	count += ft_tester('%', "%05%");
	count += ft_tester('%', "%010%");
	count += ft_tester('%', "%020%");
	count += ft_tester('%', "%-01%");
	count += ft_tester('%', "%-02%");
	count += ft_tester('%', "%-05%");
	count += ft_tester('%', "%-010%");
	count += ft_tester('%', "%-020%");
	count += ft_tester('%', "%--1%");
	count += ft_tester('%', "%--5%");
	count += ft_tester('%', "%---5%");
	count += ft_tester('%', "%----10%");
	count += ft_tester('%', "%0001%");
	count += ft_tester('%', "%0005%");
	count += ft_tester('%', "%00010%");
	count += ft_tester('%', "%--005%");
	count += ft_tester('%', "%-0-05%");
	count += ft_tester('%', "%*%", 0);
	count += ft_tester('%', "%*%", 1);
	count += ft_tester('%', "%*%", 2);
	count += ft_tester('%', "%*%", 5);
	count += ft_tester('%', "%*%", 10);
	count += ft_tester('%', "%*%", 20);
	count += ft_tester('%', "%*%", -1);
	count += ft_tester('%', "%*%", -2);
	count += ft_tester('%', "%*%", -5);
	count += ft_tester('%', "%*%", -10);
	count += ft_tester('%', "%*%", -20);
	count += ft_tester('%', "%0*%", 0);
	count += ft_tester('%', "%0*%", 1);
	count += ft_tester('%', "%0*%", 5);
	count += ft_tester('%', "%0*%", 10);
	count += ft_tester('%', "%0*%", 20);
	count += ft_tester('%', "%0*%", -5);
	count += ft_tester('%', "%0*%", -10);
	count += ft_tester('%', "%-*%", 0);
	count += ft_tester('%', "%-*%", 1);
	count += ft_tester('%', "%-*%", 5);
	count += ft_tester('%', "%-*%", 10);
	count += ft_tester('%', "%-*%", 20);
	count += ft_tester('%', "%-*%", -5);
	count += ft_tester('%', "%-*%", -10);
	count += ft_tester('%', "%-0*%", 0);
	count += ft_tester('%', "%-0*%", 1);
	count += ft_tester('%', "%-0*%", 5);
	count += ft_tester('%', "%-0*%", 10);
	count += ft_tester('%', "%-0*%", 20);
	count += ft_tester('%', "%-0*%", -5);
	count += ft_tester('%', "%-0*%", -10);
	count += ft_tester('%', "abc%%def");
	count += ft_tester('%', "abc%5%def");
	count += ft_tester('%', "abc%-5%def");
	count += ft_tester('%', "abc%05%def");
	count += ft_tester('%', "abc%10%def");
	count += ft_tester('%', "abc%-10%def");
	count += ft_tester('%', "%%%%");
	count += ft_tester('%', "%% %%");
	count += ft_tester('%', "%5%%5%");
	count += ft_tester('%', "%-5%%-5%");
	count += ft_tester('%', "%05%%05%");
	count += ft_tester('%', "%*%%*%", 5, 5);
	count += ft_tester('%', "%*%%*%", -5, -5);

	ft_putendl_fd("%%", 1);
	write(1, "SUCCED TESTS : ", 15);
	ft_putnbr_fd(count, 1);
	write(1, "\n", 1);
	write(1, "FAILED TESTS : ", 15);
	ft_putnbr_fd(75 - count, 1);
	write(1, "\n\n", 2);
	return ;
}
