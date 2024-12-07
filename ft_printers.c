/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:13:16 by auskola-          #+#    #+#             */
/*   Updated: 2023/07/14 08:11:28 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_string(char *s)
{
	int	lenght;

	if (s == NULL)
		return (write(1, "(null)", 6));
	lenght = ft_strlen(s);
	return (write(1, s, lenght));
}

int	ft_print_reverse(char *str)
{
	int	len;

	len = ft_strlen(str);
	while (len > 0)
	{
		ft_print_char(str[len - 1]);
		len--;
	}
	return (ft_strlen(str));
}
