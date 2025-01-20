/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_int.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:45:57 by alermi            #+#    #+#             */
/*   Updated: 2024/11/29 15:45:58 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	w_int(int number)
{
	int		len;
	int		tmp;
	char	c;

	len = 0;
	if (number == -2147483648)
		return (write(1, "-2147483648", 11));
	if (number < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		number = -number;
		len++;
	}
	if (number >= 10)
	{
		tmp = w_int(number / 10);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	c = ((number % 10) + '0');
	if (write (1, &c, 1) == -1)
		return (-1);
	return (len + 1);
}
