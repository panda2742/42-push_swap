/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clist_inits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:50:27 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/21 18:01:06 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_clist_node	*create_clist(t_env *env, int is_empty)
{
	t_clist_node	*head;
	t_clist_node	*node;
	size_t			i;

	head = create_head();
	i = -1;
	node = head;
	while (++i < env->stack_size)
	{
		if (is_empty)
		{
			create_node(NODE_EMPTY, 0, node);
			node = node->next;
			continue;
		}
		display_clist(head);
		create_node(NODE_ELEMENT, ft_atoi(env->stack_str[i]), node);
		node = node->next;
	}
	return (head);
}

t_clist_node	*create_head(void)
{
	t_clist_node	*head;

	head = malloc(sizeof(t_clist_node));
	if (!head)
		return (NULL);
	head->type = NODE_HEAD;
	head->value = 0;
	head->previous = head;
	head->next = head;
	return (head);
}

t_clist_node	*create_node(t_node_type type, int val, t_clist_node *previous)
{
	t_clist_node	*element;
	t_clist_node	*next;

	element = malloc(sizeof(t_clist_node));
	if (!element)
		return (NULL);
	element->type = type;
	element->value = val;
	next = previous->next;
	if (next)
	{
		next->previous = element;
		element->next = previous;
	}
	element->previous = previous;
	previous->next = element;
	return (element);
}
