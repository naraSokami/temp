/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baderwae <baderwae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 10:44:09 by baderwae          #+#    #+#             */
/*   Updated: 2025/08/15 10:44:09 by baderwae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_value(t_list	*list)
{
	return (*(int *)(list->content));
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_get_lesser_size(int value, t_stack *stack, int size)
{
	t_list	*elem;
	int		lesser_size;
	int		i;

	elem = stack->list;
	lesser_size = 0;
	i = 0;
	while (i < size && elem)
	{
		i++;
		if (stack->name == 'a' && ft_value(elem) < value)
			lesser_size = i;
		if (stack->name == 'b' && ft_value(elem) > value)
			lesser_size = i;
		elem = elem->next;
	}
	return (lesser_size);
}

int	ft_is_sorted(t_list	*list, int size)
{
	int	i;

	if (!list || !list->next)
		return (1);
	i = 1;
	while (list->next && i < size)
	{
		if (ft_value(list) != ft_value(list->next) - 1)
			return (0);
		list = list->next;
		i++;
	}
	return (1);
}

int	ft_is_reverse_sorted(t_list	*list, int size)
{
	int	i;

	if (!list || !list->next)
		return (1);
	i = 1;
	while (list->next && i < size)
	{
		if (ft_value(list) != ft_value(list->next) + 1)
			return (0);
		list = list->next;
		i++;
	}
	return (1);
}
