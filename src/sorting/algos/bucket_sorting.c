/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:23:10 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/29 12:07:11 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

static int	_push_bucket(t_env *env, int buckets, int offset, int emulation, int elt_per_bucket);

int	bucket_sorting(t_env *env, int emulation)
{
	int	buckets;
	int	moves;
	int	max_buckets;
	int	max_moves;
	int	i;

	buckets = 0;
	max_buckets = 0;
	max_moves = 65000;
	while (++buckets < env->stack_size / 2)
	{
		buckets = 2;
		moves = 0;
		i = -1;
		while (++i < buckets)
			moves += _push_bucket(env, buckets, i, emulation, env->stack_size / buckets + (1 * (env->stack_size % buckets != 0)));
		if (moves < max_moves)
		{
			max_moves = moves;
			max_buckets = buckets;
		}
		break ;
	}
	(void)env;
	(void)emulation;
	return (max_moves);
}

static int	_push_bucket(t_env *env, int buckets, int offset, int emulation, int elt_per_bucket)
{
	int	moves;
	int	pushed;
	int	i;
	int	*elements;

	moves = 0;
	i = -1;
	if ((++i + 1))
	{
		elements = get_bucket_composition(env, offset, elt_per_bucket, &pushed);
		// moves += execute_bucket_distances(env, elements, pushed, 1);
	}
	(void)i;
	(void)env;
	(void)offset;
	(void)buckets;
	(void)emulation;
	return (moves);
}