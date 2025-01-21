/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clist_inits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:50:27 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/21 23:32:29 by ehosta           ###   ########.fr       */
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
			create_node(NODE_EMPTY, 0, node, head);
			node = node->next;
			continue;
		}
		create_node(NODE_ELEMENT, ft_atoi(env->stack_str[i]), node, head);
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
	head->next = NULL;
	return (head);
}

t_clist_node	*create_node(t_node_type type, int val, t_clist_node *previous, t_clist_node *head)
{
	t_clist_node	*element;

	element = malloc(sizeof(t_clist_node));
	if (!element)
		return (NULL);
	element->type = type;
	element->value = val;
	element->next = NULL;

	previous->next = element;
	element->next = head;
	return (element);
}
