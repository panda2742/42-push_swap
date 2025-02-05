/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:23:10 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/05 17:14:03 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	_get_nearest_element(t_stack *s, t_bucket *b);
t_bucket	*_kick_bucket_from_stack(t_stack *s, t_bucket *b);

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
	int			i;

	a = get_stack_by_id(p->env, 'a');
	i = -1;
	while (++i < buckets)
	{
		b = append_bucket(sb, NULL, 0);
		b->composition = get_bucket_composition(
							a, i, p->env->stack_size, buckets, &b->size);
	}
	display_stack_buckets(sb);
	return (sb);
}

t_bucket	*_kick_bucket_from_stack(t_stack *s, t_bucket *b)
{
	int	i;
	int	nearest;

	i = -1;
	while (++i < s->size)
	{
		nearest = _get_nearest_element(s, b);
		ft_printf("nearest: %d\n", nearest);
	}
	return (b);
}

static int	_get_nearest_element(t_stack *s, t_bucket *b)
{
	int	nearest[2];
	int	current[2];
	int	i;

	nearest[0] = 65000;
	nearest[1] = 65000;
	i = -1;
	while (++i < b->size)
	{
		current[0] = b->composition[i];
		current[1] = distance_to_pos(s->size, s->head, getpos(s, b->composition[i]));
		if (ft_abs(current[1]) < ft_abs(nearest[1]))
		{
			nearest[0] = current[0];
			nearest[1] = current[1];
		}
	}
	return (nearest[0]);
}
