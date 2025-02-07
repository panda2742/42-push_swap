/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:23:10 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/07 15:32:12 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	_get_nearest_element(t_stack *s, t_bucket *b);
static t_move	**_kick_bucket_from_stack(t_stack *s, t_bucket *b);
static t_stack_buckets	*_create_and_move_buckets(
	t_stack_buckets *sb, t_env *env, int buckets);
static t_move	**_do_move(int dist);

void	bucket_sort(t_push_swap *p, int buckets)
{
	t_stack_buckets	*sb;

	sb = create_stack_buckets();
	sb = _create_and_move_buckets(sb, p->env, buckets);
	display_stack_buckets(sb);
	empty_stack_buckets(sb);
}

static t_stack_buckets	*_create_and_move_buckets(
	t_stack_buckets *sb, t_env *env, int buckets)
{
	t_bucket	*b;
	t_stack		*a;
	int			i;
	t_move		**flow;

	a = get_stack_by_id(env, 'a');
	i = -1;
	flow = create_flow();
	while (++i < buckets)
	{
		b = append_bucket(sb, NULL, 0);
		b->composition = get_bucket_composition(
				i, env->stack_size, buckets, &b->size);
		flow = concat_flow(flow, _kick_bucket_from_stack(a, b), i == 0);
	}
	env->moves = flow;
	display_env(env, 0, false);
	return (sb);
}

static t_move	**_kick_bucket_from_stack(t_stack *s, t_bucket *b)
{
	int	i;
	int	nearest;
	int	size;
	int	head;
	int	dist;
	t_move	**flow;

	i = -1;
	size = s->size;
	head = s->head;
	flow = create_flow();
	while (++i < s->size)
	{
		nearest = _get_nearest_element(s, b);
		dist = distance_to_pos(s->size, head, getpos(s, nearest));
		flow = concat_flow(flow, _do_move(dist), i == 0);
	}
	return (flow);
}

static t_move	**_do_move(int dist)
{
	int		i;
	t_move	**flow;
	t_bool	init;

	i = 0;
	flow = create_flow();
	init = true;
	while (ft_abs(dist))
	{
		display_flow(flow);
		if (dist < 0)
			append_move(flow, RRA, init);
		else
			append_move(flow, RRA, init);
		dist -= ft_sign(dist);
		if (init)
			init = false;
	}
	append_move(flow, PB, init);
	return (flow);
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
		current[1] = distance_to_pos(
				s->size, s->head, getpos(s, b->composition[i]));
		if (ft_abs(current[1]) < ft_abs(nearest[1]))
		{
			nearest[0] = current[0];
			nearest[1] = current[1];
		}
	}
	return (nearest[0]);
}
