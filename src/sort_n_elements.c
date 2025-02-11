/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_n_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 00:00:19 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/11 09:40:05 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_2(t_push_swap *p)
{
	if (((int *)p->a->data)[0])
		return (swap(p, p->a, NULL, true));
}

void	sort_3(t_push_swap *p)
{
	int	*atab;
	int	first;
	int	second;

	atab = (int *)p->a->data;
	first = atab[0];
	second = atab[1];
	if (first == 2 && second == 1)
		return (rotate(p, p->a, NULL, true), swap(p, p->a, NULL, true));
	if (first == 2 && second == 0)
		return (rotate(p, p->a, NULL, true));
	if (first == 1 && second == 2)
		return (reverse_rotate(p, p->a, NULL, true));
	if (first == 1 && second == 0)
		return (swap(p, p->a, NULL, true));
	if (first == 0 && second == 2)
		return (reverse_rotate(p, p->a, NULL, true), swap(p, p->a, NULL, true));
}
