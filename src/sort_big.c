/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:58:06 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/12 14:16:31 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	_pre_sort(t_push_swap *p);

void	sort_big(t_push_swap *p)
{
	int	*tab;
	int	i;
	int	i_min;
	int	cost;

	_pre_sort(p);
	push(p, p->b, p->a);
	push(p, p->b, p->a);
	push(p, p->b, p->a);
	sort_3(p, p->a);
	while (p->b->size)
	{
		tab = ((int *)p->b->data);
		i = -1;
		cost = 65000;
		i_min = 0;
		while (++i < p->b->size)
		{
			cost = cost_to_move(p->b, p->a, tab[i]);
			printf(MAGENTA "cost: %d for %d\n" RESET, cost, tab[i]);
			if (cost_to_move(p->b, p->a, tab[i]) < cost_to_move(p->b, p->a, tab[i_min]))
				i_min = i;
		}
		if (DEBUG)
			ft_array_prints(p->a, p->b);
		printf("   %d [%d]\n", tab[i_min], cost_to_move(p->b, p->a, tab[i_min]));
		jump_to_val(p, p->b, tab[i_min]);
		push(p, p->b, p->a);
		printf("------------\n");
	}
}

static void	_pre_sort(t_push_swap *p)
{
	while (p->a->size)
		push(p, p->a, p->b);
}
