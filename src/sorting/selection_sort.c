/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:36:34 by ehosta            #+#    #+#             */
/*   Updated: 2025/01/28 14:33:39 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	selection_sort(int *list, int length)
{
	int	i;
	int	j;
	int	min;
	int	tmp;

	i = -1;
	while (++i < length - 1)
	{
		min = i;
		j = i;
		while (++j < length)
		{
			if (list[j] < list[min])
				min = j;
		}
		if (min != i)
		{
			tmp = list[min];
			list[min] = list[i];
			list[i] = tmp;
		}
	}
}

void	mirror_selection_sort(int *list, int length, int *pair)
{
	int	i;
	int	j;
	int	min;
	int	tmp;

	i = -1;
	while (++i < length - 1)
	{
		min = i;
		j = i;
		while (++j < length)
		{
			if (list[j] < list[min])
				min = j;
		}
		if (min != i)
		{
			tmp = list[min];
			list[min] = list[i];
			list[i] = tmp;
			tmp = pair[min];
			pair[min] = pair[i];
			pair[i] = tmp;
		}
	}
}
