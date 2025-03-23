/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 12:48:57 by alermi            #+#    #+#             */
/*   Updated: 2025/03/22 12:48:58 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>




int	main(int argc, char **argv)
{
	t_sets	sets;
	t_node	*start;

    printf("////////////////////////////////////////////////////////////////////////////\n");
	ft_memset(&sets, 0, sizeof(t_sets));
	arg_checker(argv, argc, &sets);
	print_stack(&sets.stack_a, &sets.stack_b);
	free_stack(&sets.stack_a);
	free_stack(&sets.stack_b);
    printf("////////////////////////////////////////////////////////////////////////////\n");
	return (0);
}
