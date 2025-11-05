/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baderwae <baderwae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 09:11:00 by baderwae          #+#    #+#             */
/*   Updated: 2025/08/14 09:11:00 by baderwae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_error(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	return (ON_ERR);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	int		*tab;

	if (ac < 2)
		return (ON_ESS);
	tab = ft_strs_to_tab(ac - 1, av + 1);
	if (!tab)
		return (ft_error());
	a.name = 'a';
	a.list = ft_tab_to_list(tab, ac - 1);
	if (!a.list)
		return (free(tab), ON_ERR);
	b.name = 'b';
	b.list = NULL;
	if (ft_instructions(&a, &b) == ON_ERR)
		return (ft_error());
	if (!b.list && ft_is_sorted(a.list, ft_lstsize(a.list)))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	free(tab);
	ft_lstclear(&a.list, NULL);
	ft_lstclear(&b.list, NULL);
	return (ON_ESS);
}
