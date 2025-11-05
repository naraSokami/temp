/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baderwae <baderwae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 13:06:54 by baderwae          #+#    #+#             */
/*   Updated: 2025/10/23 10:15:25 by baderwae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*mapped;
	t_list	*new;

	if (!lst || !f || !(*f) || !del || !(*del))
		return (NULL);
	mapped = NULL;
	while (lst)
	{
		new = ft_lstnew((*f)(lst->content));
		if (!new)
		{
			ft_lstclear(&mapped, del);
			return (NULL);
		}
		ft_lstadd_back(&mapped, new);
		lst = lst->next;
	}
	return (mapped);
}
