/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:39:10 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/05 16:18:22 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static t_stack	**_dup_stacks(t_env *emu, t_env *env);

t_env	*create_env(void)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->stack_size = 0;
	env->stack_str = NULL;
	env->is_copy = false;
	env->moves = malloc(sizeof(t_move *));
	env->stacks = malloc(sizeof(t_stack *));
	return (env);
}

t_env	*create_emulation(t_env *env)
{
	t_env	*emu;

	emu = create_env();
	if (!emu)
		return (NULL);
	emu->stack_size = env->stack_size;
	emu->stack_str = env->stack_str;
	emu->is_copy = true;
	emu->stacks = malloc(sizeof(t_stack *));
	emu->stacks = _dup_stacks(emu, env);
	return (emu);
}

static t_stack	**_dup_stacks(t_env *emu, t_env *env)
{
	t_stack	*elt;
	t_stack	*emu_elt;
	t_stack	*emu_last;

	elt = env->stacks[0];
	emu_last = NULL;
	while (elt)
	{
		emu_elt = create_stack(elt->size, elt->identifier);
		emu_elt->head = elt->head;
		feed_stack(emu_elt, int_stack, elt->tab, elt->size);
		if (!emu_last)
		{
			emu->stacks[0] = emu_elt;
			emu_last = emu_elt;
		}
		else
		{
			emu_last->next = emu_elt;
			emu_last = emu_elt;
		}
		elt = elt->next;
	}
	return (emu->stacks);
}
