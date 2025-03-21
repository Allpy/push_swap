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

void	error_exit(void)
{
	printf("Error\n");
	exit(1);
}

int	main(int argc, char **argv)
{
	t_sets	sets;
	t_node	*start;

    printf("////////////////////////////////////////////////////////////////////////////\n");
	ft_memset(&sets, 0, sizeof(t_sets));
	arg_checker(argv, argc, &sets.stack_a);
    printf("////////////////stacka :\n");
	print_stack(&sets.stack_a);
    printf("////////////////stackb :\n");
	print_stack(&sets.stack_b);
	pb(&sets.stack_b, &sets.stack_a);
	pb(&sets.stack_b, &sets.stack_a);
	pb(&sets.stack_b, &sets.stack_a);
    rb(&sets.stack_b);
    printf("////////////////stacka :\n");
	print_stack(&sets.stack_a);
    printf("////////////////stackb :\n");
	print_stack(&sets.stack_b); 
	free_stack(&sets.stack_a);
	free_stack(&sets.stack_b);
    printf("////////////////////////////////////////////////////////////////////////////\n");
	return (0);
}
