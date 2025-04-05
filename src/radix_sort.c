/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 19:10:59 by alermi            #+#    #+#             */
/*   Updated: 2025/04/03 19:11:44 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	radix_sort(t_sets *sets)
{
	int	max_bits;
	int	max_index;
	int	bit;
	int	i;
	int	size;

	bit = -1;
	max_bits = 0;
	max_index = sets->stack_a.size - 1;
	while ((max_index >> max_bits) != 0)
		max_bits++;
	while (++bit < max_bits)
	{
		i = -1;
		size = sets->stack_a.size;
		while (++i < size)
		{
			if (((sets->stack_a.top->index >> bit) & 1) == 0)
				pb(&sets->stack_b, &sets->stack_a);
			else
				ra(&sets->stack_a);
		}
		while (sets->stack_b.size > 0)
			pa(&sets->stack_a, &sets->stack_b);
	}
}
