/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_n_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 00:00:19 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/10 16:41:13 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	_execute_3s_comb(t_push_swap *p, t_move_id m1, t_move_id m2);

int	sort_2(t_push_swap *p)
{
	if (((int *)p->a->data)[0])
		return (create_instr_flow(p, SA), 1);
	return (0);
}

int	sort_3(t_push_swap *p)
{
	int	*atab;
	int	first;
	int	second;

	atab = (int *)p->a->data;
	first = atab[0];
	second = atab[1];
	if (first == 2 && second == 1)
		return (_execute_3s_comb(p, RA, SA));
	if (first == 2 && second == 0)
		return (_execute_3s_comb(p, RA, -1));
	if (first == 1 && second == 2)
		return (_execute_3s_comb(p, RRA, -1));
	if (first == 1 && second == 0)
		return (_execute_3s_comb(p, SA, -1));
	if (first == 0 && second == 2)
		return (_execute_3s_comb(p, RRA, SA));
	return (2);
}

static int	_execute_3s_comb(t_push_swap *p, t_move_id m1, t_move_id m2)
{
	create_instr_flow(p, m1);
	if ((int)m2 != -1)
		create_instr(p, m2);
	return (1 + ((int)m2 != -1));
}
