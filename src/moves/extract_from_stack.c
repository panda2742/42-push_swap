/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_from_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 01:02:44 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/23 09:35:26 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	extract_from_stack(int *tab, size_t head, size_t *size)
{
	int		elt;
	size_t	i;

	elt = tab[head];
	if (head + 1 == *size)
	{
		*size -= 1;
		head = 0;
		return (elt);
	}
	i = head - 1;
	while (++i + 1 < *size)
		tab[i] = tab[i + 1];
	*size -= 1;
	return (elt);
}
