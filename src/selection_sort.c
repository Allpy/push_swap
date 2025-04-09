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

void	move_and_push(t_sets *sets, int j)
{
	int		rev;

	if (j <= sets->stack_a.size / 2)
		while (j-- > 0)
			ra(&sets->stack_a);
	else
	{
		rev = sets->stack_a.size - j;
		while (rev-- > 0)
			rra(&sets->stack_a);
	}
	pb(&sets->stack_b, &sets->stack_a);
}

void	move_to_b(t_sets *sets, int i)
{
	int		j;
	t_node	*cur;

	j = 0;
	cur = sets->stack_a.top;
	while (cur && cur->index != i)
	{
		cur = cur->next;
		j++;
	}
	if (!cur)
		return ;
	if (sets->stack_a.top && sets->stack_a.top->next
		&& sets->stack_a.top->next->index == i)
	{
		swap_selector(sets, "sa");
		pb(&sets->stack_b, &sets->stack_a);
		return ;
	}
	move_and_push(sets, j);
}

void	sort_three(t_sets *sets, int a, int b, int c)
{
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
	if (!is_sorted(&sets->stack_a) && sets->stack_a.size == 3)
		sort_three(sets, sets->stack_a.top->index,
			sets->stack_a.top->next->index,
			sets->stack_a.top->next->next->index);
	else if (!is_sorted(&sets->stack_a) && sets->stack_a.size == 2)
		swap_selector(sets, "sa");
	while (sets->stack_b.size > 0)
		pa(&sets->stack_a, &sets->stack_b);
}
