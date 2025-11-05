/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_modifiers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baderwae <baderwae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 13:56:33 by baderwae          #+#    #+#             */
/*   Updated: 2025/11/05 07:55:08 by baderwae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_add_prefix(char *str, char *prefix)
{
	char	*prefixed;

	prefixed = ft_strjoin((const char *)prefix, (const char *)str);
	if (str)
		free(str);
	return (prefixed);
}

void	ft_set_minus_for_prefix(char *str, char *prefixed, size_t *i)
{
	prefixed[0] = '-';
	str[0] = '0';
	(*i)++;
}

char	*ft_prefix_by_c(char *str, char c, size_t n, char type)
{
	char	*prefixed;
	size_t	size;
	size_t	i;

	size = ft_strlen(str) + n + (type == 'c' && str[0] == 0);
	prefixed = malloc(sizeof(char) * (size + 1));
	if (!prefixed)
		return (free(str), NULL);
	i = 0;
	if (str[0] == '-' && c == '0' && ft_c_in_str(type, "di"))
		ft_set_minus_for_prefix(str, prefixed, &i);
	while (i < n)
	{
		prefixed[i] = c;
		i++;
	}
	while (i < size)
	{
		prefixed[i] = str[i - n];
		i++;
	}
	prefixed[i] = 0;
	free(str);
	return (prefixed);
}

char	*ft_suffix_by_c(char *str, char c, size_t n, char type)
{
	char	*suffixed;
	size_t	size;
	size_t	i;

	size = ft_strlen(str) + (type == 'c' && str[0] == 0);
	suffixed = malloc(sizeof(char) * (size + n + 1));
	if (!suffixed)
		return (free(str), NULL);
	i = 0;
	while (i < size)
	{
		suffixed[i] = str[i];
		i++;
	}
	while (i < size + n)
	{
		suffixed[i] = c;
		i++;
	}
	suffixed[i] = 0;
	free(str);
	return (suffixed);
}

char	*ft_add_padding(char *print_value, t_wildcard *wild)
{
	size_t	size;

	size = ft_strlen(print_value);
	if (wild->type == 'c' && print_value[0] == 0)
		size++;
	if (wild->width <= (int)size || wild->type == '%')
		return (print_value);
	if (wild->flags && ft_c_in_str('-', wild->flags))
		print_value = ft_suffix_by_c(
				print_value, ' ', wild->width - (int)size, wild->type);
	else if (wild->flags && ft_c_in_str('0', wild->flags)
		&& ft_c_in_str(wild->type, "diuxX") && wild->precision == -1)
		print_value = ft_prefix_by_c(print_value, '0',
				wild->width - (int)size, wild->type);
	else
		print_value = ft_prefix_by_c(print_value, ' ',
				wild->width - (int)size, wild->type);
	return (print_value);
}
