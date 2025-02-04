/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:05:29 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/04 21:27:43 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_push_swap	*create_push_swap(int argc, char **argv)
{
	t_push_swap	*push_swap;

	push_swap = malloc(sizeof(t_push_swap));
	if (!push_swap)
		return (NULL);
	push_swap->argc = argc;
	push_swap->argv = argv;
	push_swap->is_in_stackmem = true;
	push_swap->wall_status = WALL_OK;
	push_swap->env = NULL;
	return (push_swap);
}

void	end_everything(t_push_swap *p, t_bool exit_program, int exit_status)
{
	t_stack	*elt;
	t_stack	*next;

	if (p->env)
	{
		if (!p->is_in_stackmem)
			free(p->env->stack_str);
		if (p->env->stacks)
		{
			elt = p->env->stacks[0];
			while (elt)
			{
				if (elt->tab)
					free(elt->tab);
				next = elt->next;
				free(elt);
				elt = next;
			}
			free(p->env->stacks);
		}
		free(p->env);
	}
	free(p);
	if (exit_program)
		exit(exit_status);
}
