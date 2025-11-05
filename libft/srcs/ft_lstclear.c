/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baderwae <baderwae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:10:49 by baderwae          #+#    #+#             */
/*   Updated: 2025/11/03 09:38:02 by baderwae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*prev;

	if (!lst)
		return ;
	while (*lst)
	{
		prev = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(prev, del);
	}
}
