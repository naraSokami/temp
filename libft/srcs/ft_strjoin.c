/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baderwae <baderwae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 10:41:00 by baderwae          #+#    #+#             */
/*   Updated: 2025/08/05 10:41:00 by baderwae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_protected_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	i;
	size_t	j;

	i = ft_protected_strlen(s1);
	j = ft_protected_strlen(s2);
	joined = malloc(sizeof(char) * (i + j + 1));
	if (!joined)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		joined[i + j] = s2[j];
		j++;
	}
	joined[i + j] = 0;
	return (joined);
}
