/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_n_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 00:00:19 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/11 23:34:48 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_2(t_push_swap *p, t_array *arr)
{
	if (((int *)arr->data)[0])
		return (swap(p, arr, NULL, true));
}

void	sort_3(t_push_swap *p)
{
	int	*atab;
	int	first;
	int	second;
	int	third;

	atab = (int *)p->a->data;
	first = atab[0];
	second = atab[1];
	third = atab[2];
	if (first > second && second > third)
		return (rotate(p, p->a, NULL, true), swap(p, p->a, NULL, true));
	if (first > third && third > second)
		return (rotate(p, p->a, NULL, true));
	if (second > first && first > third)
		return (reverse_rotate(p, p->a, NULL, true));
	if (third > first && first > second)
		return (swap(p, p->a, NULL, true));
	if (second > third && third > first)
		return (reverse_rotate(p, p->a, NULL, true), swap(p, p->a, NULL, true));
}

void	sort_5(t_push_swap *p)
{
	int	tmp;
	int	smallest_1 = ft_array_posdist(p->a->head, ft_array_getpos(p->a, 0), p->a->size);
	int	smallest_2 = ft_array_posdist(p->a->head, ft_array_getpos(p->a, 1), p->a->size);

	if (ft_abs(smallest_2) < ft_abs(smallest_1))
	{
		tmp = smallest_1;
		smallest_1 = smallest_2;
		smallest_2 = tmp;
	}
	jump_to_val(p, p->a, ft_array_getval(p->a, p->a->head, smallest_1));
	push(p, p->a, p->b);
	smallest_2 = ft_array_posdist(p->a->head, ft_array_getpos(p->a, 1), p->a->size);
	jump_to_val(p, p->a, ft_array_getval(p->a, p->a->head, smallest_2));
	push(p, p->a, p->b);
	// sort_3(p);
	// jump_to_val(p, p->a, 2);
	// push(p, p->b, p->a);
	// push(p, p->b, p->a);
}

static void	_push_smallests(t_push_swap *p)
{
	
}
