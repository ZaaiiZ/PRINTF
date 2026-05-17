/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor.horel@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 18:14:54 by victor            #+#    #+#             */
/*   Updated: 2026/05/16 08:35:37 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tester.h"

void	ft_test_i(void)
{
	int		count;
	int		nbr;
	
	count = 0;
	nbr = 42;
	
	count += ft_tester('i', "%i", nbr);
	count += ft_tester('i', "%i", 0);
	count += ft_tester('i', "%i", 42);
	count += ft_tester('i', "%i", -42);
	count += ft_tester('i', "%i", INT_MAX);
	count += ft_tester('i', "%i", INT_MIN);
	count += ft_tester('i', "%5i", nbr);
	count += ft_tester('i', "%5i", -42);
	count += ft_tester('i', "%-5i", nbr);
	count += ft_tester('i', "%-5i", -42);
	count += ft_tester('i', "%05i", nbr);
	count += ft_tester('i', "%05i", -42);
	count += ft_tester('i', "%+i", nbr);
	count += ft_tester('i', "%+i", -42);
	count += ft_tester('i', "%+05i", nbr);
	count += ft_tester('i', "%+05i", -42);
	count += ft_tester('i', "% i", nbr);
	count += ft_tester('i', "% i", -42);
	count += ft_tester('i', "% 05i", nbr);
	count += ft_tester('i', "% 05i", -42);
	count += ft_tester('i', "%+ i", nbr);
	count += ft_tester('i', "%+ i", -42);
	count += ft_tester('i', "%-05i", nbr);
	count += ft_tester('i', "%-05i", -42);
	count += ft_tester('i', "%.0i", 0);
	count += ft_tester('i', "%.0i", nbr);
	count += ft_tester('i', "%.0i", -42);
	count += ft_tester('i', "%.5i", nbr);
	count += ft_tester('i', "%.5i", -42);
	count += ft_tester('i', "%5.0i", 0);
	count += ft_tester('i', "%8.5i", nbr);
	count += ft_tester('i', "%8.5i", -42);
	count += ft_tester('i', "%-8.5i", nbr);
	count += ft_tester('i', "%-8.5i", -42);
	count += ft_tester('i', "%08.5i", nbr);
	count += ft_tester('i', "%08.5i", -42);
	count += ft_tester('i', "%*i", 8, nbr);
	count += ft_tester('i', "%*i", -8, nbr);
	count += ft_tester('i', "%*i", 8, -42);
	count += ft_tester('i', "%*i", -8, -42);
	count += ft_tester('i', "%.*i", 5, nbr);
	count += ft_tester('i', "%.*i", 5, -42);
	count += ft_tester('i', "%.*i", -5, nbr);
	count += ft_tester('i', "%.*i", -5, -42);
	count += ft_tester('i', "%*.*i", 8, 5, nbr);
	count += ft_tester('i', "%*.*i", 8, 5, -42);
	count += ft_tester('i', "%*.*i", -8, 5, nbr);
	count += ft_tester('i', "%*.*i", -8, 5, -42);
	count += ft_tester('i', "%*.*i", 8, -5, nbr);
	count += ft_tester('i', "abc%idef", nbr);
	count += ft_tester('i', "abc%05idef", nbr);
	count += ft_tester('i', "abc%8.5idef", -42);
	count += ft_tester('i', "%i%i", 42, -42);
	count += ft_tester('i', "%5i%5i", 42, -42);
	count += ft_tester('i', "%05i%05i", 42, -42);

	ft_putendl_fd("%i", 1);
	write(1, "SUCCED TESTS : ", 15);
	ft_putnbr_fd(count, 1);
	write(1, "\n", 1);
	write(1, "FAILED TESTS : ", 15);
	ft_putnbr_fd(55 - count, 1);
	write(1, "\n\n", 2);
	return ;
}
