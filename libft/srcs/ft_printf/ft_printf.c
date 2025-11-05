/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baderwae <baderwae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:10:27 by baderwae          #+#    #+#             */
/*   Updated: 2025/11/04 17:31:08 by baderwae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_print_text(const char **str)
{
	unsigned int	printed_count;

	printed_count = 0;
	while (**str)
	{
		if (**str == '%')
			return (printed_count);
		write(1, *str, 1);
		(*str)++;
		printed_count++;
	}
	return (printed_count);
}

int	ft_get_null_char_size(char *print_value)
{
	int	size;
	int	null_passed;

	size = 0;
	null_passed = 0;
	while (null_passed == 0)
	{
		if (!print_value[size])
			null_passed = 1;
		size++;
	}
	while (print_value[size])
		size++;
	return (size);
}

int	ft_print(char *print_value, t_wildcard *wild)
{
	int	size;

	if (!print_value)
		return (0);
	if (wild->is_null_char)
		size = ft_get_null_char_size(print_value);
	else
		size = ft_strlen(print_value);
	return (write(1, print_value, size));
}

int	ft_printf(const char *str, ...)
{
	va_list			args;
	unsigned int	printed_count;
	t_wildcard		*wild;
	char			*print_value;

	va_start(args, str);
	printed_count = 0;
	while (str)
	{
		printed_count += ft_print_text(&str);
		wild = ft_get_next_wildcard(&str);
		if (!wild)
			return (va_end(args), printed_count);
		print_value = ft_exec_wildcard(&args, wild);
		if (!print_value)
			return (va_end(args), ft_free_wildcard(wild), printed_count);
		print_value = ft_add_padding(print_value, wild);
		printed_count += ft_print(print_value, wild);
		free(print_value);
		if (wild->flags)
			free(wild->flags);
		free(wild);
	}
	va_end(args);
	return (printed_count);
}
