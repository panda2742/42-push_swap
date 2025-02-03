/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:23:32 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/03 10:53:16 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rotate(t_stack *s1, t_stack *s2, t_bool print_move)
{
	if (s2)
	{
		ft_printf("rr\n");
		rotate(s1, NULL, print_move);
		rotate(s2, NULL, print_move);
		return ;
	}
	if (print_move)
		ft_printf("r%c\n", s1->identifier);
	if (s1->size < 2)
		return ;
	if (s1->head == s1->size - 1)
		s1->head = 0;
	else
		s1->head += 1;
}
