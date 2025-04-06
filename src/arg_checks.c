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

long	ft_atol(const char *nptr)
{
	int		sign;
	size_t	res;
	size_t	i;

	i = 0;
	sign = 1;
	res = 0;
	while (nptr[i] <= 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10) + (nptr[i] - '0');
		i++;
	}
	return ((long)(res * sign));
}

int	number_controllor(char *arr)
{
	int	i;

	i = 0;
	if (arr[i] == '+' || arr[i] == '-')
		i++;
	if (ft_strlen(&arr[i]) == 0)
		return (-1);
	while (arr[i] == '0')
		i++;
	if (ft_strlen(&arr[i]) >= 11)
		return (-1);
	while (arr[i])
	{
		if (!ft_isdigit(arr[i]))
			return (-1);
		i++;
	}
	return (0);
}

void	check_unique(t_sets *sets)
{
	t_node	*check_node;
	t_node	*active_node;

	active_node = sets->stack_a.top;
	while (active_node != 0)
	{
		check_node = active_node->next;
		while (check_node != 0)
		{
			if (active_node->data == check_node->data)
				error_exit(&sets->stack_a, &sets->stack_b, 1);
			check_node = check_node->next;
		}
		active_node = active_node->next;
	}
}

void	single_arg_checker(char *numbers, t_sets *sets)
{
	int		i;
	long	num;
	char	**arr;

	i = -1;
	arr = ft_split(numbers, ' ');
	free(numbers);
	if (arr == NULL)
		error_exit(&sets->stack_a, &sets->stack_b, 1);
	while (arr[++i])
	{
		if (number_controllor(arr[i]) == -1)
		{
			matris_free(arr);
			error_exit(&sets->stack_a, &sets->stack_b, 1);
		}
		num = ft_atol(arr[i]);
		if (num > 2147483647 && num < -2147483648)
		{
			matris_free(arr);
			error_exit(&sets->stack_a, &sets->stack_b, 1);
		}
		add_to_stack(&sets->stack_a, num);
	}
	matris_free(arr);
}

void	arg_checker(char **argv, int argc, t_sets *sets)
{
	char	*str;
	char	*temp;
	int		i;

	i = 0;
	str = NULL;
	while (argv[++i])
	{
		if (ft_strlen(argv[i]) == 0)
			free_imp(str);
		if (ft_strlen(argv[i]) == 0)
			error_exit(&sets->stack_a, &sets->stack_b, 1);
		temp = ft_strjoin(str, argv[i]);
		free_imp(str);
		if (!temp)
			exit(1);
		str = temp;
		temp = ft_strjoin(str, " ");
		free_imp(str);
		if (!temp)
			exit(1);
		str = temp;
	}
	single_arg_checker(str, sets);
}
