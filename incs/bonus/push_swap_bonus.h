/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baderwae <baderwae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 19:43:37 by baderwae          #+#    #+#             */
/*   Updated: 2025/11/03 09:42:24 by baderwae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "libft.h"
# include <stdio.h>

# define ON_ESS 0
# define ON_ERR 1
# define ON_EOL 2

typedef struct s_stack
{
	char	name;
	t_list	*list;
}	t_stack;

int		*ft_strs_to_tab(int size, char **strs);
t_list	*ft_tab_to_list(int *tab, int size);
int		*ft_get_normalized_tab(int *tab, int size);

t_list	*ft_lstpop_front(t_list **list);
t_list	*ft_lstpop_back(t_list **list);

void	ft_push(t_stack *to, t_stack *from);
void	ft_swap(t_stack *stack);
void	ft_rotate(t_stack *stack);
void	ft_reverse_rotate(t_stack *stack);

t_list	*ft_lstpop_front(t_list **list);
t_list	*ft_lstpop_back(t_list **list);
int		ft_value(t_list	*list);
int		ft_is_sorted(t_list	*list, int size);
int		ft_c_in_str(char c, char *str);

int		ft_instructions(t_stack *a, t_stack *b);

void	ft_update_stacks(t_stack *a, t_stack *b, int size, int is_first);

#endif
