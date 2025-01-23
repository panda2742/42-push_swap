/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_n_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 00:00:19 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/24 00:25:14 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

void	sort_3(t_env *env)
{
	int	*t;

	t = env->stack_a;
	if (t[0] > t[1])
	{
		if (t[1] > t[2])
		{
			sa(env);
			return (rra(env));
		}
		return (ra(env));
	}
	if (t[0] > t[2])
		return (rra(env));
	ra(env);
	sa(env);
	rra(env);
}
