/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_find_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baderwae <baderwae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:38:26 by baderwae          #+#    #+#             */
/*   Updated: 2025/08/11 17:38:26 by baderwae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstfind(int value, t_list *list, int size)
{
	int	i;

	i = 0;
	while (i < size && list)
	{
		if (ft_value(list) == value)
			return (list);
		list = list->next;
		i++;
	}
	return (NULL);
}

t_list	*ft_lstfind_min(t_list *list, int size)
{
	t_list	*min;
	int		i;

	if (!list)
		return (NULL);
	min = list;
	i = 0;
	while (i < size && list)
	{
		if (ft_value(list) < ft_value(min))
			min = list;
		list = list->next;
		i++;
	}
	return (min);
}

t_list	*ft_lstfind_max(t_list *list, int size)
{
	t_list	*max;
	int		i;

	if (!list)
		return (NULL);
	max = list;
	i = 0;
	while (i < size && list)
	{
		if (ft_value(list) > ft_value(max))
			max = list;
		list = list->next;
		i++;
	}
	return (max);
}

t_list	*ft_lstfind_pivot(t_stack *stack, int size)
{
	t_list	*min;

	min = ft_lstfind_min(stack->list, size);
	if (!min)
		return (NULL);
	if (stack->name == 'a')
		return (ft_lstfind(ft_value(min) + size / 2, stack->list, size));
	return (ft_lstfind(ft_value(min) + (size - 1) / 2, stack->list, size));
}
