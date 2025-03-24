/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_push_and_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 12:49:08 by alermi            #+#    #+#             */
/*   Updated: 2025/03/22 12:49:09 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_stack *stack_a)
{
	t_node *last;

	if (!stack_a || stack_a->size < 2)
		return;
	last = stack_a->bottom;
	stack_a->bottom = last->prev;
	stack_a->bottom->next = NULL;
	last->prev = NULL;
	last->next = stack_a->top;
	stack_a->top->prev = last;
	stack_a->top = last;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack_b)
{
	t_node *last;

	if (!stack_b || stack_b->size < 2)
		return;
	last = stack_b->bottom;
	stack_b->bottom = last->prev;
	stack_b->bottom->next = NULL;
	last->prev = NULL;
	last->next = stack_b->top;
	stack_b->top->prev = last;
	stack_b->top = last;

	write(1, "rrb\n", 4);
}
