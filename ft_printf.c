/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:43:49 by auskola-          #+#    #+#             */
/*   Updated: 2023/07/14 08:12:44 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_clear_string(char *temp)
{
	int	prints;

	prints = ft_print_string(temp);
	free(temp);
	return (prints);
}

int	ft_parse_args(va_list args, char option)
{
	if (option == 'c')
		return (ft_print_char(va_arg(args, int)));
	if (option == '%')
		return (ft_print_char('%'));
	if (option == 's')
		return (ft_print_string(va_arg(args, char *)));
	if (option == 'p')
		return (ft_print_pointer(va_arg(args, void *)));
	if (option == 'd' || option == 'i')
		return (ft_print_number(va_arg(args, int)));
	if (option == 'u')
		return (ft_print_unsigned(va_arg(args, int)));
	if (option == 'x')
		return (ft_int_to_hex(va_arg(args, int), 0));
	if (option == 'X')
		return (ft_int_to_hex(va_arg(args, int), 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	char	*s;
	size_t	pos;
	size_t	pos2;
	int		printed;

	va_start(args, str);
	s = (char *)str;
	pos = 0;
	printed = 0;
	pos2 = ft_strpos2(s, pos, '%');
	while (pos2 > 0)
	{
		printed += ft_print_clear_string(ft_substr(s, pos, pos2 - pos - 1));
		printed += ft_parse_args(args, s[pos2]);
		pos = pos2 + 1;
		pos2 = ft_strpos2(s, pos, '%');
	}
	if (pos < ft_strlen(s))
		printed += ft_print_clear_string(ft_substr(s, pos, pos2 - pos - 1));
	va_end(args);
	return (printed);
}
