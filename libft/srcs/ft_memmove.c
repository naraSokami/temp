/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baderwae <baderwae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 10:29:24 by baderwae          #+#    #+#             */
/*   Updated: 2025/10/22 07:00:08 by baderwae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char unsigned	*ddest;
	char unsigned	*ssrc;
	unsigned int	i;

	ddest = (unsigned char *)dest;
	ssrc = (unsigned char *)src;
	if (ssrc < ddest)
	{
		while (n > 0)
		{
			ddest[n - 1] = ssrc[n - 1];
			n--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			ddest[i] = ssrc[i];
			i++;
		}
	}
	return (dest);
}
