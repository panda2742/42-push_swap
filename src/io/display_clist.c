/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_clist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:14:04 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/21 23:25:48 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	display_clist(t_clist_node *head)
{
	t_clist_node	*element;

	display_clist_node(head);
	element = head->next;
	int i = 0;
	while (element->type != NODE_HEAD && i < 10)
	{
		display_clist_node(element);
		element = element->next;
		i++;
	}
}

void	display_clist_node(t_clist_node *element)
{
	ft_printf("%p\t", element);
	if (element->type == NODE_ELEMENT)
		ft_printf("%d", element->value);
	else if (element->type == NODE_EMPTY)
		ft_printf("x");
	else if (element->type == NODE_HEAD)
		ft_printf("HEAD");
	ft_printf("\t%p\n", element->next);
	if (element->next->type != NODE_HEAD)
	{
		ft_printf("\t\t⋁\n");
	}
}
