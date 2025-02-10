/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:46:22 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/10 14:39:31 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	_free_env_moves(t_push_swap *p);

void	terminate(t_push_swap *p, t_bool exit_program, int exit_status)
{
	if (!p->is_in_stackmem)
		ft_free_strtab(p->stack_str);
	ft_array_clear(p->a);
	ft_array_clear(p->b);
	if (p->moves)
	{
		_free_env_moves(p);
		free(p->moves);
	}
	free(p);
	if (exit_program)
		exit(exit_status);
}

static void	_free_env_moves(t_push_swap *p)
{
	t_move	*elt;
	t_move	*next;

	elt = p->moves[0];
	while (elt)
	{
		next = elt->next;
		free(elt);
		elt = next;
	}
}
