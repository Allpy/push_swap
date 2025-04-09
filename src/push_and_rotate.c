/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 12:49:02 by alermi            #+#    #+#             */
/*   Updated: 2025/04/03 19:56:03 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <unistd.h>

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*tmp;

	if (!stack_b->top)
		return ;
	tmp = stack_b->top;
	stack_b->top = tmp->next;
	if (stack_b->top)
		stack_b->top->prev = NULL;
	else
		stack_b->bottom = NULL;
	tmp->next = stack_a->top;
	if (stack_a->top)
		stack_a->top->prev = tmp;
	stack_a->top = tmp;
	if (!stack_a->bottom)
		stack_a->bottom = tmp;
	stack_a->size++;
	stack_b->size--;
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack_b, t_stack *stack_a)
{
	t_node	*tmp;

	if (!stack_a->top)
		return ;
	tmp = stack_a->top;
	stack_a->top = tmp->next;
	if (stack_a->top)
		stack_a->top->prev = NULL;
	else
		stack_a->bottom = NULL;
	tmp->next = stack_b->top;
	if (stack_b->top)
		stack_b->top->prev = tmp;
	stack_b->top = tmp;
	if (!stack_b->bottom)
		stack_b->bottom = tmp;
	stack_b->size++;
	stack_a->size--;
	write(1, "pb\n", 3);
}

void	ra(t_stack *stack_a)
{
	t_node	*tmp;

	if (stack_a->size < 2)
		return ;
	tmp = stack_a->top;
	stack_a->top = tmp->next;
	stack_a->top->prev = NULL;
	tmp->next = NULL;
	tmp->prev = stack_a->bottom;
	stack_a->bottom->next = tmp;
	stack_a->bottom = tmp;
	write(1, "ra\n", 3);
}
