/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_getter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:19:34 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/24 17:10:39 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

size_t	get_stack_min(int *stack, size_t size)
{
	size_t	i;
	size_t	min;
	
	i = -1;
	min = 0;
	while (++i < size)
		if (stack[i] < stack[min])
			min = i;
	return (min);
}

size_t	get_stack_max(int *stack, size_t size)
{
	size_t	i;
	size_t	max;
	
	i = -1;
	max = 0;
	while (++i < size)
		if (stack[i] > stack[max])
			max = i;
	return (max);
}

size_t	getval(int *stack, size_t pos, size_t size, ssize_t offset)
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

size_t	getpos(int *stack, int value, size_t size)
{
	size_t	i;

	i = -1;
	while (++i < size)
		if (stack[i] == value)
			return (i);
	return (i);
}

ssize_t	distance_to_pos(size_t size, size_t cur_pos, size_t pos)
{
	ssize_t	distr;
	ssize_t	distrr;
	ssize_t	i;

	distr = 0;
	i = cur_pos - 1;
	while (++i != (ssize_t)pos)
	{
		if (i == (ssize_t)size)
			i = -1;
		distr++;
	}
	distrr = 0;
	i = cur_pos + 1;
	while (--i != (ssize_t)pos)
	{
		if (i == -1)
			i = size;
		distrr--;
	}
	if (ft_abs(distrr) >= distr)
		return (distr);
	return (distrr);
}
