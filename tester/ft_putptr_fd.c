/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor.horel@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 12:55:13 by victor            #+#    #+#             */
/*   Updated: 2026/05/14 12:56:57 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tester.h"

void	ft_putptr_fd(uintptr_t ptr, int fd)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (ptr > 0xf)
		ft_putptr_fd(ptr / 16, fd);
	write(fd, hexa + (ptr % 16), 1);
	return ;
}
