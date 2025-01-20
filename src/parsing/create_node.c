/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:42:16 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/20 14:52:34 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack_node	*create_head(void)
{
	t_stack_node	*head;
	
	head = malloc(sizeof(t_stack_node));
	if (!head)
		return (NULL);
	head->first = head;
	head->last = head;
	head->next = NULL;
	head->previous = NULL;
	head->type = STACK_HEAD;
	head->value = 0;
	return (head);
}

t_stack_node	*create_element(t_stack_node **parent, int value)
{
	t_stack_node	*elt;

	elt = malloc(sizeof(t_stack_node));
	if (!elt)
		return (NULL);
	elt->next = NULL;
	elt->type = STACK_ELEMENT;
	elt->value = value;
	return (elt);
}