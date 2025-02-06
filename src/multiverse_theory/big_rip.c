/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_rip.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:46:22 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/06 14:57:14 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	_free_env_stacks(t_env *env);
static void	_free_env_moves(t_env *env);
static void	_free_strlst(char **strlst);

void	end_everything(t_push_swap *p, t_bool exit_program, int exit_status)
{
	if (p->env)
	{
		if (!p->is_in_stackmem)
			_free_strlst(p->env->stack_str);
		if (p->env->stacks)
		{
			_free_env_stacks(p->env);
			free(p->env->stacks);
		}
		if (p->env->moves)
		{
			_free_env_moves(p->env);
			free(p->env->moves);
		}
		free(p->env);
	}
	free(p);
	if (exit_program)
		exit(exit_status);
}

static void	_free_env_stacks(t_env *env)
{
	t_stack	*elt;
	t_stack	*next;

	elt = env->stacks[0];
	while (elt)
	{
		if (elt->tab)
			free(elt->tab);
		next = elt->next;
		free(elt);
		elt = next;
	}
}

static void	_free_env_moves(t_env *env)
{
	t_move	*elt;
	t_move	*next;

	elt = env->moves[0];
	while (elt)
	{
		next = elt->next;
		free(elt);
		elt = next;
	}
}

static void	_free_strlst(char **strlst)
{
	int		i;

	i = 0;
	while (strlst[i])
	{
		free(strlst[i]);
		i++;
	}
	free(strlst);
}
