/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_n_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 00:00:19 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/03 11:01:27 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

int	sort_2(t_stack *s1, t_bool emulation)
{
	if (s1->tab[0] > s1->tab[1])
		return (swap(s1, NULL, !emulation), 1);
	return (0);
}

int	sort_3(t_stack *s1, t_bool emulation)
{
	if (s1->tab[0] > s1->tab[1])
	{
		if (s1->tab[1] > s1->tab[2])
		{
			swap(s1, NULL, !emulation);
			return (reverse_rotate(s1, NULL, !emulation), 2);
		}
		return (rotate(s1, NULL, !emulation), 1);
	}
	if (s1->tab[0] > s1->tab[2])
		return (reverse_rotate(s1, NULL, !emulation), 1);
	reverse_rotate(s1, NULL, !emulation);
	swap(s1, NULL, !emulation);
	return (2);
}
