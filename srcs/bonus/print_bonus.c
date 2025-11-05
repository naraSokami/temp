/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baderwae <baderwae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:45:45 by baderwae          #+#    #+#             */
/*   Updated: 2025/11/04 12:51:47 by baderwae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_print_stacks(t_list *a, t_list *b, int size)
{
	int	i;

	i = 0;
	ft_putstr_fd("\r  a  |  b  \n-----------\n", 1);
	i = 0;
	while (i < size)
	{
		if (a)
			printf("%3d  ", ft_value(a));
		else
			ft_putstr_fd("     ", 1);
		ft_putstr_fd("|", 1);
		if (b)
			printf("%3d\n", ft_value(b));
		else
			ft_putstr_fd("     \n", 1);
		if (a)
			a = a->next;
		if (b)
			b = b->next;
		i++;
	}
}

#ifdef PRINT

void	ft_update_stacks(t_stack *a, t_stack *b, int size, int is_first)
{
	t_stack	*tmp;
	t_list	*a_elem;
	t_list	*b_elem;

	if (a->name == 'b')
	{
		tmp = a;
		a = b;
		b = tmp;
	}
	a_elem = a->list;
	b_elem = b->list;
	//if (!is_first)
	//	printf("\033[%dA", size + 5);
	ft_print_stacks(a_elem, b_elem, size);
	//printf("\ninstruction:\n    ");
	//printf("\033[4D");
	(void)is_first;
}
#else

void	ft_update_stacks(t_stack *a, t_stack *b, int size, int is_first)
{
	(void)a;
	(void)b;
	(void)size;
	(void)is_first;
}
#endif
