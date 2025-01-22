/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clist_deleters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:32:18 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/22 10:31:25 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	free_clist(t_clist_node *stack)
{
	t_clist_node	*tmp;

	stack = stack->next;
	while (stack->type != NODE_HEAD)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
	free(stack);
}

void	free_stack_str(char **stack_str, size_t stack_size)
{
	size_t	i;

	i = -1;
	while (++i < stack_size)
		free(stack_str[i]);
	free(stack_str);
}