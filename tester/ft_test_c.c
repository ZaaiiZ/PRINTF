/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor.horel@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 17:00:55 by victor            #+#    #+#             */
/*   Updated: 2026/05/16 08:31:25 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tester.h"

void	ft_test_c(void)
{
	int		count;
	char	chr;

	count = 0;
	chr = 'X';

	count += ft_tester('c', "%c", chr);
	count += ft_tester('c', "%c", 'A');
	count += ft_tester('c', "%c", '0');
	count += ft_tester('c', "%c", ' ');
	count += ft_tester('c', "%c", '\t');
	count += ft_tester('c', "%c", '\n');
	count += ft_tester('c', "%c", '\0');
	count += ft_tester('c', "%1c", chr);
	count += ft_tester('c', "%2c", chr);
	count += ft_tester('c', "%3c", chr);
	count += ft_tester('c', "%4c", chr);
	count += ft_tester('c', "%5c", chr);
	count += ft_tester('c', "%10c", chr);
	count += ft_tester('c', "%20c", chr);
	count += ft_tester('c', "%-1c", chr);
	count += ft_tester('c', "%-2c", chr);
	count += ft_tester('c', "%-3c", chr);
	count += ft_tester('c', "%-4c", chr);
	count += ft_tester('c', "%-5c", chr);
	count += ft_tester('c', "%-10c", chr);
	count += ft_tester('c', "%-20c", chr);
	count += ft_tester('c', "%01c", chr);
	count += ft_tester('c', "%02c", chr);
	count += ft_tester('c', "%03c", chr);
	count += ft_tester('c', "%05c", chr);
	count += ft_tester('c', "%010c", chr);
	count += ft_tester('c', "%-01c", chr);
	count += ft_tester('c', "%-02c", chr);
	count += ft_tester('c', "%-05c", chr);
	count += ft_tester('c', "%-010c", chr);
	count += ft_tester('c', "%--1c", chr);
	count += ft_tester('c', "%--5c", chr);
	count += ft_tester('c', "%---5c", chr);
	count += ft_tester('c', "%0001c", chr);
	count += ft_tester('c', "%0005c", chr);
	count += ft_tester('c', "%00010c", chr);
	count += ft_tester('c', "%--005c", chr);
	count += ft_tester('c', "%-0-05c", chr);
	count += ft_tester('c', "%*c", 0, chr);
	count += ft_tester('c', "%*c", 1, chr);
	count += ft_tester('c', "%*c", 2, chr);
	count += ft_tester('c', "%*c", 5, chr);
	count += ft_tester('c', "%*c", 10, chr);
	count += ft_tester('c', "%*c", 20, chr);
	count += ft_tester('c', "%*c", -1, chr);
	count += ft_tester('c', "%*c", -2, chr);
	count += ft_tester('c', "%*c", -5, chr);
	count += ft_tester('c', "%*c", -10, chr);
	count += ft_tester('c', "%*c", -20, chr);
	count += ft_tester('c', "%0*c", 0, chr);
	count += ft_tester('c', "%0*c", 1, chr);
	count += ft_tester('c', "%0*c", 5, chr);
	count += ft_tester('c', "%0*c", 10, chr);
	count += ft_tester('c', "%0*c", -5, chr);
	count += ft_tester('c', "%0*c", -10, chr);
	count += ft_tester('c', "%-*c", 0, chr);
	count += ft_tester('c', "%-*c", 1, chr);
	count += ft_tester('c', "%-*c", 5, chr);
	count += ft_tester('c', "%-*c", 10, chr);
	count += ft_tester('c', "%-*c", -5, chr);
	count += ft_tester('c', "%-*c", -10, chr);
	count += ft_tester('c', "%-0*c", 0, chr);
	count += ft_tester('c', "%-0*c", 1, chr);
	count += ft_tester('c', "%-0*c", 5, chr);
	count += ft_tester('c', "%-0*c", 10, chr);
	count += ft_tester('c', "%-0*c", -5, chr);
	count += ft_tester('c', "%-0*c", -10, chr);
	count += ft_tester('c', "%c", '\0');
	count += ft_tester('c', "%1c", '\0');
	count += ft_tester('c', "%2c", '\0');
	count += ft_tester('c', "%5c", '\0');
	count += ft_tester('c', "%10c", '\0');
	count += ft_tester('c', "%-1c", '\0');
	count += ft_tester('c', "%-2c", '\0');
	count += ft_tester('c', "%-5c", '\0');
	count += ft_tester('c', "%-10c", '\0');
	count += ft_tester('c', "%*c", 0, '\0');
	count += ft_tester('c', "%*c", 1, '\0');
	count += ft_tester('c', "%*c", 5, '\0');
	count += ft_tester('c', "%*c", 10, '\0');
	count += ft_tester('c', "%*c", -1, '\0');
	count += ft_tester('c', "%*c", -5, '\0');
	count += ft_tester('c', "%*c", -10, '\0');
	count += ft_tester('c', "%05c", '\0');
	count += ft_tester('c', "%-05c", '\0');
	count += ft_tester('c', "%0*c", 5, '\0');
	count += ft_tester('c', "%0*c", -5, '\0');
	count += ft_tester('c', "abc%cdef", chr);
	count += ft_tester('c', "abc%5cdef", chr);
	count += ft_tester('c', "abc%-5cdef", chr);
	count += ft_tester('c', "abc%cdef", '\0');
	count += ft_tester('c', "abc%5cdef", '\0');
	count += ft_tester('c', "abc%-5cdef", '\0');
	count += ft_tester('c', "%c%c", 'A', 'B');
	count += ft_tester('c', "%c %c", 'A', 'B');
	count += ft_tester('c', "%5c%5c", 'A', 'B');
	count += ft_tester('c', "%-5c%-5c", 'A', 'B');
	count += ft_tester('c', "%*c%*c", 5, 'A', 5, 'B');
	count += ft_tester('c', "%*c%*c", -5, 'A', -5, 'B');
	count += ft_tester('c', "%c%c", '\0', 'B');
	count += ft_tester('c', "%c%c", 'A', '\0');
	count += ft_tester('c', "%c%c", '\0', '\0');

	ft_putendl_fd("%c", 1);
	write(1, "SUCCED TESTS : ", 15);
	ft_putnbr_fd(count, 1);
	write(1, "\n", 1);
	write(1, "FAILED TESTS : ", 15);
	ft_putnbr_fd(102 - count, 1);
	write(1, "\n\n", 2);
	return ;
}
