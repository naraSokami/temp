/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baderwae <baderwae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 08:47:14 by baderwae          #+#    #+#             */
/*   Updated: 2025/08/13 08:47:14 by baderwae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_btree	*ft_new_node(int value)
{
	t_btree	*node;

	node = malloc(sizeof(t_btree));
	if (!node)
		return (NULL);
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

void	ft_clear_tree(t_btree *node)
{
	if (!node)
		return ;
	if (node->left)
		ft_clear_tree(node->left);
	if (node->right)
		ft_clear_tree(node->right);
	free(node);
}

t_btree	*ft_create_tree_rec(t_btree *node, int size)
{
	if (!node)
		return (NULL);
	if (size > MAX_SORTABLE_SIZE && (size + 1) / 2 > 0)
	{
		node->left = ft_create_tree_rec(ft_new_node((size + 1) / 2),
				(size + 1) / 2);
		if (!node->left)
			return (free(node), NULL);
	}
	if (size > MAX_SORTABLE_SIZE && size / 2 > 0)
	{
		node->right = ft_create_tree_rec(ft_new_node(size / 2), size / 2);
		if (!node->right)
			return (ft_clear_tree(node), NULL);
	}
	return (node);
}

t_btree	*ft_create_tree(int size)
{
	t_btree	*tree;

	tree = ft_new_node(size);
	if (!tree)
		return (NULL);
	tree = ft_create_tree_rec(tree, size);
	return (tree);
}
