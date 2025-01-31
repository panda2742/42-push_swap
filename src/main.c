/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:59:51 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/31 11:44:53 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	_wall_handler(t_push_swap *p);
static void	_stack_handler(t_push_swap *p);
static void	_sort_handler(t_push_swap *p);
static void	_exit_program(t_push_swap *p, int exit_status);

int	main(int argc, char **argv)
{
	t_env		*p_env;
	t_push_swap	*p;

	p = create_push_swap(argc, argv);
	if (!p)
		return (EXIT_FAILURE);
	p_env = create_env();
	if (!p_env)
		return (free(p), EXIT_FAILURE);
	p->env = p_env;
	_wall_handler(p);
	_stack_handler(p);
	_sort_handler(p);
	_exit_program(p, -1);
	return (EXIT_SUCCESS);
}

static void	_wall_handler(t_push_swap *p)
{
	p->env->stack_size = 0;
	p->wall_status = check_argv(p);
	if (p->wall_status == WALL_AVOID)
		_exit_program(p, EXIT_FAILURE);
	if (p->wall_status == WALL_ERROR)
	{
		ft_printf("Error\n");
		_exit_program(p, EXIT_FAILURE);
	}
}

static void	_stack_handler(t_push_swap *p)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*c;

	a = create_stack(p->env->stack_size, 'a');
	if (!a)
		_exit_program(p, EXIT_FAILURE);
	b = create_stack(p->env->stack_size, 'b');
	if (!b)
		_exit_program(p, EXIT_FAILURE);
	a = feed_stack(a, string_stack, p->env->stack_str, p->env->stack_size);
	c = create_stack(p->env->stack_size, 'c');
	if (!c)
		_exit_program(p, EXIT_FAILURE);
	c = sort_and_replace_by_index(c, a, p->env->stack_size);
	b->next = c;
	a->next = b;
	p->env->stacks[0] = a;
}

static void	_sort_handler(t_push_swap *p)
{
	if (is_sorted(p->env))
		return ;
	// else if (env->a_size == 2)
	// 	sort_2(env, 0);
	// else if (env->a_size == 3)
	// 	sort_3(env, 0);
	// else
	// 	sort(env);
}

static void	_exit_program(t_push_swap *p, int exit_status)
{
	if (exit_status != -1)
		exit(exit_status);
}
