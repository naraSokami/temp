/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baderwae <baderwae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 13:53:38 by baderwae          #+#    #+#             */
/*   Updated: 2025/10/26 09:44:52 by baderwae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_int(int n, t_wildcard *wild)
{
	char	*print_value;

	if (wild->precision == 0 && n == 0)
		return (ft_strdup(""));
	print_value = ft_abs_itoa(n);
	if (!print_value)
		return (NULL);
	if (wild->precision != -1
		&& ft_strlen(print_value) < (size_t)wild->precision)
		print_value = ft_prefix_by_c(print_value, '0',
				(size_t)wild->precision - ft_strlen(print_value), wild->type);
	if (!print_value)
		return (NULL);
	if (n < 0)
		return (ft_add_prefix(print_value, "-"));
	if (!print_value || !wild->flags)
		return (print_value);
	if (ft_c_in_str('+', wild->flags))
		print_value = ft_add_prefix(print_value, "+");
	else if (ft_c_in_str(' ', wild->flags))
		print_value = ft_add_prefix(print_value, " ");
	return (print_value);
}

char	*ft_get_uint(unsigned int n, t_wildcard *wild)
{
	char	*print_value;

	if (wild->precision == 0 && n == 0)
		return (ft_strdup(""));
	print_value = NULL;
	if (wild->type == 'u')
		print_value = ft_uitoa_base(n, 10, "0123456789");
	else if (wild->type == 'x')
		print_value = ft_uitoa_base(n, 16, "0123456789abcdef");
	else if (wild->type == 'X')
		print_value = ft_uitoa_base(n, 16, "0123456789ABCDEF");
	if (print_value && wild->precision != -1
		&& ft_strlen(print_value) < (size_t)wild->precision)
		print_value = ft_prefix_by_c(print_value, '0',
				(size_t)wild->precision - ft_strlen(print_value), wild->type);
	if (print_value && wild->flags && n != 0
		&& ft_c_in_str('#', wild->flags) && wild->type == 'x')
		print_value = ft_add_prefix(print_value, "0x");
	if (print_value && wild->flags && n != 0
		&& ft_c_in_str('#', wild->flags) && wild->type == 'X')
		print_value = ft_add_prefix(print_value, "0X");
	return (print_value);
}

char	*ft_get_uchar(unsigned char c, t_wildcard *wild)
{
	char	*print_value;

	if (c == 0)
		wild->is_null_char = 1;
	print_value = malloc(sizeof(char) * 2);
	if (!print_value)
		return (NULL);
	print_value[0] = c;
	print_value[1] = 0;
	return (print_value);
}

char	*ft_get_str(char *str, t_wildcard *wild)
{
	char	*print_value;
	int		size;

	size = wild->precision;
	if (size == -1)
		size = INT_MAX;
	if (!str)
	{
		if (wild->precision > 5 || wild->precision == -1)
			print_value = ft_strdup("(null)");
		else
			print_value = ft_strdup("");
	}
	else if (size > 0 && str[0] == 0)
		print_value = ft_strdup("");
	else
		print_value = ft_substr(str, 0, size);
	return (print_value);
}

char	*ft_get_addr(void *addr)
{
	char	*print_value;

	if (!addr)
		print_value = ft_strdup("(nil)");
	else
	{
		print_value = ft_lluitoa_base(
				(long long unsigned int)addr, 16, "0123456789abcdef");
		if (print_value)
			print_value = ft_add_prefix(print_value, "0x");
	}
	return (print_value);
}
