/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_n_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 00:00:19 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/31 13:01:37 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

int	sort_2(t_env *env)
{
	int		*t;

	t = env->stack_a;
	if (t[0] > t[1])
		return (swap(env, 'a', !emulation), 1);
	return (0);
}

int	sort_3(t_env *env, int emulation)
{
	int	*t;

	t = env->stack_a;
	if (t[0] > t[1])
	{
		if (t[1] > t[2])
		{
			swap(env, 'a', !emulation);
			return (reverse_rotate(env, 'a', !emulation), 2);
		}
		return (rotate(env, 'a', !emulation), 1);
	}
	if (t[0] > t[2])
		return (reverse_rotate(env, 'a', !emulation), 1);
	reverse_rotate(env, 'a', !emulation);
	swap(env, 'a', !emulation);
	return (2);
}
