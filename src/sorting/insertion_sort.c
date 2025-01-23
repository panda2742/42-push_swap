/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:36:34 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/23 15:42:46 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	insertion_sort(int *list, int length)
{
	int	i;
	int	j;
	int	key;

	i = 0;
	while (++i < length)
	{
		key = list[i];
		j = i - 1;
		while (list[j] > key && j >= 0)
		{
			list[j + 1] = list[j];
			j--;
		}
		list[j + 1] = key;
	}
}
