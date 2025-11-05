/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baderwae <baderwae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:38:42 by baderwae          #+#    #+#             */
/*   Updated: 2025/10/22 16:37:17 by baderwae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	unsigned int	i;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > INT_MAX || size > INT_MAX || nmemb * size > INT_MAX)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}
