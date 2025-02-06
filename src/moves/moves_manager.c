/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:01:09 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/06 14:51:48 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	_execute_move(
				t_stack *a, t_stack *b, t_move_id move_id, t_bool print_move);

t_move	*create_moves(t_move_id move_id, t_move *prev)
{
	t_move	*move;

	move = malloc(sizeof(t_move));
	if (!move)
		return (NULL);
	move->move = move_id;
	prev->next = move;
	return (move);
}

int	read_moves_flow(t_env *env, t_move *flow, t_bool print_move)
{
	int		ops;
	t_stack	*a;
	t_stack	*b;

	ops = 0;
	a = get_stack_by_id(env, 'a');
	b = get_stack_by_id(env, 'b');
	while (flow)
	{
		_execute_move(a, b, flow->move, print_move);
		flow = flow->next;
	}
	return (ops);
}

t_move	*create_move(t_move *prev, t_move_id move_id)
{
	t_move	*move;

	move = malloc(sizeof(t_move));
	if (!move)
		return (NULL);
	move->move = move_id;
	move->next = NULL;
	if (prev)
		prev->next = move;
	return (move);
}

static void	_execute_move(
	t_stack *a, t_stack *b, t_move_id move_id, t_bool print_move)
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
