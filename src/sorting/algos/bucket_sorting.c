/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:23:10 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/28 16:03:08 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

static int	_push_until_median(t_env *env, int buckets, int offset, int emulation, int elt_per_bucket);
static int	_travel_throught_stack(t_env *env, int *elements);
static int	*_nearest_combination(t_env *env, int offset, int elt_per_bucket);

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
		moves = 0;
		i = -1;
		printf("buckets: %d = %d/bkt\n", buckets, env->stack_size / buckets + (1 * (env->stack_size % buckets != 0)));
		display_stack(env, 'a');
		printf("\n");
		while (++i < buckets)
			moves += _push_until_median(env, buckets, i, emulation, env->stack_size / buckets + (1 * (env->stack_size % buckets != 0)));
		if (moves < max_moves)
		{
			max_moves = moves;
			max_buckets = buckets;
		}
		printf("\n----------------------\n");
	}
	(void)env;
	(void)emulation;
	return (max_moves);
}

static int	_push_until_median(t_env *env, int buckets, int offset, int emulation, int elt_per_bucket)
{
	int	moves;
	int	pushed;
	int	i;
	int	*elements;

	moves = 0;
	pushed = 0;
	i = -1;
	if ((++i + 1) && pushed < elt_per_bucket)
	{
		elements = _nearest_combination(env, offset, elt_per_bucket);
		_travel_throught_stack(env, elements);
	}
	(void)i;
	(void)env;
	(void)offset;
	(void)buckets;
	(void)emulation;
	return (moves);
}

static int	_travel_throught_stack(t_env *env, int *elements)
{
	int	i;

	i = -1;
	while (elements[++i] != -1)
	{
		distance_to_pos(env->a_size, env->a_head, getpos(env->stack_a, elements[i], env->a_size));
	}
	free(elements);
	return (0);
}

static int	*_nearest_combination(t_env *env, int offset, int elt_per_bucket)
{
	int	*elements;
	int	pushed;
	int	i;

	elements = malloc((elt_per_bucket + 1) * sizeof(int));
	if (!elements)
		return (NULL);
	pushed = 0;
	i = -1;
	while (++i < elt_per_bucket && (elt_per_bucket * offset + i) < env->a_size)
	{
		elements[i] = env->a_size - (elt_per_bucket * offset + i + 1);
		pushed++;
	}
	elements[i] = -1;
	printf("elements: %p (%d)\n", elements, pushed);
	display_inttab(elements, pushed, 0);
	return (elements);
}
