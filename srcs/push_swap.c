/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baderwae <baderwae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 10:37:09 by baderwae          #+#    #+#             */
/*   Updated: 2025/08/15 10:37:09 by baderwae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_nrotate_back(t_stack *stack, int size, int lesser_size, int n)
{
	int	i;

	i = 0;
	if (ft_lstsize(stack->list) == (size + 1) / 2)
	{
		while (i < size - lesser_size)
		{
			ft_reverse_rotate(stack);
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			ft_rotate(stack);
			i++;
		}
	}
}

void	ft_lstsplit(t_stack *from, t_stack *to, int size)
{
	t_list	*pivot;
	int		lesser_size;
	int		i;
	int		rotate_count;

	pivot = ft_lstfind_pivot(from, size);
	lesser_size = ft_get_lesser_size(ft_value(pivot), from, size);
	rotate_count = 0;
	i = 0;
	while (i < lesser_size)
	{
		if (from->name == 'a' && ft_value(pivot) > ft_value(from->list))
			ft_push(to, from);
		else if (from->name == 'b' && ft_value(pivot) < ft_value(from->list))
			ft_push(to, from);
		else
		{
			rotate_count++;
			ft_reverse_rotate(from);
		}
		i++;
	}
	ft_nrotate_back(from, size, lesser_size, rotate_count);
}

void	ft_npush(t_stack *to, t_stack *from, int n)
{
	if (!to || !from)
		return ;
	while (n > 0)
	{
		ft_push(to, from);
		n--;
	}
}

void	ft_quicksort_traversal(t_btree *node, t_stack *from, t_stack *to,
	int is_first)
{
	if (is_first && (!node->left || !node->right))
		ft_little_sort(from, node->value);
	if (!node || !node->left || !node->right)
		return ;
	if ((from->name == 'a' && !ft_is_sorted(from->list, node->value))
		|| (from->name == 'b'
			&& !ft_is_reverse_sorted(from->list, node->value)))
	{
		ft_lstsplit(from, to, node->value);
		ft_quicksort_traversal(node->left, from, to, 0);
		ft_quicksort_traversal(node->right, to, from, 0);
		if (node->left->value < MAX_SORTABLE_SIZE + 1)
			ft_little_sort(from, node->left->value);
		if (node->right->value < MAX_SORTABLE_SIZE + 1)
			ft_little_sort(to, node->right->value);
		ft_npush(from, to, node->right->value);
	}
}
