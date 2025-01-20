/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:42:16 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/20 15:41:12 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack_node	*create_head(void)
{
	t_stack_node	*head;
	
	head = malloc(sizeof(t_stack_node));
	if (!head)
		return (NULL);
	head->next = NULL;
	head->previous = NULL;
	head->type = STACK_HEAD;
	head->value = 0;
	return (head);
}

t_stack_node	*create_element(t_stack_node **parent, int value)
{
	t_stack_node	*elt;
	t_stack_node	*last;

	elt = malloc(sizeof(t_stack_node));
	if (!elt)
		return (NULL);
	last = stack_last(*parent);
	elt->next = NULL;
	elt->type = STACK_ELEMENT;
	elt->value = value;
	elt->previous = last;
	last->next = elt;
	return (elt);
}

t_stack_node	*create_empty_cell(t_stack_node **parent)
{
	t_stack_node	*elt;
	t_stack_node	*last;

	elt = malloc(sizeof(t_stack_node));
	if (!elt)
		return (NULL);
	last = stack_last(*parent);
	elt->next = NULL;
	elt->type = STACK_EMPTY_CELL;
	elt->value = 0;
	elt->previous = last;
	last->next = elt;
	return (elt);
}