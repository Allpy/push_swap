#include "../includes/push_swap.h"
#include <stdio.h>

void move_to_b(t_sets *sets, int i)
{
    int	j;
    t_node *current;

	j = 0;
	current = sets->stack_a.top;
    while (current)
    {
        if (current->index == i)
            break;
        current = current->next;
        j++;
    }
    if (current)
    {
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

void	selection_sort(t_sets *sets)
{
    int i;

	i = 1;
    while (sets->stack_a.size > 1)
    {
        move_to_b(sets, i);
        i++;
    }
	while (sets->stack_b.size > 0)
		pa(&sets->stack_a, &sets->stack_b);
}
