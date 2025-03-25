/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_project.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 23:21:11 by alermi            #+#    #+#             */
/*   Updated: 2025/03/25 23:21:13 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdlib.h>

void	free_imp(char *str)
{
	if (str)
		free(str);
	str = NULL;
}

void	matris_free(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free_imp(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
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

void	error_exit(t_stack *stack_a, t_stack *stack_b, int section)
{
	if ((stack_a) && stack_a->top)
		free_stack(stack_a);
	if ((stack_b) && stack_b->top)
		free_stack(stack_b);
	if (section == 0)
		exit (0);
	write(1, "Error\n", 6);
	exit(1);
}
