/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:59:51 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/21 23:28:49 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	_wall_handler(t_env *env);
static void	_stack_handler(t_env *env);

int	main(int argc, char **argv)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (!env)
		return (0);
	env->argc = argc;
	env->argv = argv;
	_wall_handler(env);
	_stack_handler(env);
	if (env->wall_status == WALL_HEAPED)
		free(env->stack_str);
	return (0);
}

static void	_wall_handler(t_env *env)
{
	t_wall_status	checked;

	env->stack_size = 0;
	checked = check_argv(env);
	if (checked == WALL_AVOID)
		exit(EXIT_FAILURE);
	if (checked == WALL_ERROR_HEAPED)
		free(env->stack_str);
	if (checked == WALL_ERROR || checked == WALL_ERROR_HEAPED)
	{
		display_error();
		exit(EXIT_FAILURE);
	}
}

static void	_stack_handler(t_env *env)
{
	t_clist_node	*head;

	head = create_clist(env, 0);
	env->stack_a = &head;
	display_clist(*env->stack_a);
}