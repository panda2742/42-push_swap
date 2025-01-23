/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:02:55 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/24 00:26:24 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

static int	_is_sorted(t_env *env);

void	stack_sorting(t_env *env)
{
	if (_is_sorted(env))
		return ;
	if (env->a_size >= 3)
		sort_3(env);
	(void)env;
}

static int	_is_sorted(t_env *env)
{
	size_t	i;
	size_t	j;

	if (env->a_size != env->stack_size)
		return (0);
	i = -1;
	j = env->a_head - 1;
	while (++i < env->stack_size)
	{
		++j;
		if (j == env->a_head)
			j = 0;
		if (env->stack_a[j] != env->sorted_stack[i])
			return (0);
	}
	return (1);
}
