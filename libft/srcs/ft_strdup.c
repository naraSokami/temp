/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baderwae <baderwae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:59:15 by baderwae          #+#    #+#             */
/*   Updated: 2025/08/04 16:59:15 by baderwae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char			*copy;
	unsigned int	size;

	size = 0;
	while (s[size])
		size++;
	copy = malloc(sizeof(char) * (size + 1));
	if (!copy)
		return (NULL);
	copy[size] = 0;
	while (size > 0)
	{
		copy[size - 1] = s[size - 1];
		size--;
	}
	return (copy);
}
