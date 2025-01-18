/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:02:38 by alermi            #+#    #+#             */
/*   Updated: 2025/01/12 16:28:46 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sign_checker(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '+' || argv[i] == '-')
		i++;
	while (argv[i])
	{
		if (argv[i] == '+' || argv[i] == '-')
			return (0);
		i++;
	}
	return (1);
}

int	value_checker(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if ((argv[i] < '0' || argv[i] > '9')
			&& (argv[i] != '+' && argv[i] != '-'))
			return (0);
		i++;
	}
	return (1);
}

int	arg_checker(char **argv)
{
	int	i;
	int	controller;

	i = 1;
	while (argv[i])
	{
		if (!sign_checker(argv[i]) || !value_checker(argv[i]))
			return (-1);
		i++;
	}
	return (1);
}
