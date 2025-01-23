/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:27:07 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/23 11:32:57 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	push_to_stack(int *tab, size_t head, size_t *size, int elt)
{
	size_t	i;

	i = *size;
	*size += 1;
	while (i > head)
	{
		tab[i] = tab[i - 1];
		i--;
	}
	tab[i] = elt;
}
