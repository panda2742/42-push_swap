/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:59:51 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/04 17:20:13 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	_wall_handler(t_push_swap *p);
static void	_stack_handler(t_push_swap *p);
static void	_sort_handler(t_push_swap *p);

int	main(int argc, char **argv)
{
	t_env		*p_env;
	t_push_swap	*p;

	// Leaks checks
	const char command[50];
	int	pid = getpid();
	sprintf((char *)command, "leaks %d > memory_traces/%d.trace", pid, pid);
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
	// display_push_swap(p);
	end_everything(p, false, EXIT_SUCCESS);
	// system(command);
	return (EXIT_SUCCESS);
}

static void	_wall_handler(t_push_swap *p)
{
	p->env->stack_size = 0;
	p->wall_status = check_argv(p);
	if (p->wall_status == WALL_AVOID)
		end_everything(p, true, EXIT_FAILURE);
	if (p->wall_status == WALL_ERROR)
	{
		ft_printf("Error\n");
		end_everything(p, true, EXIT_FAILURE);
	}
}

static void	_stack_handler(t_push_swap *p)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*c;

	a = create_stack(p->env->stack_size, 'a');
	if (!a)
		end_everything(p, true, EXIT_FAILURE);
	b = create_stack(p->env->stack_size, 'b');
	if (!b)
		end_everything(p, true , EXIT_FAILURE);
	a = feed_stack(a, string_stack, p->env->stack_str, p->env->stack_size);
	c = create_stack(p->env->stack_size, 'c');
	if (!c)
		end_everything(p, true, EXIT_FAILURE);
	c = sort_and_replace_by_index(c, a, p->env->stack_size);
	b->next = c;
	a->next = b;
	p->env->stacks[0] = a;
}

static void	_sort_handler(t_push_swap *p)
{
	t_stack	*a;

	if (is_sorted(p->env))
		return ;
	a = get_stack_by_id(p->env, 'a');
	if (a->size == 2)
		sort_2(a, false);
	else if (a->size == 3)
		sort_3(a, false);
	else
		bucket_sort(p);
}
