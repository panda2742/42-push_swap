/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:23:10 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/04 21:22:56 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	bucket_sort(t_push_swap *p)
{
	t_stack_buckets	*sb;
	t_stack_buckets	*min_sb;
	int				buckets;
	int				moves;

	min_sb = NULL;
	buckets = 0;
	while (++buckets < p->env->stack_size / 2)
	{
		sb = calc_bucket_sort(create_stack_buckets(), p, buckets);
		if (!min_sb)
			min_sb = sb;
		if (!min_sb || min_sb == sb)
			continue ;
		if (min_sb->total_moves <= sb->total_moves)
		{
			empty_stack_buckets(min_sb);
			min_sb = sb;
			continue ;
		}
		empty_stack_buckets(sb);
	}
	moves = min_sb->total_moves;
	empty_stack_buckets(min_sb);
	return (moves);
}

t_stack_buckets	*calc_bucket_sort(
	t_stack_buckets *sb, t_push_swap *p, int buckets)
{
	t_bucket	*b;
	t_stack		*a;
	int			bucket_size;
	int			i;

	a = get_stack_by_id(p->env, 'a');
	bucket_size = p->env->stack_size / buckets
		+ (p->env->stack_size % buckets != 0);
	i = -1;
	while (++i < buckets)
	{
		b = append_bucket(sb, NULL, 0);
		b->composition = get_bucket_composition(a, i, bucket_size, &b->size);
	}
	display_stack_bucket(sb);
	return (sb);
}
