#include "../includes/push_swap.h"

int is_sorted(t_stack *stack)
{
    t_node *current;

    if (!stack || stack->size < 2)
        return 1;

    current = stack->top;
    while (current->next)
    {
        if (current->data > current->next->data)
            return 0;
        current = current->next;
    }
    return 1;
}