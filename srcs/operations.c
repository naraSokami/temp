/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baderwae <baderwae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 15:04:41 by baderwae          #+#    #+#             */
/*   Updated: 2025/11/04 17:19:58 by baderwae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack *to, t_stack *from)
{
	if (!to || !from || !from->list)
		return ;
	ft_printf("p%c\n", to->name);
	ft_lstadd_front(&to->list, ft_lstpop_front(&from->list));
}

void	ft_rotate(t_stack *stack)
{
	ft_printf("r%c\n", stack->name);
	if (!stack || !stack->list)
		return ;
	ft_lstadd_front(&stack->list, ft_lstpop_back(&stack->list));
}

void	ft_reverse_rotate(t_stack *stack)
{
	ft_printf("rr%c\n", stack->name);
	if (!stack || !stack->list)
		return ;
	ft_lstadd_back(&stack->list, ft_lstpop_front(&stack->list));
}

void	ft_swap(t_stack *stack)
{
	t_list	*first;
	t_list	*second;

	ft_printf("s%c\n", stack->name);
	if (!stack || !stack->list || !stack->list->next)
		return ;
	first = ft_lstpop_front(&stack->list);
	second = ft_lstpop_front(&stack->list);
	ft_lstadd_front(&stack->list, first);
	ft_lstadd_front(&stack->list, second);
}
