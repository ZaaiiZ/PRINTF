/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putxnbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor.horel@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 13:01:19 by victor            #+#    #+#             */
/*   Updated: 2026/05/14 20:02:41 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tester.h"

void	ft_putxnbr_fd(unsigned int unbr, char *base, int fd)
{
	if (unbr > 0xf)
		ft_putxnbr_fd(unbr / 16, base, fd);
	write(fd, base + (unbr % 16), 1);
	return ;
}
