/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_options.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:19:34 by auskola-          #+#    #+#             */
/*   Updated: 2023/07/14 07:19:35 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_int_to_hex(unsigned int p_value, int uppercase)
{
	char	*hex;
	int		counter;
	char	hex_char[20];

	if (uppercase == 1)
		hex = ft_strdup("0123456789ABCDEF");
	else
		hex = ft_strdup("0123456789abcdef");
	counter = 0;
	while (p_value >= 16)
	{
		hex_char[counter] = hex[p_value % 16];
		p_value = p_value / 16;
		counter++;
	}
	hex_char[counter] = hex[p_value % 16];
	hex_char[counter + 1] = '\0';
	free(hex);
	return (ft_print_reverse(hex_char));
}

int	ft_pointer_to_hex(unsigned long long p_value)
{
	char	*hex;
	int		counter;
	char	hex_char[20];

	hex = ft_strdup("0123456789abcdef");
	counter = 0;
	while (p_value >= 16)
	{
		hex_char[counter] = hex[p_value % 16];
		p_value = p_value / 16;
		counter++;
	}
	hex_char[counter] = hex[p_value % 16];
	hex_char[counter + 1] = '\0';
	free (hex);
	return (ft_print_reverse(hex_char));
}

int	ft_print_pointer(void *p)
{
	unsigned long long	p_value;
	int					prints;

	p_value = (unsigned long long)p;
	prints = ft_print_string("0x");
	prints += ft_pointer_to_hex(p_value);
	return (prints);
}

int	ft_print_number(int int_number)
{
	char	num_to_str[20];
	int		counter;
	int		prints;
	long	number;

	number = int_number;
	counter = 0;
	prints = 0;
	if (number < 0)
	{
		ft_print_char('-');
		prints = 1;
		number = number * -1;
	}
	while (number >= 10)
	{
		num_to_str[counter] = number % 10 + '0';
		number = number / 10;
		counter++;
	}
	num_to_str[counter] = number + '0';
	num_to_str[counter + 1] = '\0';
	prints += ft_print_reverse(num_to_str);
	return (prints);
}

int	ft_print_unsigned(int u_number)
{
	unsigned int	number;
	char			num_to_str[20];
	int				counter;

	number = (unsigned int) u_number;
	counter = 0;
	while (number >= 10)
	{
		num_to_str[counter] = number % 10 + '0';
		number = number / 10;
		counter++;
	}
	num_to_str[counter] = number + '0';
	num_to_str[counter + 1] = '\0';
	return (ft_print_reverse(num_to_str));
}
