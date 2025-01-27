/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_getter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:19:34 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/27 11:35:00 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	getval(int *stack, int pos, int size, int offset)
{
	int	sign;

	sign = ft_sign(offset);
	while (offset)
	{
		pos += sign;
		if (pos < 0)
			pos = size - 1;
		if (pos > size)
			pos = 0;
		offset -= sign;
	}
	return (stack[pos]);
}

int	getpos(int *stack, int value, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		if (stack[i] == value)
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
	while (++i != (int)pos)
	{
		if (i == (int)size)
			i = -1;
		distr++;
	}
	distrr = 0;
	i = cur_pos + 1;
	while (--i != (int)pos)
	{
		if (i == -1)
			i = size;
		distrr--;
	}
	if ((int)ft_abs(distrr) >= distr)
		return (distr);
	return (distrr);
}
