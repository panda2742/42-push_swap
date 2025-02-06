/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:23:10 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/06 17:00:28 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	_get_nearest_element(t_stack *s, t_bucket *b);
t_bucket	*_kick_bucket_from_stack(t_env *env, t_stack *s, t_bucket *b);
static t_stack_buckets	*_create_and_move_buckets(
	t_stack_buckets *sb, t_env *env, int buckets);
static t_move	*_do_move(t_move *m, int dist);

void	bucket_sort(t_push_swap *p, int buckets)
{
	t_stack_buckets	*sb;
	t_move			*a;

	sb = create_stack_buckets();
	sb = _create_and_move_buckets(sb, p->env, buckets);
	display_stack_buckets(sb);
	a = create_move(NULL, SA);
	p->env->moves[0] = a;
	empty_stack_buckets(sb);
}

static t_stack_buckets	*_create_and_move_buckets(
	t_stack_buckets *sb, t_env *env, int buckets)
{
	t_bucket	*b;
	t_stack		*a;
	int			i;

	a = get_stack_by_id(env, 'a');
	i = -1;
	while (++i < buckets)
	{
		b = append_bucket(sb, NULL, 0);
		b->composition = get_bucket_composition(
				i, env->stack_size, buckets, &b->size);
		_kick_bucket_from_stack(env, a, b);
	}
	return (sb);
}

t_bucket	*_kick_bucket_from_stack(t_env *env, t_stack *s, t_bucket *b)
{
	int	i;
	int	nearest;
	int	size;
	int	head;
	int	dist;
	t_move	*m;

	i = -1;
	size = s->size;
	head = s->head;
	m = NULL;
	while (++i < s->size)
	{
		nearest = _get_nearest_element(s, b);
		dist = distance_to_pos(s->size, head, getpos(s, nearest));
		m = _do_move(m, dist);
	}
	env->moves[0] = m;
	return (b);
}

static t_move	*_do_move(t_move *m, int dist)
{
	int		i;

	i = 0;
	while (ft_abs(dist))
	{
		if (dist < 0)
			m = create_move(m, RRA);
		else
			m = create_move(m, RA);
		dist -= ft_sign(dist);
	}
	return (m);
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
