/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baderwae <baderwae@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 06:33:22 by baderwae          #+#    #+#             */
/*   Updated: 2025/08/15 06:33:22 by baderwae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_is_valid_instrucion(char *inst)
{
	if (!inst)
		return (1);
	if (!inst[0] || !ft_c_in_str(inst[0], "psr"))
		return (0);
	if (!inst[1]
		|| (inst[0] == 'p' && !ft_c_in_str(inst[1], "ab"))
		|| (inst[0] == 's' && !ft_c_in_str(inst[1], "abs"))
		|| (inst[0] == 'r' && !ft_c_in_str(inst[1], "abr")))
		return (0);
	if ((inst[0] == 'r' && inst[1] == 'r' && inst[2] && inst[2] != '\n'
			&& !ft_c_in_str(inst[2], "abr")))
		return (0);
	if (((inst[0] != 'r' || inst[1] != 'r') && inst[2] && inst[2] != '\n'))
		return (0);
	if ((inst[2] && inst[3] && inst[3] != '\n'))
		return (0);
	return (1);
}

char	*ft_read_instruction(void)
{
	char	*instruction;

	instruction = get_next_line(0);
	if (instruction && !ft_is_valid_instrucion(instruction))
		return (free(instruction), NULL);
	return (instruction);
}

void	ft_exec_instruction(char *inst, t_stack *a, t_stack *b)
{
	if (inst[0] == 'p' && inst[1] == 'a')
		ft_push(a, b);
	else if (inst[0] == 'p' && inst[1] == 'b')
		ft_push(b, a);
	else if (inst[0] == 's')
	{
		if (inst[1] == 'a' || inst[1] == 's')
			ft_swap(a);
		if (inst[1] == 'b' || inst[1] == 's')
			ft_swap(b);
	}
	else if (inst[0] == 'r' && (inst[2] == '\n' || !inst[2]))
	{
		if (inst[1] == 'a' || inst[1] == 'r')
			ft_rotate(a);
		if (inst[1] == 'b' || inst[1] == 'r')
			ft_rotate(b);
	}
	else
	{
		if (inst[2] == 'a' || inst[2] == 'r')
			ft_reverse_rotate(a);
		if (inst[2] == 'b' || inst[2] == 'r')
			ft_reverse_rotate(b);
	}
}

int	ft_instruction(t_stack *a, t_stack *b, int size)
{
	char	*line;

	line = get_next_line(0);
	if (line)
	{
		if (!ft_is_valid_instrucion(line))
		{
			free(line);
			return (ON_ERR);
		}
		ft_exec_instruction(line, a, b);
		ft_update_stacks(a, b, size, 0);
	}
	if (line)
		return (free(line), ON_ESS);
	return (ON_EOL);
}

int	ft_instructions(t_stack *a, t_stack *b)
{
	int	size;
	int	return_code;

	size = ft_lstsize(a->list);
	ft_update_stacks(a, b, size, 1);
	return_code = ft_instruction(a, b, size);
	while (return_code == ON_ESS)
		return_code = ft_instruction(a, b, size);
	if (return_code == ON_ERR)
		return (ON_ERR);
	return (ON_ESS);
}
