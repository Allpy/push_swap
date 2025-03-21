#include "../includes/push_swap.h"
#include <stdio.h>

void add_to_stack(t_stack *stack, int value)
{
    t_node *new_node;

    new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node)
        error_exit();
    new_node->data = value;
    new_node->next = NULL;
    new_node->prev = stack->top;
    if (stack->top)
        stack->top->next = new_node;
    else
        stack->bottom = new_node;
    stack->top = new_node;
    stack->size++;
}

void remove_node(t_stack *stack, t_node *node)
{
    if (!stack || !node)
        return;

    if (node->prev)
        node->prev->next = node->next;
    else
        stack->bottom = node->next;

    if (node->next)
        node->next->prev = node->prev;
    else
        stack->top = node->prev;

    free(node);
    stack->size--;
}

void free_stack(t_stack *stack)
{
    t_node *current = stack->bottom;
    t_node *next_node;

    while (current)
    {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    stack->top = NULL;
    stack->bottom = NULL;
    stack->size = 0;
}

void print_stack(t_stack *stack)
{
    t_node *current = stack->bottom;
    
    while (current)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
}