/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:01:09 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/10 16:57:46 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	_execute_move(
				t_array *a, t_array *b, t_move_id move_id, t_bool print_move);

int	read_moves_flow(t_push_swap *p, t_bool print_move)
{
	t_instruction	*instr;
	int				ops;

	instr = p->instructions[0];
	ops = 0;
	while (instr)
	{
		_execute_move(p->a, p->b, instr->move_id, print_move);
		instr = instr->next;
	}
	return (ops);
}

static void	_execute_move(
	t_array *a, t_array *b, t_move_id move_id, t_bool print_move)
{
	if (move_id == SA)
		swap(a, NULL, print_move);
	else if (move_id == SB)
		swap(b, NULL, print_move);
	else if (move_id == SS)
		swap(a, b, print_move);
	else if (move_id == PA)
		push(a, NULL, print_move);
	else if (move_id == PB)
		push(b, NULL, print_move);
	else if (move_id == RA)
		rotate(a, NULL, print_move);
	else if (move_id == RB)
		rotate(b, NULL, print_move);
	else if (move_id == RR)
		rotate(a, b, print_move);
	else if (move_id == RRA)
		reverse_rotate(a, NULL, print_move);
	else if (move_id == RRB)
		reverse_rotate(b, NULL, print_move);
	else if (move_id == RRR)
		reverse_rotate(a, b, print_move);
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
