/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 12:48:57 by alermi            #+#    #+#             */
/*   Updated: 2025/03/22 12:48:58 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_sets	sets;
	t_node	*start;

	if (argc == 1)
		return (0);
	ft_memset(&sets, 0, sizeof(t_sets));
	arg_checker(argv, argc, &sets);
	check_unique(&sets);
	if (is_sorted(&sets.stack_a) && (sets.stack_a.top != 0))
		error_exit(&sets.stack_a, &sets.stack_b, 0);
	else if (is_sorted(&sets.stack_a) && (sets.stack_a.top == 0))
		error_exit(&sets.stack_a, &sets.stack_b, 1);
	index_reset(&sets);
	assign_indexes(&sets);
	if (sets.stack_a.size < 10)
		selection_sort(&sets);
	else
		radix_sort(&sets);
	free_stack(&sets.stack_a);
	free_stack(&sets.stack_b);
	return (0);
}
