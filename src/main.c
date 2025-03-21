#include "../includes/push_swap.h"
#include <stdio.h>

void error_exit(void)
{
    printf("Error\n");
    exit(1);
}

int main(int argc, char **argv)
{
    t_sets sets;
    sets.stack_a.top = NULL;
    sets.stack_a.bottom = NULL;
    sets.stack_a.size = 0;
    sets.stack_b.top = NULL;
    sets.stack_b.bottom = NULL;
    sets.stack_b.size = 0;

    arg_checker(argv, argc, &sets.stack_a);
    return (0);
}