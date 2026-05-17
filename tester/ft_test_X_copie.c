/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_X.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor.horel@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 18:39:50 by victor            #+#    #+#             */
/*   Updated: 2026/05/16 08:45:06 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tester.h"

void	ft_test_X(void)
{
	int				count;
	unsigned int	xnbr;
	
	count = 0;
	xnbr = 0xFFFF;

	count += ft_tester('X', "%X", xnbr);
	count += ft_tester('X', "%X", 0u);
	count += ft_tester('X', "%X", 1u);
	count += ft_tester('X', "%X", 15u);
	count += ft_tester('X', "%X", 16u);
	count += ft_tester('X', "%X", 255u);
	count += ft_tester('X', "%X", UINT_MAX);
	count += ft_tester('X', "%5X", xnbr);
	count += ft_tester('X', "%10X", xnbr);
	count += ft_tester('X', "%-5X", xnbr);
	count += ft_tester('X', "%-10X", xnbr);
	count += ft_tester('X', "%05X", xnbr);
	count += ft_tester('X', "%010X", xnbr);
	count += ft_tester('X', "%5X", 0u);
	count += ft_tester('X', "%05X", 0u);
	count += ft_tester('X', "%10X", UINT_MAX);
	count += ft_tester('X', "%.0X", 0u);
	count += ft_tester('X', "%.0X", xnbr);
	count += ft_tester('X', "%.1X", xnbr);
	count += ft_tester('X', "%.3X", xnbr);
	count += ft_tester('X', "%.5X", xnbr);
	count += ft_tester('X', "%.10X", xnbr);
	count += ft_tester('X', "%5.0X", 0u);
	count += ft_tester('X', "%5.3X", xnbr);
	count += ft_tester('X', "%8.5X", xnbr);
	count += ft_tester('X', "%-8.5X", xnbr);
	count += ft_tester('X', "%08.5X", xnbr);
	count += ft_tester('X', "%#X", xnbr);
	count += ft_tester('X', "%#X", 0u);
	count += ft_tester('X', "%#X", 255u);
	count += ft_tester('X', "%#X", UINT_MAX);
	count += ft_tester('X', "%#5X", xnbr);
	count += ft_tester('X', "%#10X", xnbr);
	count += ft_tester('X', "%#-10X", xnbr);
	count += ft_tester('X', "%#010X", xnbr);
	count += ft_tester('X', "%#8.5X", xnbr);
	count += ft_tester('X', "%#08.5X", xnbr);
	count += ft_tester('X', "%*X", 8, xnbr);
	count += ft_tester('X', "%*X", -8, xnbr);
	count += ft_tester('X', "%0*X", 8, xnbr);
	count += ft_tester('X', "%0*X", -8, xnbr);
	count += ft_tester('X', "%.*X", 5, xnbr);
	count += ft_tester('X', "%.*X", -5, xnbr);
	count += ft_tester('X', "%*.*X", 8, 5, xnbr);
	count += ft_tester('X', "%*.*X", -8, 5, xnbr);
	count += ft_tester('X', "%*.*X", 8, -5, xnbr);
	count += ft_tester('X', "%#*X", 8, xnbr);
	count += ft_tester('X', "%#*X", -8, xnbr);
	count += ft_tester('X', "%#.*X", 5, xnbr);
	count += ft_tester('X', "%#.*X", -5, xnbr);
	count += ft_tester('X', "%#*.*X", 8, 5, xnbr);
	count += ft_tester('X', "%#*.*X", -8, 5, xnbr);
	count += ft_tester('X', "abc%Xdef", xnbr);
	count += ft_tester('X', "abc%#Xdef", xnbr);
	count += ft_tester('X', "abc%#08Xdef", xnbr);
	count += ft_tester('X', "abc%8.5Xdef", xnbr);
	count += ft_tester('X', "%X%X", 42u, 255u);
	count += ft_tester('X', "%5X%5X", 42u, 255u);
	count += ft_tester('X', "%05X%05X", 42u, 255u);
	count += ft_tester('X', "%#X%#X", 42u, 255u);

	ft_putendl_fd("%X", 1);
	write(1, "SUCCED TESTS : ", 15);
	ft_putnbr_fd(count, 1);
	write(1, "\n", 1);
	write(1, "FAILED TESTS : ", 15);
	ft_putnbr_fd(60 - count, 1);
	write(1, "\n\n", 2);
	return ;
}
