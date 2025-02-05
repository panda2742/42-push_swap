/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   black_hole.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:46:22 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/05 12:46:46 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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