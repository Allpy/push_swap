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

void	arg_checker(char **argv, int argc, t_stack *stack_a);
void	multiple_arg_checker(char **str, int argc, t_stack *stack_a);
void	single_arg_checker(char *numbers, t_stack *stack_a);
void	check_unique(t_node *head);

//###############=[Error and Close]=################//

void	free_stack(t_stack *stack);
void	free_imp(char *str);
void	matris_free(char **str);
void	error_exit(void);

//###############=[Stack Manipulation]=################//

void	remove_node(t_stack *stack, t_node *node);
void	add_to_stack(t_stack *stack, int value);
void	print_stack(t_stack *stack);

//###############=[Action Pattern]=################//
void	pa(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);

#endif
