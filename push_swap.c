/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:46:03 by alermi            #+#    #+#             */
/*   Updated: 2025/01/10 16:46:33 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"
#include "./ft_printf/ft_printf.h"

int	arg_checker(char **argv)
{
	while (*argv)
	{
		while (**argv != '\0' && **argv >= '0' && **argv <= '9')
		{
			if (**argv >= '0' && **argv <= '9')
			{
			
			}
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	ft_printf("test");
}
