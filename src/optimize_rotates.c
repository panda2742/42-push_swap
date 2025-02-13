/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_rotates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:54:44 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/13 22:08:20 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	optimize_rotates(t_push_swap *p)
{
	
}

static t_instruction	*_optimize(t_instruction *head, t_move_id move_id)
{
	t_instruction	*elt;
	t_instruction	*next;
	t_instropt		opt;

	elt = head;
	opt.ma = 0;
	opt.mb = 0;
	while (elt)
	{
		if (elt->move_id - move_id < 0 && elt->move_id - move_id > 1)
		{
			return (elt);
		}
		if (elt->move_id - move_id == 0)
			opt.ma++;
		else
			opt.mb++;
		next = elt->next;
		free(elt);
	}
}