/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_hex_a_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:40:46 by alermi            #+#    #+#             */
/*   Updated: 2024/11/29 17:40:48 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <unistd.h>

int	w_hex(unsigned int number, char c, char	*base)
{
	int	len;
	int	result;

	len = 0;
	if (number >= 16)
	{
		result = w_hex((number / 16), c, base);
		if (result == -1)
			return (-1);
		len += result;
	}
	if (c == 'x')
	{
		if (write(1, &(base[number % 16]), 1) == -1)
			return (-1);
	}
	if (c == 'X')
	{
		if (write(1, &(base[number % 16]), 1) == -1)
			return (-1);
	}
	len++;
	return (len);
}

static int	w_convertor(unsigned long int number, char *base)
{
	int	len;
	int	result;

	len = 0;
	if (number >= 16)
	{
		result = w_convertor((number / 16), base);
		if (result == -1)
			return (-1);
		len += result;
	}
	if (write(1, &(base[number % 16]), 1) == -1)
		return (-1);
	len++;
	return (len);
}

int	w_pointer(void *adress, char *base)
{
	if (!adress)
	{
		write(1, "(nil)", 5);
		return (5);
	}	
	write(1, "0x", 2);
	return (w_convertor((unsigned long int)adress, base) + 2);
}
