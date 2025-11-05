/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baderwae <baderwae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:14:38 by baderwae          #+#    #+#             */
/*   Updated: 2025/08/05 16:14:38 by baderwae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	size;
	size_t	i;

	if (!s || !f || !(*f))
		return (NULL);
	size = ft_strlen(s);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < size)
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}
