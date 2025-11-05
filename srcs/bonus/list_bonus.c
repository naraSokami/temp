/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baderwae <baderwae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 06:41:27 by baderwae          #+#    #+#             */
/*   Updated: 2025/08/15 06:41:27 by baderwae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_value(t_list	*list)
{
	return (*(int *)(list->content));
}

int	ft_is_sorted(t_list	*list, int size)
{
	int	i;

	if (!list || !list->next)
		return (1);
	i = 1;
	while (list->next && i < size)
	{
		if (ft_value(list) > ft_value(list->next))
			return (0);
		list = list->next;
		i++;
	}
	return (1);
}

t_list	*ft_lstpop_front(t_list **list)
{
	t_list	*popped;

	if (!list || !(*list))
		return (NULL);
	popped = *list;
	*list = (*list)->next;
	popped->next = NULL;
	return (popped);
}

t_list	*ft_lstpop_back(t_list **list)
{
	t_list	*popped;
	t_list	*prev;

	if (!list || !(*list))
		return (NULL);
	popped = *list;
	prev = NULL;
	while (popped->next)
	{
		prev = popped;
		popped = popped->next;
	}
	if (prev)
		prev->next = NULL;
	else
		*list = NULL;
	popped->next = NULL;
	return (popped);
}

int	ft_c_in_str(char c, char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
