/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor.horel@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 19:15:24 by victor            #+#    #+#             */
/*   Updated: 2026/05/16 09:32:13 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tester.h"

static void	ft_remove_logfiles(void);
static void	ft_test_all(void);

int	main(int argc, char **argv)
{
	ft_remove_logfiles();
	if (argc == 2)
	{
		if (!ft_strncmp(*(argv + 1), "c", 2))
			ft_test_c();
		if (!ft_strncmp(*(argv + 1), "s", 2))
			ft_test_s();
		if (!ft_strncmp(*(argv + 1), "p", 2))
			ft_test_p();
		if (!ft_strncmp(*(argv + 1), "d", 2))
			ft_test_d();
		if (!ft_strncmp(*(argv + 1), "i", 2))
			ft_test_i();
		if (!ft_strncmp(*(argv + 1), "u", 2))
			ft_test_u();
		if (!ft_strncmp(*(argv + 1), "x", 2))
			ft_test_x();
		if (!ft_strncmp(*(argv + 1), "X", 2))
			ft_test_X();
		if (!ft_strncmp(*(argv + 1), "%", 2))
			ft_test_percent();
	}
	else
		ft_test_all();
	return (0);
}

static void	ft_remove_logfiles(void)
{
	remove("SUCCED_LOG.txt");
	remove("FAILED_LOG.txt");
}

static void	ft_test_all(void)
{
	ft_test_c();
	ft_test_s();
	ft_test_p();
	ft_test_d();
	ft_test_i();
	ft_test_u();
	ft_test_x();
	ft_test_X();
	ft_test_percent();
}
