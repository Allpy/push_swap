/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 23:20:27 by alermi            #+#    #+#             */
/*   Updated: 2025/03/25 23:20:27 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_sets	sets;
	t_node	*start;

	ft_memset(&sets, 0, sizeof(t_sets));
	arg_checker(argv, argc, &sets);
	if (is_sorted(&sets.stack_a))
		error_exit(&sets.stack_a, &sets.stack_b, 0);
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
