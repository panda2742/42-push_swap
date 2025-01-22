/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:14:30 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/22 15:39:54 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	push(t_env *env, char c, int to_print)
{
	int	elt_to_push;

	if (to_print)
		ft_printf("p%c\n", c);
	
}

static int	_extract_from_stack(int *tab, size_t head, size_t size)
{
	int	elt;

	elt = tab[head];
	while (head + 1 < size)
	{
		tab[head] = tab[head + 1];
		head++;
	}
	return (elt);
}

static int	_add_to_stack(int *tab, size_t head, size_t size, int elt)
{
	int	tmp;

	while (head + 1 < size)
	{
		tmp = tab[head + 1];
		tab[head + 1] = tab[head];
		head++;
	}
}
