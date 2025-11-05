/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baderwae <baderwae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:01:26 by baderwae          #+#    #+#             */
/*   Updated: 2025/08/05 15:01:26 by baderwae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				tmp;
	unsigned int	size;

	tmp = n;
	size = 1;
	while (tmp < -9 || tmp > 9)
	{
		tmp /= 10;
		size++;
	}
	str = malloc(sizeof(char) * (size + (n < 0) + 1));
	if (!str)
		return (NULL);
	str[size + (n < 0)] = 0;
	tmp = n;
	while (size > 0)
	{
		str[size - 1 + (n < 0)] = ft_abs(tmp % 10) + '0';
		tmp /= 10;
		size--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
