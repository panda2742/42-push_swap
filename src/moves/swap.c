/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:45:14 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/04 21:23:36 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	swap(t_stack *s1, t_stack *s2, t_bool print_move)
{
	int	i_to_swap;
	int	tmp;

	if (s2)
	{
		ft_printf("ss\n");
		swap(s1, NULL, false);
		swap(s2, NULL, false);
		return ;
	}
	if (print_move)
		ft_printf("s%c\n", s1->identifier);
	if (s1->size < 2)
		return ;
	i_to_swap = s1->head + 1;
	if (i_to_swap == s1->size)
		i_to_swap = 0;
	tmp = s1->tab[s1->head];
	s1->tab[s1->head] = s1->tab[i_to_swap];
	s1->tab[i_to_swap] = tmp;
}
