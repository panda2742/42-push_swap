/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:01:09 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/20 17:22:31 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_instruction	*_optimize_moves(
							t_instruction *move, t_move_id mv_base);
static void				_print_optimization(int g1, int g2, t_move_id mv_base);
static t_move_id		_get_move_base(t_move_id mv_id);

void	read_moves_flow(t_push_swap *p)
{
	t_instruction	*instr;

	instr = p->instructions[0];
	while (instr)
	{
		if (instr->move_id < PA || instr->move_id > PB)
			instr = _optimize_moves(instr, _get_move_base(instr->move_id));
		if (instr)
		{
			ft_printf("%s\n", move_str(instr->move_id));
			instr = instr->next;
		}
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

static t_instruction	*_optimize_moves(t_instruction *move, t_move_id mv_base)
{
	t_instruction	*mv;
	t_bool			opt_is_possible;
	int				groups[2];

	mv = move;
	opt_is_possible = true;
	groups[0] = 0;
	groups[1] = 0;
	while (opt_is_possible && mv)
	{
		if (mv->move_id - mv_base == 0 || mv ->move_id - mv_base == 1)
		{
			groups[mv->move_id - mv_base]++;
			mv = mv->next;
		}
		else
			opt_is_possible = false;
	}
	_print_optimization(groups[0], groups[1], mv_base);
	return (mv);
}

static void	_print_optimization(int g1, int g2, t_move_id mv_base)
{
	while (g1 && g2)
	{
		g1--;
		g2--;
		ft_printf("%s\n", move_str(mv_base + 2));
	}
	while (g1--)
		ft_printf("%s\n", move_str(mv_base));
	while (g2--)
		ft_printf("%s\n", move_str(mv_base + 1));
}

static t_move_id	_get_move_base(t_move_id mv_id)
{
	if (mv_id < PA)
		return (SA);
	if (mv_id <= RR)
		return (RA);
	return (RRA);
}
