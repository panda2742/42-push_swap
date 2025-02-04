/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:44:43 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/04 21:22:19 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	*get_bucket_composition(
	t_stack *s, int bucket_offset, int bucket_size, int *pushed)
{
	int	*elements;
	int	i;

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
