/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:13:45 by auskola-          #+#    #+#             */
/*   Updated: 2023/07/14 08:12:52 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(char	*text)
{
	size_t	i;

	i = 0;
	if (!text)
		return (0);
	while (text[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*puntero;
	size_t	counter;
	size_t	len;

	counter = 0;
	len = ft_strlen(str);
	puntero = (char *)malloc(sizeof(char) * (len) + 1);
	if (puntero == NULL)
		return (NULL);
	while (counter < len)
	{
		puntero[counter] = str[counter];
		counter++;
	}
	puntero[counter] = '\0';
	return (puntero);
}

size_t	ft_strpos( char *s, int c)
{
	size_t	counter;

	counter = 0;
	while (s && s[counter] != '\0')
	{
		if (s[counter] == (unsigned char)c)
		{
			return (counter + 1);
		}
		counter++;
	}
	if (s[counter] == (unsigned char)c)
		return (counter + 1);
	return (0);
}

char	*ft_substr(char *old_string, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	counter;

	if (!old_string)
		return ("");
	else if (ft_strlen(old_string) < start)
		return ("");
	if (len > (ft_strlen(old_string) - start))
		sub_str = (char *)malloc(sizeof(char) * \
			(ft_strlen(old_string) - start) + 1);
	else
		sub_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub_str || (ft_strlen(old_string) < start) || (len == 0))
	{
		free(sub_str);
		return (ft_strdup(""));
	}
	counter = 0;
	while ((counter < len) && (counter < ft_strlen(old_string) - start))
	{
		sub_str[counter] = old_string[start + counter];
		counter++;
	}
	sub_str[counter] = '\0';
	return (sub_str);
}

int	(ft_strpos2(char *s, int start, char c))
{
	size_t	counter;

	counter = start;
	while (s && s[counter] != '\0')
	{
		if (s[counter] == (unsigned char)c)
		{
			return (counter + 1);
		}
		counter++;
	}
	if (s[counter] == (unsigned char)c)
		return (counter + 1);
	return (0);
}
