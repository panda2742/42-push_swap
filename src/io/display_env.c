/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:16:30 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/22 11:13:51 by ehosta           ###   ########.fr       */
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
	ft_printf("| is_in_stack: %d\n", env->is_in_stack);
	ft_printf("| wall_status: %d\n", env->wall_status);
	ft_printf("| stack_a: %p\n", env->stack_a);
	if (env->stack_a)
		display_clist(*env->stack_a);
	ft_printf("| stack_b: %p\n", env->stack_b);
	if (env->stack_b)
		display_clist(*env->stack_b);
	ft_printf("---------------------------------\n");
	print_id++;
}