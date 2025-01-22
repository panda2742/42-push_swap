/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:59:51 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/22 11:27:03 by ehosta           ###   ########.fr       */
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
	env->stack_a = NULL;
	env->stack_b = NULL;
	env->is_in_stack = 1;
	env->stack_size = 0;
	_wall_handler(env);
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
	t_clist_node	*head;
	t_clist_node	*empty_head;

	env->stack_a = malloc(sizeof(t_clist_node *));
	if (!env->stack_a)
		_exit_program(env, 0, EXIT_FAILURE);
	env->stack_b = malloc(sizeof(t_clist_node *));
	if (!env->stack_b)
	{
		free(env->stack_a);
		env->stack_a = NULL;
		_exit_program(env, 0, EXIT_FAILURE);
	}
	head = create_clist(env, 0);
	empty_head = create_clist(env, 1);
	env->stack_a[0] = head;
	env->stack_b[0] = empty_head;
}

static void	_exit_program(t_env *env, int free_stacks, int exit_status)
{
	(void)free_stacks;
	if (!env->is_in_stack)
		free_stack_str(env->stack_str, env->stack_size);
	if (env->stack_a)
		free_clist(*env->stack_a);
	if (env->stack_b)
		free_clist(*env->stack_b);
	free(env->stack_a);
	free(env->stack_b);
	free(env);
	if (exit_status != -1)
		exit(exit_status);
}
