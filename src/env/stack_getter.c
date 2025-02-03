/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_getter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:19:34 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/03 11:50:16 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	getval(t_stack *s, int pos, int offset)
{
	int	sign;

	sign = ft_sign(offset);
	while (offset)
	{
		pos += sign;
		if (pos < 0)
			pos = s->size - 1;
		if (pos > s->size)
			pos = 0;
		offset -= sign;
	}
	return (s->tab[pos]);
}

int	getpos(t_stack *s, int value)
{
	int	i;

	i = -1;
	while (++i < s->size)
		if (s->tab[i] == value)
			return (i);
	return (i);
}

int	distance_to_pos(int size, int cur_pos, int pos)
{
	int	distr;
	int	distrr;
	int	i;

	distr = 0;
	i = cur_pos - 1;
	while (++i != pos)
	{
		if (i == size)
			i = -1;
		distr++;
	}
	distrr = 0;
	i = cur_pos + 1;
	while (--i != pos)
	{
		if (i == -1)
			i = size;
		distrr--;
	}
	if ((int)ft_abs(distrr) >= distr)
		return (distr);
	return (distrr);
}