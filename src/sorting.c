/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 23:19:52 by alermi            #+#    #+#             */
/*   Updated: 2025/03/25 23:30:18 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || stack->size < 2)
		return (1);
	current = stack->top;
	while (current->next)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}

void	assign_indexes(t_sets *sets)
{
	t_node	*current;
	t_node	*min_node;
	int		i;

	i = 1;
	while (1)
	{
		min_node = NULL;
		current = sets->stack_a.top;
		while (current)
		{
			if ((min_node == NULL || current->data < min_node->data)
				&& current->index == 0)
			{
				min_node = current;
			}
			current = current->next;
		}
		if (!min_node)
			break ;
		min_node->index = i++;
	}
}
