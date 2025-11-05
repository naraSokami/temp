/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baderwae <baderwae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:09:33 by baderwae          #+#    #+#             */
/*   Updated: 2025/10/23 10:09:00 by baderwae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	ft_get_sign(unsigned int *i, const char *nptr)
{
	int	sign;

	sign = 1;
	if (nptr[*i] == '+' || nptr[*i] == '-')
	{
		if (nptr[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

int	ft_atoi(const char *nptr)
{
	int				n;
	int				sign;
	unsigned int	i;

	i = 0;
	while (nptr[i] && is_space(nptr[i]))
		i++;
	sign = ft_get_sign(&i, nptr);
	n = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (-n == INT_MIN / 10 && nptr[i] - '0' == INT_MIN % 10 * -1
			&& sign == -1)
			return (INT_MIN);
		n = n * 10 + nptr[i] - '0';
		i++;
	}
	return (n * sign);
}
