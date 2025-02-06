/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_rip.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:46:22 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/06 14:26:33 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	end_everything(t_push_swap *p, t_bool exit_program, int exit_status)
{
	void	*elt;
	void	*next;

	if (p->env)
	{
		if (!p->is_in_stackmem)
			free(p->env->stack_str);
		if (p->env->stacks)
		{
			elt = p->env->stacks[0];
			while (elt)
			{
				if (((t_stack *)elt)->tab)
					free(((t_stack *)elt)->tab);
				next = ((t_stack *)elt)->next;
				free(elt);
				elt = next;
			}
			free(p->env->stacks);
		}
		if (p->env->moves)
		{
			elt = p->env->moves[0];
			while (elt)
			{
				next = ((t_move *)elt)->next;
				free(elt);
				elt = next;
			}
			free(p->env->moves);
		}
		free(p->env);
	}
	free(p);
	if (exit_program)
		exit(exit_status);
}