/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manipulations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 12:44:49 by alermi            #+#    #+#             */
/*   Updated: 2025/03/22 12:45:05 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	add_to_stack(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		error_exit();
	new_node->data = value;
	new_node->next = NULL;
	new_node->prev = stack->bottom;
	if (stack->bottom)
		stack->bottom->next = new_node;
	else
		stack->top = new_node;
	stack->bottom = new_node;
	stack->size++;
}

void	remove_node(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	if (node->prev)
		node->prev->next = node->next;
	else
		stack->top = node->next;
	if (node->next)
		node->next->prev = node->prev;
	else
		stack->bottom = node->prev;
	free(node);
	stack->size--;
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next_node;

	current = stack->top;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	stack->bottom = NULL;
	stack->top = NULL;
	stack->size = 0;
}

void	print_stack(t_stack *stack_a, t_stack	*stack_b)
{
	t_node	*current_one;
	t_node	*current_two;

	current_one = stack_a->top;
	current_two	= stack_b->top;
	printf("\n|a|\n");
	while (current_one)
	{
		printf("|%d|\n", current_one->data);
		current_one = current_one->next;
	}
	printf("\n||||||||||||||||||||||||||||||||\n");
	printf("\n|b|\n");
	while (current_two)
	{
		printf("|%d|\n", current_two->data);
		current_two = current_two->next;
	}
}
