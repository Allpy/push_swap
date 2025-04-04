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

int	checker_atoi(char *str, t_sets *sets)
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
		return (-1);
	return ((int)(result * sign));
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
	int		num;
	char	**arr;

	i = -1;
	arr = ft_split(numbers, ' ');
	if (arr == NULL)
		error_exit(&sets->stack_a, &sets->stack_b, 1);
	while (arr[++i])
	{
		if (arr[i][0] == '-' && arr[i][1] == '1' && arr[i][3] == '\0')
			num = -1;
		else
		{
			num = checker_atoi(arr[i], sets);
			if (num == -1)
			{
				matris_free(arr);
				error_exit(&sets->stack_a, &sets->stack_b, 1);
			}
		}
		add_to_stack(&sets->stack_a, num);
	}
	matris_free(arr);
}

void	arg_checker(char **argv, int argc, t_sets *sets)
{
	char	*str;
	int		i;

	i = 1;
	str = NULL;
	if (argc == 2)
		single_arg_checker(argv[1], sets);
	else if (argc > 2)
	{
		while (argv[i])
		{
			str = ft_strjoin(str, argv[i]);
			str = ft_strjoin(str, " ");
			i++;
		}
		single_arg_checker(str, sets);
	}
	else
		error_exit(&sets->stack_a, &sets->stack_b, 1);
	if (is_sorted(&sets->stack_a) && (sets->stack_a.top != 0))
		exit(1);
	else if (is_sorted(&sets->stack_a) && (sets->stack_a.top == 0))
		error_exit(&sets->stack_a, &sets->stack_b, 1);
	check_unique(sets);
}
