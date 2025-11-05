/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baderwae <baderwae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:41:31 by baderwae          #+#    #+#             */
/*   Updated: 2025/10/22 16:35:47 by baderwae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **strs)
{
	unsigned int	i;

	i = 0;
	while (strs && strs[i])
	{
		free(strs[i]);
		i++;
	}
	if (strs)
		free(strs);
}

static unsigned int	ft_word_count(char const *s, char c)
{
	unsigned int	wc;
	unsigned int	i;

	wc = 0;
	i = 0;
	while (s && s[i])
	{
		if ((i == 0 && s[i] != c) || (i > 0 && s[i] != c && s[i - 1] == c))
			wc++;
		i++;
	}
	return (wc);
}

static char	*ft_get_word(char const **s, char c)
{
	char			*word;
	unsigned int	size;
	unsigned int	i;

	while (**s && **s == c)
		(*s)++;
	size = 0;
	while ((*s)[size] && (*s)[size] != c)
	{
		size++;
	}
	word = malloc(sizeof(char) * (size + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < size)
	{
		word[i] = (*s)[i];
		i++;
	}
	word[i] = 0;
	(*s) += i;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char			**strs;
	unsigned int	wc;
	unsigned int	i;

	if (!s)
		return (NULL);
	wc = ft_word_count(s, c);
	strs = malloc(sizeof(char *) * (wc + 1));
	if (!strs)
		return (NULL);
	i = 0;
	while (i < wc)
	{
		strs[i] = ft_get_word(&s, c);
		if (!strs[i])
		{
			ft_free(strs);
			return (NULL);
		}
		i++;
	}
	strs[i] = NULL;
	return (strs);
}
