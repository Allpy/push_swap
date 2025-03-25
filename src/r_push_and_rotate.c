/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_push_and_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 12:49:08 by alermi            #+#    #+#             */
/*   Updated: 2025/03/25 23:31:20 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_stack *stack_a)
{
	t_node	*last;

	if (!stack_a || stack_a->size < 2)
		return ;
	last = stack_a->bottom;
	stack_a->bottom = last->prev;
	stack_a->bottom->next = NULL;
	last->prev = NULL;
	last->next = stack_a->top;
	stack_a->top->prev = last;
	stack_a->top = last;
	write(1, "rra\n", 4);
}
