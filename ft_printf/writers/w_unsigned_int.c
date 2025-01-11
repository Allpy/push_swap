/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_unsigned_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 22:49:38 by alermi            #+#    #+#             */
/*   Updated: 2024/11/30 22:49:40 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <unistd.h>

int	w_unsigned_int(unsigned int number)
{
	int		len;
	int		tmp;
	char	c;

	len = 0;
	if (number >= 10)
	{
		tmp = w_unsigned_int(number / 10);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	c = ((number % 10) + '0');
	if (write (1, &c, 1) == -1)
		return (-1);
	return (len + 1);
}
