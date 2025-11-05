/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baderwae <baderwae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 12:12:37 by baderwae          #+#    #+#             */
/*   Updated: 2025/11/04 17:27:37 by baderwae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	return (ON_ERR);
}

int	ft_init_stack(t_stack *stack, char name, int *tab, int tab_size)
{
	if (!stack)
		return (ON_ERR);
	stack->name = name;
	stack->list = NULL;
	if (tab)
	{
		stack->list = ft_tab_to_list(tab, tab_size);
		if (!stack->list)
			return (free(tab), ON_ERR);
	}
	return (ON_ESS);
}

int	main(int ac, char **av)
{
	t_btree	*tree;
	t_stack	a;
	t_stack	b;
	int		*tab;
	int		size;

	ft_printf("this is a test %c\n", 'a');

	if (ac < 2)
		return (ON_ESS);
	tab = ft_strs_to_tab(ac - 1, av + 1);
	if (tab)
		tab = ft_get_normalized_tab(tab, ac - 1);
	if (!tab || ft_init_stack(&a, 'a', tab, ac - 1) == ON_ERR)
		return (ft_error());
	ft_init_stack(&b, 'b', NULL, 0);
	size = ft_lstsize(a.list);
	tree = ft_create_tree(size);
	if (!tree)
		return (free(tab), ft_lstclear(&a.list, NULL), ON_ERR);
	ft_quicksort_traversal(tree, &a, &b, 1);
	free(tab);
	ft_clear_tree(tree);
	ft_lstclear(&a.list, NULL);
	ft_lstclear(&b.list, NULL);
	return (ON_ESS);
}
