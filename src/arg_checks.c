/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 12:38:51 by alermi            #+#    #+#             */
/*   Updated: 2025/03/22 12:44:30 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/libft/libft.h"
#include <stdio.h>

int	checker_atoi(char *str)
{
	int			i;
	int			sign;
	long int	result;

	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	if (result * sign > 2147483647 || result * sign < -2147483648)
		error_exit();
	return ((int)(result * sign));
}

void	single_arg_checker(char *numbers, t_stack *stack_a)
{
	int		i;
	int		num;
	char	**arr;

	i = 0;
	arr = ft_split(numbers, ' ');
	if (arr == NULL)
		error_exit();
	while (arr[i])
	{
		if (arr[i][0] == '-' && arr[i][1] == '1' && arr[i][3] == '\0')
			num = -1;
		else
		{
			num = checker_atoi(arr[i]);
			if (num == -1)
				error_exit();
			add_to_stack(stack_a, num);
		}
		i++;
	}
	if (i == 1)
		error_exit();
}

void	multiple_arg_checker(char **str, int argc, t_stack *stack_a)
{
	int	i;
	int	num;

	i = 1;
	while (i < argc)
	{
		if (str[i][0] == '-' && str[i][1] == '1' && str[i][2] == '\0')
			num = -1;
		else
		{
			num = checker_atoi(str[i]);
			if (num == -1)
				error_exit();
		}
		add_to_stack(stack_a, num);
		i++;
	}
}

void	arg_checker(char **argv, int argc, t_stack *stack_a)
{
	if (argc == 2)
		single_arg_checker(argv[1], stack_a);
	else if (argc > 2)
		multiple_arg_checker(argv, argc, stack_a);
	else
		error_exit();
}
