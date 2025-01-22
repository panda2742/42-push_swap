/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:16:30 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/22 19:56:04 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	display_env(t_env *env)
{
	static int	print_id;

	ft_printf("\n---------- Environment ----------\n");
	ft_printf("| [print_id: %d] [%p]\n", print_id, env);
	ft_printf("| argc: %d\n", env->argc);
	ft_printf("| argv: %p\n", env->argv);
	ft_printf("| stack_str: %p\n", env->stack_a);
	ft_printf("| stack_size: %d\n", env->stack_size);
	ft_printf("| is_in_stackmem: %d\n", env->is_in_stackmem);
	ft_printf("| wall_status: %d\n", env->wall_status);
	ft_printf("| stack_a: %p\n", env->stack_a);
	ft_printf("| a_size: %d\n", env->a_size);
	ft_printf("| a_head: %d\n", env->a_head);
	display_stack(env->stack_a, env->a_size, env->a_head);
	ft_printf("| stack_b: %p\n", env->stack_b);
	ft_printf("| b_size: %d\n", env->b_size);
	ft_printf("| b_head: %d\n", env->b_head);
	display_stack(env->stack_b, env->b_size, env->b_head);
	ft_printf("---------------------------------\n");
	print_id++;
}

void	display_stack(int *stack, size_t stack_size, size_t head)
{
	size_t	iter;

	iter = -1;
	while (++iter < stack_size)
	{
		ft_printf("%d", stack[head]);
		if (iter + 1 < stack_size)
			ft_printf(" | ");
		head++;
		if (head == stack_size)
			head = 0;
	}
	ft_printf("\n");
}
