/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:09:10 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/03 10:51:12 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	reverse_rotate(t_stack *s1, t_stack *s2, t_bool print_move)
{
	if (s2)
	{
		ft_printf("rrr\n");
		reverse_rotate(s1, NULL, false);
		reverse_rotate(s2, NULL, false);
		return ;
	}
	if (print_move)
		ft_printf("rr%c\n", s1->identifier);
	if (s1->size < 2)
		return ;
	if (s1->head == 0)
		s1->head = s1->size - 1;
	else
		s1->head -= 1;
}
