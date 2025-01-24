/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_n_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 00:00:19 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/24 17:29:16 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_2(t_env *env)
{
	int		*t;

	t = env->stack_a;
	if (t[0] > t[1])
		sa(env);
}

void	sort_3(t_env *env)
{
	int		*t;

	t = env->stack_a;
	if (t[0] > t[1] && t[0] > t[2])
		ra(env);
	else if (t[1] > t[0] && t[1] > t[2])
		rra(env);
	if (t[0] > t[1])
		sa(env);
}
