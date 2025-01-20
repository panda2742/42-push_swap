/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:00:57 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/20 15:45:57 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack_node	*init_stack(t_stack_node *stack_a, t_stack_node *stack_b)
{
	stack_a = create_head();
	if (!stack_a)
		return (NULL);
	stack_b = create_head();
	if (!stack_b)
	{
		free(stack_a);
		return (NULL);
	}
	return (stack_a);
}

t_stack_node	*append_to_stack(
	const char *stack_elt,
	t_stack_node *stack_a,
	t_stack_node *stack_b
)
{
	int	value;
	t_stack_node	*elt;
	t_stack_node	*empty_cell;

	value = ft_atoi(stack_elt);
	elt = create_element(&stack_a, value);
	if (!elt)
		return (NULL);
	empty_cell = create_empty_cell(&stack_b);
	if (!empty_cell)
	{
		free(elt);
		return (NULL);
	}
	return (stack_a);
}
