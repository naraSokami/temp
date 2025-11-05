/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baderwae <baderwae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 14:45:01 by baderwae          #+#    #+#             */
/*   Updated: 2025/08/10 14:45:01 by baderwae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_lstput_on_top(int index, t_stack *stack, int size)
{
	int	i;

	i = 0;
	if (index > size / 2)
	{
		while (i < ft_abs(index - size))
		{
			ft_reverse_rotate(stack);
			i++;
		}
	}
	else
	{
		while (i < index)
		{
			ft_rotate(stack);
			i++;
		}
	}
}
