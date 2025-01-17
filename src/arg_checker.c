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
	int	sign_flag;
	int	i;

	sign_flag = 0;
	i = 0;
	if (argv[i] == '+' || argv[i] == '-')
	{
		sign_flag = 1;
		i++;
	}
	while (argv[i])
	{
		if (sign_flag == 0 && (argv[i] == '+' || argv[i] == '-'))
			sign_flag = 1;
		else if (sign_flag == 1 && (argv[i] == '+' || argv[i] == '-'))
			return (-1);
		i++;
	}
	return (1);
}

int	arg_checker(char **argv)
{
	int	value_state;
	int	i;
	int	j;

	value_state = 1;
	i = 1;
	j = 0;
	while (argv[i])
	{
		value_state = sign_checker(argv[i]);
		if (value_state == -1)
			return (-1);
		while (argv[i][j])
		{
			if ((argv[i][j] <= '0' && argv[i][j] >= '9')
				|| (argv[i][j] != '+' || argv[i][j] != '-'))
				value_state = -1;
			if (value_state == -1)
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}


// 12