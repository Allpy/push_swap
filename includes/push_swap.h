/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:46:39 by alermi            #+#    #+#             */
/*   Updated: 2025/01/12 15:11:52 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				data;
	int				index;
	struct	s_node	*next;
	struct	s_node	*prev;
} t_node;



typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;



typedef struct s_sets
{
	t_stack	stack_a;
	t_stack	stack_b;
}	t_sets;


//##############=[Checker Funtions]=#################//

void	arg_checker(char **argv, int argc, t_sets *sets);
void	multiple_arg_checker(char **str, int argc, t_sets *sets);
void	single_arg_checker(char *numbers, t_sets *sets);
void	check_unique(t_sets *sets);

//###############=[Error and Close]=################//

void	free_stack(t_stack *stack);
void	free_imp(char *str);
void	matris_free(char **str);
void	error_exit(t_stack *stack_a, t_stack *stack_b, int section);

//###############=[Stack Manipulation]=################//

void    index_reset(t_sets *sets);
void	remove_node(t_stack *stack, t_node *node);
void	add_to_stack(t_stack *stack, int value);
void	print_stack(t_stack *stack_a, t_stack	*stack_b);

//###############=[Action Pattern]=################//
void    swap_selector(t_sets *sets, char *pick);
void	swap(t_stack *stack);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_b, t_stack *stack_a);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);

//###############=[Sorting Pattern]=################//

int 	is_sorted(t_stack *stack);
void	radix_sorting(t_sets *sets);
void	assign_indexes(t_sets *sets);

//###############=[Sorting Pattern]=################//

void selection_sort(t_sets *sets);
void move_to_b(t_sets *sets, int i);

#endif
