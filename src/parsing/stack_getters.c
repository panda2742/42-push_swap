/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_getters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:52:43 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/20 15:05:45 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack_node	*stack_last(t_stack_node *stack_elt)
{
	t_stack_node	*tmp;

	if (stack_elt->type == STACK_HEAD && !stack_elt->previous)
		return (NULL);
	tmp = stack_elt->previous;
	while (stack_elt->type != STACK_HEAD)
	{
		tmp = stack_elt;
	}
}