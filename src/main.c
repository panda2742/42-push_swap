/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:59:51 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/23 11:32:01 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	_wall_handler(t_env *env);
static void	_stack_handler(t_env *env);
static void	_exit_program(t_env *env, int free_stacks, int exit_status);

int	main(int argc, char **argv)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (!env)
		return (0);
	env->argc = argc;
	env->argv = argv;
	env->is_in_stackmem = 1;
	env->stack_size = 0;
	env->stack_a = NULL;
	env->stack_b = NULL;
	env->b_size = 0;
	env->a_head = 0;
	env->b_head = 0;
	_wall_handler(env);
	env->a_size = env->stack_size;
	_stack_handler(env);
	_exit_program(env, 1, -1);
	return (0);
}

static void	_wall_handler(t_env *env)
{
	env->stack_size = 0;
	env->wall_status = check_argv(env);
	if (env->wall_status == WALL_AVOID)
		_exit_program(env, 0, EXIT_FAILURE);
	if (env->wall_status == WALL_ERROR)
	{
		display_error();
		_exit_program(env, 0, EXIT_FAILURE);
	}
}

static void	_stack_handler(t_env *env)
{
	env->stack_a = init_stack(env, 0);
	env->stack_b = init_stack(env, 1);
	display_stack(env, 'a');
	display_stack(env, 'b');
	rotate(env, 'a', 1);
	push(env, 'a', 1);
	push(env, 'a', 1);
	push(env, 'a', 1);
	rotate(env, 'r', 1);
	push(env, 'a', 1);
	push(env, 'a', 1);
	push(env, 'a', 1);
	rotate(env, 'r', 1);
	display_stack(env, 'a');
	display_stack(env, 'b');
}

static void	_exit_program(t_env *env, int free_stacks, int exit_status)
{
	(void)free_stacks;
	if (!env->is_in_stackmem)
		free_stack_str(env->stack_str, env->stack_size);
	if (env->stack_a)
		free(env->stack_a);
	if (env->stack_b)
		free(env->stack_b);
	free(env);
	if (exit_status != -1)
		exit(exit_status);
}
