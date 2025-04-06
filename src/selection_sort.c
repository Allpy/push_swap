/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 19:11:07 by alermi            #+#    #+#             */
/*   Updated: 2025/04/06 22:20:35 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	move_to_b(t_sets *sets, int i)
{
	int		j;
	t_node	*current;

	j = 0;
	current = sets->stack_a.top;
	while (current)
	{
		if (current->index == i)
			break ;
		current = current->next;
		j++;
	}
	if (current)
	{
		if (sets->stack_a.top && sets->stack_a.top->next &&
			sets->stack_a.top->next->index == i)
		{
			swap_selector(sets, "sa");
			pb(&sets->stack_b, &sets->stack_a);
			return ;
		}
		if (j <= sets->stack_a.size / 2)
			while (j--)
				ra(&sets->stack_a);
		else
		{
			j = sets->stack_a.size - j;
			while (j--)
				rra(&sets->stack_a);
		}
		pb(&sets->stack_b, &sets->stack_a);
	}
}


void	sort_three(t_sets *sets)
{
	int a = sets->stack_a.top->index;
	int b = sets->stack_a.top->next->index;
	int c = sets->stack_a.top->next->next->index;

	if (a > b && b < c && a < c)
		swap_selector(sets, "sa");
	else if (a > b && b > c)
	{
		swap_selector(sets, "sa");
		rra(&sets->stack_a);
	}
	else if (a > b && b < c && a > c)
		ra(&sets->stack_a);
	else if (a < b && b > c && a < c)
	{
		swap_selector(sets, "sa");
		ra(&sets->stack_a);
	}
	else if (a < b && b > c && a > c)
		rra(&sets->stack_a);
}

void	selection_sort(t_sets *sets)
{
	int	i;

	i = 1;
	while (sets->stack_a.size > 3)
	{
		if (is_sorted(&sets->stack_a))
			break ;
		move_to_b(sets, i);
		i++;
	}
	if (!is_sorted(&sets->stack_a))
		sort_three(sets);
	while (sets->stack_b.size > 0)
		pa(&sets->stack_a, &sets->stack_b);
}

