/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 12:49:02 by alermi            #+#    #+#             */
/*   Updated: 2025/03/22 12:49:04 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <unistd.h>

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	add_to_stack(stack_b, stack_a->top->data);
	remove_node(stack_a, stack_a->top);
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack_b, t_stack *stack_a)
{
	add_to_stack(stack_b, stack_a->top->data);
	remove_node(stack_a, stack_a->top);
	write(1, "pb\n", 3);
}

void	ra(t_stack *stack_a)
{
	t_node	*tmp;
	
	stack_a->bottom->next = stack_a->top;
	stack_a->top->prev = stack_a->bottom;
	stack_a->top = stack_a->top->next;
	stack_a->top->prev->next = NULL;
	stack_a->top->prev = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_stack *stack_b) // kullanılmadı -> kullanılabilir
{
    t_node	*tmp;
	
	stack_b->bottom->next = stack_b->top;
	stack_b->top->prev = stack_b->bottom;
	stack_b->top = stack_b->top->next;
	stack_b->top->prev->next = NULL;
	stack_b->top->prev = NULL;
	write(1, "rb\n", 3);
}
