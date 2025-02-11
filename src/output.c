/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:01:09 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/11 09:40:21 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	read_moves_flow(t_push_swap *p)
{
	t_instruction	*instr;

	instr = p->instructions[0];
	while (instr)
	{
		ft_printf("%s\n", move_str(instr->move_id));
		instr = instr->next;
	}
}

char	*move_str(t_move_id move_id)
{
	static char	moves_short[8][3] = {
		"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr"
	};
	static char	moves_long[3][4] = {"rra", "rrb", "rrr"};

	if (move_id >= RRA)
		return (moves_long[move_id - 8]);
	return (moves_short[move_id]);
}
