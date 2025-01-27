/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:16:30 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/27 14:41:19 by ehosta           ###   ########.fr       */
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
	display_stack(env, 'a');
	ft_printf("| stack_b: %p\n", env->stack_b);
	ft_printf("| b_size: %d\n", env->b_size);
	ft_printf("| b_head: %d\n", env->b_head);
	display_stack(env, 'b');
	ft_printf("---------------------------------\n");
	print_id++;
}

void	display_stack(t_env *env, char c)
{
	int	iter;
	int	*stack;
	int	stack_size;
	int	head;

	stack = env->stack_a;
	stack_size = env->a_size;
	head = env->a_head;
	if (c == 'b')
	{
		stack = env->stack_b;
		stack_size = env->b_size;
		head = env->b_head;
	}
	if (c == 's')
	{
		stack = env->sorted_stack;
		stack_size = env->stack_size;
		head = 0;
	}
	iter = -1;
	while (++iter < stack_size)
	{
		if (iter == head)
			ft_printf(". %d", stack[iter]);
		else
			ft_printf("%d", stack[iter]);
		if (iter + 1 < stack_size)
			ft_printf(" ");
	}
	ft_printf("\n");
}
