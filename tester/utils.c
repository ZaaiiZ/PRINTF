/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor.horel@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 14:06:50 by victor            #+#    #+#             */
/*   Updated: 2026/05/14 20:00:52 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tester.h"

int	ft_isflag(char chr)
{
	if (chr == '+' || chr == '-' || chr == '0' || chr == ' ' || chr == '#')
		return (1);
	else
		return (0);
}

int	ft_isspecifier(char chr)
{
	if (chr == 'c' || chr == 's' || chr == 'p'
		|| chr == 'd' || chr == 'i' || chr == 'u'
		|| chr == 'x' || chr == 'X' || chr == '%')
		return (1);
	else
		return (0);
}
