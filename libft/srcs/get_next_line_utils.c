/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baderwae <baderwae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 22:18:29 by baderwae          #+#    #+#             */
/*   Updated: 2025/10/28 12:44:29 by baderwae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_end(char *str)
{
	int	size;

	if (!str)
		return (0);
	size = 0;
	while (str[size] && str[size] != '\n')
		size++;
	if (str[size] == '\n')
		size++;
	return (size);
}

char	*ft_strndup(char *str, int n)
{
	char	*new;
	int		i;

	if (!str)
		return (NULL);
	new = malloc(sizeof(char) * (n + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (i < n)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = 0;
	return (new);
}
