/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_n_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 00:00:19 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/12 12:14:57 by ehosta           ###   ########.fr       */
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
	first = ft_array_getval(p->a, p->a->head, 0);
	second = ft_array_getval(p->a, p->a->head, 1);
	third = ft_array_getval(p->a, p->a->head, 2);
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
	jump_to_val(p, p->a, 0);
	push(p, p->a, p->b);
	jump_to_val(p, p->a, 1);
	push(p, p->a, p->b);
	sort_3(p);
	push(p, p->b, p->a);
	push(p, p->b, p->a);
}
