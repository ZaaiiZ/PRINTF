/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbuffer_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor.horel@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 15:28:54 by victor            #+#    #+#             */
/*   Updated: 2026/05/15 22:36:30 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tester.h"

void	ft_putbuffer_fd(char *buffer, int size, int fd)
{
	int	x;

	x = 0;
	while (x < size)
	{
		if (*buffer == '\0')
			write(fd, "\\0", 2);
		else if (*buffer == '\n')
			write(fd, "\\n", 2);
		else if (*buffer == '\t')
			write(fd, "\\t", 2);
		else
			write(fd, buffer, 1);
		buffer++;
		x++;
	}
	return ;
}
