/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baderwae <baderwae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 19:41:25 by baderwae          #+#    #+#             */
/*   Updated: 2025/08/14 19:41:25 by baderwae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_is_valid_int(char *str)
{
	int	sign;
	int	i;

	i = 0;
	if (!str)
		return (0);
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (i > 10
		|| (i == 10 && sign == 1 && ft_strncmp(str, "2147483647", 10) > 0)
		|| (i == 10 && sign == -1 && ft_strncmp(str, "2147483648", 10) > 0))
		return (0);
	return (1);
}

int	ft_in_tab(int n, int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (tab[i] == n)
			return (1);
		i++;
	}
	return (0);
}

int	*ft_strs_to_tab(int size, char **strs)
{
	int	*tab;
	int	i;

	i = 0;
	while (i < size)
	{
		if (!ft_is_valid_int(strs[i]))
			return (NULL);
		i++;
	}
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < size)
	{
		tab[i] = ft_atoi(strs[i]);
		if (ft_in_tab(tab[i], tab, i))
			return (free(tab), NULL);
		i++;
	}
	return (tab);
}

t_list	*ft_tab_to_list(int *tab, int size)
{
	t_list	*list;
	t_list	*elem;

	list = NULL;
	while (size > 0)
	{
		elem = ft_lstnew((void *)&tab[size - 1]);
		if (!elem)
			return (ft_lstclear(&list, NULL), NULL);
		ft_lstadd_front(&list, elem);
		size--;
	}
	return (list);
}

int	*ft_get_normalized_tab(int *tab, int size)
{
	int	*normalized;
	int	bigger_count;
	int	i;
	int	j;

	normalized = malloc(sizeof(int) * size);
	if (!normalized)
		return (NULL);
	i = 0;
	while (i < size)
	{
		bigger_count = 0;
		j = 0;
		while (j < size)
		{
			if (tab[i] > tab[j])
				bigger_count++;
			j++;
		}
		normalized[i] = bigger_count;
		i++;
	}
	free(tab);
	return (normalized);
}
