/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:22:47 by alermi            #+#    #+#             */
/*   Updated: 2024/11/28 20:44:59 by alermi           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

static	int	ft_handle_format(va_list args, char c)
{
	if (c == 'c')
		return (w_chr(va_arg(args, int)));
	else if (c == 's')
		return (w_str(va_arg(args, char *)));
	else if (c == 'i' || c == 'd')
		return (w_int(va_arg(args, int)));
	else if (c == 'p')
		return (w_pointer(va_arg(args, void *), "0123456789abcdef"));
	else if (c == 'x')
		return (w_hex(va_arg(args, unsigned int), c, "0123456789abcdef"));
	else if (c == 'X')
		return (w_hex(va_arg(args, unsigned int), c, "0123456789ABCDEF"));
	else if (c == 'u')
		return (w_unsigned_int(va_arg(args, unsigned int)));
	else if (c == '%')
	{
		write (1, "%", 1);
		return (1);
	}
	else
		return (-1);
}

static	int	ft_formatselector(va_list args, const char *format)
{
	int	temp;
	int	len;
	int	i;

	i = -1;
	len = 0;
	while (format[++i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
			temp = ft_handle_format(args, format[++i]);
			if (temp == -1)
				return (-1);
			len += temp;
		}
		else
		{
			if (w_chr(format[i]) == -1)
				return (-1);
			len++;
		}
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, format);
	len = ft_formatselector(args, format);
	if (len == -1)
	{
		va_end(args);
		return (-1);
	}
	return (len);
}
