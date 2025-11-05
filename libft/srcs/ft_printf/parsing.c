/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baderwae <baderwae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 14:10:49 by baderwae          #+#    #+#             */
/*   Updated: 2025/11/05 07:54:39 by baderwae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_c_in_str(char c, char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_get_flags(const char **str)
{
	char			*flags;
	unsigned int	i;

	i = 0;
	while ((*str)[i] && ft_c_in_str((*str)[i], "#0- +"))
		i++;
	if (i == 0)
		return (NULL);
	flags = ft_substr(*str, 0, i);
	*str += i;
	return (flags);
}

int	ft_get_number(const char **str)
{
	int	n;

	if (!str || !(*str) || **str < '0' || **str > '9')
		return (0);
	n = 0;
	while (**str >= '0' && **str <= '9')
	{
		n = n * 10 + **str - '0';
		(*str)++;
	}
	return (n);
}
