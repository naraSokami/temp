/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baderwae <baderwae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 09:59:35 by baderwae          #+#    #+#             */
/*   Updated: 2025/08/14 09:59:35 by baderwae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_push(t_stack *to, t_stack *from)
{
	if (!to || !from || !from->list)
		return ;
	ft_lstadd_front(&to->list, ft_lstpop_front(&from->list));
}

void	ft_rotate(t_stack *stack)
{
	if (!stack || !stack->list)
		return ;
	ft_lstadd_back(&stack->list, ft_lstpop_front(&stack->list));
}

void	ft_reverse_rotate(t_stack *stack)
{
	if (!stack || !stack->list)
		return ;
	ft_lstadd_front(&stack->list, ft_lstpop_back(&stack->list));
}

void	ft_swap(t_stack *stack)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !stack->list || !stack->list->next)
		return ;
	first = ft_lstpop_front(&stack->list);
	second = ft_lstpop_front(&stack->list);
	ft_lstadd_front(&stack->list, first);
	ft_lstadd_front(&stack->list, second);
}
