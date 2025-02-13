/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:58:06 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/13 16:55:54 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void		_pre_sort(t_push_swap *p);
static t_bool	_is_in_bucket(int i_bk, int bk_size, int val);

void	sort_big(t_push_swap *p)
{
	int	*tab;
	int	i;
	int	i_min;
	int	cost;

	_pre_sort(p);
	sort_3(p, p->a);
	while (p->b->size)
	{
		if (DEBUG)
			ft_array_prints(p->a, p->b);
		tab = ((int *)p->b->data);
		i = -1;
		cost = 65000;
		i_min = 0;
		while (++i < p->b->size)
		{
			cost = cost_to_move(p->b, p->a, tab[i]);
			if (cost < cost_to_move(p->b, p->a, tab[i_min]))
				i_min = i;
		}
		jump_to_val(p, p->b, tab[i_min]);
		jump_to_val(p, p->a, correct_head(p->a, tab[i_min]));
		push(p, p->b, p->a);
	}
	jump_to_val(p, p->a, 0);
}

static void	_pre_sort(t_push_swap *p)
{
	int	cur;
	int	buckets;
	int	i_bk;
	int	bk_size;
	int	i;
	int	size;

	buckets = ft_sqrt(p->stack_size) / 4;
	bk_size = p->stack_size / buckets;
	i_bk = 0;
	while (i_bk < buckets)
	{
		i = -1;
		size = p->a->size;
		while (++i < size)
		{
			cur = ((int *)p->a->data)[p->a->head];
			if (_is_in_bucket(i_bk, bk_size, cur) || _is_in_bucket(i_bk + 1, bk_size, cur))
			{
				if (cur == 0 || cur == 1 || cur == p->stack_size - 1)
				{
					rotate(p, p->a, NULL, true);
					continue ;
				}
				push(p, p->a, p->b);
				if (_is_in_bucket(i_bk + 1, bk_size, cur))
					rotate(p, p->b, NULL, true);
				continue ;
			}
			rotate(p, p->a, NULL, true);
		}
		i_bk += 2;
	}
	i = -1;
	size = p->a->size;
	while (++i < size)
	{
		cur = ((int *)p->a->data)[p->a->head];
		if (cur == 0 || cur == 1 || cur == p->stack_size - 1)
			rotate(p, p->a, NULL, true);
		else
			push(p, p->a, p->b);
	}
}

static t_bool	_is_in_bucket(int i_bk, int bk_size, int val)
{
	const int	bk_min = bk_size * i_bk;
	const int	bk_max = bk_size * (i_bk + 1);

	if (val >= bk_min && val < bk_max)
		return (true);
	return (false);
}
