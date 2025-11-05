/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baderwae <baderwae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 14:13:31 by baderwae          #+#    #+#             */
/*   Updated: 2025/11/04 15:58:22 by baderwae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_wildcard(t_wildcard *wild)
{
	wild->flags = NULL;
	wild->type = -1;
	wild->width = -1;
	wild->precision = -1;
	wild->is_null_char = 0;
}

void	ft_free_wildcard(t_wildcard *wild)
{
	if (!wild)
		return ;
	if (wild->flags)
		free(wild->flags);
	free(wild);
}

t_wildcard	*ft_get_next_wildcard(const char **str)
{
	t_wildcard	*wild;

	if (!str || !(*str) || **str != '%')
		return (NULL);
	wild = malloc(sizeof(t_wildcard));
	if (!wild)
		return (NULL);
	ft_init_wildcard(wild);
	(*str)++;
	wild->flags = ft_get_flags(str);
	wild->width = ft_get_number(str);
	if (**str == '.')
	{
		(*str)++;
		wild->precision = ft_get_number(str);
	}
	wild->type = **str;
	(*str)++;
	if (!ft_c_in_str(wild->type, "cspdiuxX%"))
		return (ft_free_wildcard(wild), NULL);
	return (wild);
}

char	*ft_exec_wildcard(va_list *args, t_wildcard *wild)
{
	char	*print_value;

	if (wild->type == '%')
		print_value = ft_strdup("%");
	else if (wild->type == 'd' || wild->type == 'i')
		print_value = ft_get_int(va_arg(*args, int), wild);
	else if (wild->type == 'x' || wild->type == 'X' || wild->type == 'u')
		print_value = ft_get_uint(va_arg(*args, unsigned int), wild);
	else if (wild->type == 'c')
		print_value = ft_get_uchar(va_arg(*args, int), wild);
	else if (wild->type == 's')
		print_value = ft_get_str(va_arg(*args, char *), wild);
	else if (wild->type == 'p')
		print_value = ft_get_addr(va_arg(*args, void *));
	return (NULL);
}
