/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:16:11 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/05 12:05:56 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack_buckets	*create_stack_buckets(void)
{
	t_stack_buckets	*buckets;

	buckets = malloc(sizeof(t_stack_buckets));
	if (!buckets)
		return (NULL);
	buckets->buckets = NULL;
	buckets->total_moves = 0;
	return (buckets);
}

t_bucket	*append_bucket(t_stack_buckets *parent, int *composition, int size)
{
	t_bucket	*bucket;
	t_bucket	*last;

	bucket = malloc(sizeof(t_bucket));
	if (!bucket)
		return (NULL);
	bucket->composition = composition;
	bucket->size = size;
	bucket->next = NULL;
	bucket->moves = NULL;
	if (!parent->buckets)
	{
		parent->buckets = malloc(sizeof(t_bucket *));
		parent->buckets[0] = bucket;
		return (bucket);
	}
	last = parent->buckets[0];
	while (last->next)
		last = last->next;
	last->next = bucket;
	return (bucket);
}

void	empty_stack_buckets(t_stack_buckets *sb)
{
	t_bucket	*b;
	t_bucket	*next;

	if (sb->buckets)
	{
		b = sb->buckets[0];
		while (b)
		{
			free(b->composition);
			next = b->next;
			free(b);
			b = next;
		}
		free(sb->buckets);
	}
	free(sb);
}
