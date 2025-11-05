/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baderwae <baderwae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:58:13 by baderwae          #+#    #+#             */
/*   Updated: 2025/08/15 15:58:13 by baderwae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_bigger(t_list *list, int n)
{
	int	size;

	size = 0;
	while (list)
	{
		list = list->next;
		size++;
		if (size > n)
			return (1);
	}
	return (0);
}

void	ft_full_little_sort(t_stack *stack, int size)
{
	t_list	*min;
	t_list	*max;

	if (size < 2 || !stack || !stack->list || !stack->list->next)
		return ;
	if (size == 2
		&& ((stack->name == 'a'
				&& (ft_value(stack->list) > ft_value(stack->list->next)))
			|| (stack->name == 'b'
				&& (ft_value(stack->list) < ft_value(stack->list->next)))))
		return (ft_swap(stack));
	min = ft_lstfind_min(stack->list, size);
	max = ft_lstfind_max(stack->list, size);
	if ((stack->name == 'a' && ft_value(stack->list) == ft_value(max))
		|| (stack->name == 'b' && ft_value(stack->list) == ft_value(min)))
		ft_rotate(stack);
	else if ((stack->name == 'a'
			&& ft_value(stack->list->next) == ft_value(max))
		|| (stack->name == 'b' && ft_value(stack->list->next) == ft_value(min)))
		ft_reverse_rotate(stack);
	if ((stack->name == 'a' && ft_value(stack->list) != ft_value(min))
		|| (stack->name == 'b' && ft_value(stack->list) != ft_value(max)))
		ft_swap(stack);
}

void	ft_sub_little_sort(t_stack *stack, int size)
{
	if (size < 2 || !stack || !stack->list || !stack->list->next)
		return ;
	if ((stack->name == 'a'
			&& (ft_value(stack->list) > ft_value(stack->list->next)))
		|| (stack->name == 'b'
			&& (ft_value(stack->list) < ft_value(stack->list->next))))
		ft_swap(stack);
	if (size > 2)
	{
		if ((stack->name == 'a' && !ft_is_sorted(stack->list, size))
			|| (stack->name == 'b' && !ft_is_reverse_sorted(stack->list, size)))
		{
			ft_rotate(stack);
			ft_swap(stack);
			ft_reverse_rotate(stack);
		}
		if ((stack->name == 'a' && !ft_is_sorted(stack->list, size))
			|| (stack->name == 'b' && !ft_is_reverse_sorted(stack->list, size)))
			ft_swap(stack);
	}
}

void	ft_little_sort(t_stack *stack, int size)
{
	if (ft_is_bigger(stack->list, size))
		ft_sub_little_sort(stack, size);
	else
		ft_full_little_sort(stack, size);
}
