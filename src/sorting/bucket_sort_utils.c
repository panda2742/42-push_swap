/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:44:43 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/05 10:54:32 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	_get_size(int stack_size, int buckets, int offset);

int	*get_bucket_composition(
	t_stack *s, int bucket_offset, int stack_size, int buckets, int *pushed)
{
	int	*elements;
	int	i;
	int	bucket_size;

	bucket_size = _get_size(stack_size, buckets, bucket_offset);
	elements = malloc((bucket_size + 1) * sizeof(int));
	if (!elements)
		return (NULL);
	*pushed = 0;
	i = -1;
	while (++i < bucket_size && (bucket_size * bucket_offset + i) < s->size)
	{
		elements[i] = s->size - (bucket_size * bucket_offset + i + 1);
		*pushed += 1;
	}
	elements[i] = -1;
	return (elements);
}

static int	_get_size(int stack_size, int buckets, int offset)
{
	int	size;
	int	base;
	int	remainder;

	size = 0;
	base = stack_size / buckets;
	remainder = stack_size % buckets;
	if (offset < remainder)
		size++;
	size += base;
	return (size);
}