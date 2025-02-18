/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:01:09 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/18 13:57:52 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

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
	if (move_id == SA)
		return ("sa");
	if (move_id == SB)
		return ("sb");
	if (move_id == SS)
		return ("ss");
	if (move_id == PA)
		return ("pa");
	if (move_id == PB)
		return ("pb");
	if (move_id == RA)
		return ("ra");
	if (move_id == RB)
		return ("rb");
	if (move_id == RR)
		return ("rr");
	if (move_id == RRA)
		return ("rra");
	if (move_id == RRB)
		return ("rrb");
	if (move_id == RRR)
		return ("rrr");
	return ("");
}
