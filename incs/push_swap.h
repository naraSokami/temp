/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baderwae <baderwae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 12:33:49 by baderwae          #+#    #+#             */
/*   Updated: 2025/11/03 09:42:54 by baderwae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>

# define ON_ESS 0
# define ON_ERR 1

# define MAX_SORTABLE_SIZE 3

typedef struct s_stack
{
	char	name;
	t_list	*list;
}	t_stack;

typedef struct s_btree
{
	int				value;
	struct s_btree	*left;
	struct s_btree	*right;
}	t_btree;

int		*ft_strs_to_tab(int size, char **strs);
t_list	*ft_tab_to_list(int *tab, int size);
int		*ft_get_normalized_tab(int *tab, int size);

t_list	*ft_lstpop_front(t_list **list);
t_list	*ft_lstpop_back(t_list **list);
void	ft_lstput_on_top(int index, t_stack *stack, int size);

void	ft_push(t_stack *to, t_stack *from);
void	ft_swap(t_stack *stack);
void	ft_rotate(t_stack *stack);
void	ft_reverse_rotate(t_stack *stack);

int		ft_abs(int n);
int		ft_value(t_list	*list);
int		ft_get_lesser_size(int value, t_stack *stack, int size);
int		ft_is_sorted(t_list	*list, int size);
int		ft_is_reverse_sorted(t_list	*list, int size);

t_list	*ft_lstfind_min(t_list *list, int size);
t_list	*ft_lstfind_max(t_list *list, int size);
t_list	*ft_lstfind_pivot(t_stack *stack, int size);

t_btree	*ft_create_tree(int size);
void	ft_clear_tree(t_btree *node);

void	ft_little_sort(t_stack *stack, int size);
void	ft_quicksort_traversal(
			t_btree *node, t_stack *from, t_stack *to, int is_first);

#endif
