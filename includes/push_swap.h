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

# include <stdlib.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"
# include "./libft/libft.h"

typedef struct s_stack_one {
	int					a;
	struct s_stack_one	*node;
}	t_stack_one;

int	arg_checker(char **argv);

#endif
