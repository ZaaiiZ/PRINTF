/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adallari <adrien.allaria@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 18:31:49 by adallari          #+#    #+#             */
/*   Updated: 2026/11/07 15:38:58 by adallari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

//static int	ft_uint_precision(unsigned int arg, t_flags flags);
//static int	ft_uint_width(unsigned int arg, t_flags flags);
int			ft_uint_parser(va_list *params, t_flags flags);

int	ft_uint_parser(va_list *params, t_flags flags)
{
	unsigned int	arg;
	int				c;

	c = 0;
	arg = va_arg(*params, unsigned int);
	if (flags.minus)
	{
		c += ft_parse_precision(arg, flags, 0);
		c += ft_parse_width(arg, flags, 0);
	}
	else
	{
		c += ft_parse_width(arg, flags, 0);
		c += ft_parse_precision(arg, flags, 0);
	}
	return (c);
}
