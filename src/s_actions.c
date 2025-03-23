/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_actions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 12:49:13 by alermi            #+#    #+#             */
/*   Updated: 2025/03/22 12:49:18 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack *stack)
{
    t_node *one;
    t_node *two;

    one = stack->top;
    two = one->next;
    if (!one || !two)
        return;
    one->next = two->next;
    if (two->next)
        two->next->prev = one;
    two->prev = NULL;
    two->next = one;
    one->prev = two;
    stack->top = two;
    if (stack->size == 2)
        stack->bottom = one;
}

void    swap_selector(t_stack *stack_a, t_stack *stack_b, char *pick)
{
	if (pick[0] == 's' && pick[1] == 'a')
	{
		swap(stack_a);
		write(1, "sa\n", 3);
	}
	else if (pick[0] == 's' && pick[1] == 'b')
	{
		swap(stack_b);
		write(1, "sb\n", 3);
	}
	else if (pick[0] == 's' && pick[1] == 's')
	{
		swap(stack_a);
		swap(stack_b);
		write(1, "ss\n", 3);
	}
	else
		error_exit();
}