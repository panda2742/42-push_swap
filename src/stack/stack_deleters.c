/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_deleters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:53:47 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/20 16:17:37 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	free_stack_str(const char **str, size_t len)
{
	size_t	i;

	i = -1;
	while (++i < len)
		free(str[i]);
}

void	free_stack_nodes(t_stack_node **stack)
{
	const t_stack_node	*first = stack_first(*stack);
	t_stack_node		*tmp;

	tmp = first;
	while (tmp->type != STACK_HEAD)
	{
		tmp = tmp->next;
		free(tmp->previous);
	}
	free(tmp->previous);
	free(tmp);
}