/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putulnbr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor.horel@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 12:58:39 by victor            #+#    #+#             */
/*   Updated: 2026/05/14 20:02:06 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tester.h"

void	ft_putulnbr_fd(unsigned long ulnbr, int fd)
{
	char	chr;

	if (ulnbr > 9)
		ft_putulnbr_fd(ulnbr / 10, fd);
	chr = ulnbr % 10;
	chr += '0';
	write(fd, &chr, 1);
	return ;
}
