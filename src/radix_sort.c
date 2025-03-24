#include "../includes/push_swap.h"

void radix_sort(t_sets *sets)
{
    int max_bits = 0;
    int max_index = sets->stack_a.size - 1;
    int bit = 0;

    while ((max_index >> max_bits) != 0)
        max_bits++;

    while (bit < max_bits)
    {
        int i = 0;
        int size = sets->stack_a.size;

        while (i < size)
        {
            if (((sets->stack_a.top->index >> bit) & 1) == 0)
                pb(&sets->stack_b, &sets->stack_a);
            else
                ra(&sets->stack_a);
            i++;
        }
        while (sets->stack_b.size > 0)
            pa(&sets->stack_a, &sets->stack_b);

        bit++;
    }
}
