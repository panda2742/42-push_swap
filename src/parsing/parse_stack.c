/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:38:42 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/20 14:40:44 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack_node	*parse_stack(
	const char **stack_str,
	size_t len,
	t_stack_node *stack_b
)
{
	t_stack_node	*stack_a;
	t_stack_node	*tmp;
	size_t			i;
	
	if (!init_stack(stack_a, stack_b))
		return (NULL);
	i = -1;
	while (++i < len)
	{
		if ()
	}
}
