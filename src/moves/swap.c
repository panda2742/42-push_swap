/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:45:14 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/22 15:18:18 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	_exe_swap(int *target, size_t target_size, size_t target_head);

void	swap(t_env *env, char c, int to_print)
{
	int		*target;
	size_t	target_size;
	size_t	target_head;

	if (c == 's')
	{
		ft_printf("ss\n");
		swap(env, 'a', 0);
		swap(env, 'b', 0);
		return ;
	}
	if (to_print)
		ft_printf("s%c\n", c);
	target = env->stack_a;
	target_size = env->a_size;
	target_head = env->a_head;
	if (c == 'b')
	{
		target = env->stack_b;
		target_size = env->b_size;
		target_head = env->b_head;
	}
	return (_exe_swap(target, target_size, target_head));
}

static void	_exe_swap(int *target, size_t target_size, size_t target_head)
{
	int		tmp;
	size_t	i_to_swap;

	if (target_size < 2)
		return ;
	i_to_swap = target_head + 1;
	if (i_to_swap == target_size)
		i_to_swap = 0;
	tmp = target[target_head];
	target[target_head] = target[i_to_swap];
	target[i_to_swap] = tmp;
}
