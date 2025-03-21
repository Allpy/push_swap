#include "../includes/push_swap.h"
#include <stdio.h>

void error_exit(void)
{
    printf("Error\n");
    exit(1);
}

int main(int argc, char **argv)
{
    t_sets  sets;
    t_node  *start;

    ft_memset(&sets, 0, sizeof(t_sets));
    arg_checker(argv, argc, &sets.stack_a);
    print_stack(&sets.stack_a);
    free_stack(&sets.stack_a);
    return (0);
}