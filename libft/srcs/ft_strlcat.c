/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baderwae <baderwae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 09:20:54 by baderwae          #+#    #+#             */
/*   Updated: 2025/08/04 09:20:54 by baderwae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	dst_size;
	size_t	src_size;
	size_t	i;

	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (size < dst_size + 1)
		return (src_size + size);
	i = 0;
	while (src[i] && i + dst_size + 1 < size)
	{
		dst[dst_size + i] = src[i];
		i++;
	}
	dst[dst_size + i] = 0;
	return (src_size + dst_size);
}
