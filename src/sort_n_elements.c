/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_n_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 00:00:19 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/12 12:18:33 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_2(t_push_swap *p, t_array *src)
{
	if (((int *)src->data)[0])
		return (swap(p, src, NULL, true));
}

void	sort_3(t_push_swap *p, t_array *src)
{
	int	*atab;
	int	first;
	int	second;
	int	third;

	atab = (int *)src->data;
	first = ft_array_getval(src, src->head, 0);
	second = ft_array_getval(src, src->head, 1);
	third = ft_array_getval(src, src->head, 2);
	if (first > second && second > third)
		return (rotate(p, src, NULL, true), swap(p, src, NULL, true));
	if (first > third && third > second)
		return (rotate(p, src, NULL, true));
	if (second > first && first > third)
		return (reverse_rotate(p, src, NULL, true));
	if (third > first && first > second)
		return (swap(p, src, NULL, true));
	if (second > third && third > first)
		return (reverse_rotate(p, src, NULL, true), swap(p, src, NULL, true));
}

void	sort_5(t_push_swap *p, t_array *src, t_array *dest)
{
	jump_to_val(p, src, 0);
	push(p, src, dest);
	jump_to_val(p, src, 1);
	push(p, src, dest);
	sort_3(p, src);
	push(p, dest, src);
	push(p, dest, src);
}
