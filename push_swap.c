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

int	main(int argc, char **argv)
{
	int	check_arg;

	check_arg = arg_checker(argv);
	if (check_arg == -1 || argc < 3)
	{
		ft_printf("Invalid argument value! \n");
		return (0);
	}
}
