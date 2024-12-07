/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:36:00 by auskola-          #+#    #+#             */
/*   Updated: 2023/07/14 07:05:27 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include	<fcntl.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	<string.h>
# include	<stdio.h>
# include	<stdarg.h>
# include   <limits.h>

int		ft_printf(const char *str, ...);
int		ft_int_to_hex(unsigned int p_value, int uppercase);
int		ft_pointer_to_hex(unsigned long long p_value);
int		ft_print_pointer(void *p);
int		ft_print_number(int number);
int		ft_print_unsigned(int u_number);
int		ft_print_char(char c);
int		ft_print_string(char *s);
int		ft_print_reverse(char *str);
size_t	ft_strlen(char	*text);
char	*ft_strdup(char *str);
size_t	ft_strpos( char *s, int c);
char	*ft_substr(char *old_string, unsigned int start, size_t len);
int		ft_strpos2(char *s, int start, char c);
int		ft_print_clear_string(char *temp);
#endif