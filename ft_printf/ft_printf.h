/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:46:49 by alermi            #+#    #+#             */
/*   Updated: 2024/11/28 20:48:19 by alermi           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	w_chr(char c);
int	w_str(char *str);
int	w_int(int number);
int	w_hex(unsigned int number, char c, char *base);
int	w_pointer(void *adress, char *base);
int	w_unsigned_int(unsigned int number);

#endif
