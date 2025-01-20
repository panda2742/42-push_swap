/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:48:28 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/20 17:04:39 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	display_stacks(t_stack_node *stack_a, t_stack_node *stack_b)
{
	t_stack_node	*elt_a;
	t_stack_node	*elt_b;
	size_t			i;

	ft_printf("\n________ Stacks ________");
	elt_a = stack_first(stack_a);
	elt_b = stack_first(stack_b);
	
	ft_printf("\n%d\t|\t%d");
	ft_printf("\n________________________");
}