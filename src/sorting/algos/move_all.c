/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:23:10 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/27 14:45:38 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

int	move_reverse_all(t_env *env, int emulation)
{
	int	i;
	int	original_size;
	int	moves;

	i = -1;
	moves = 0;
	original_size = env->a_size;
	while (++i < original_size)
	{
		if (env->stack_a[env->a_head] > 2)
			push(env, 'a', !emulation);
		else
			rotate(env, 'a', !emulation);
		moves++;
	}
	return (moves);
}

int	everything_ascending(t_env *env, int emulation)
{
	int	i;
	int	original_size;
	int	moves;

	i = -1;
	moves = 0;
	original_size = env->a_size;
	while (++i < original_size)
	{
		if (env->stack_a[env->a_head] > 2)
			push(env, 'a', !emulation);
		else
			rotate(env, 'a', !emulation);
		moves++;
	}
	return (moves);
}
