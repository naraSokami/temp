/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baderwae <baderwae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 10:23:29 by baderwae          #+#    #+#             */
/*   Updated: 2025/08/02 10:23:29 by baderwae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char unsigned	*ddest;
	char unsigned	*ssrc;
	unsigned int	i;

	ddest = (unsigned char *)dest;
	ssrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		ddest[i] = ssrc[i];
		i++;
	}
	return (dest);
}
