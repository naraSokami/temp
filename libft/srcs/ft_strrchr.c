/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baderwae <baderwae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 09:45:52 by baderwae          #+#    #+#             */
/*   Updated: 2025/10/20 17:14:55 by baderwae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	cc;

	cc = (unsigned char)c;
	i = 0;
	while (s[i])
		i++;
	if (cc == 0)
		return ((char *)s + i);
	while (i > 0)
	{
		if ((unsigned char)s[i - 1] == cc)
			return ((char *)(s + i - 1));
		i--;
	}
	return (NULL);
}
