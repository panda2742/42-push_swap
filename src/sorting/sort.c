/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:00:27 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/26 14:08:18 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	_move_until_3(t_env *env);

void	sort(t_env *env)
{
	_move_until_3(env);
	sort_3(env);
}

static void	_move_until_3(t_env *env)
{
	ssize_t	i;
	size_t	original_size;

	i = -1;
	original_size = env->a_size;
	while ((size_t)++i < original_size)
	{
		if (env->stack_a[env->a_head] > 2)
			pa(env);
		else
			ra(env);
	}
}
