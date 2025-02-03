/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:23:10 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/03 12:58:43 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

int	bucket_sort(t_push_swap *p)
{
	int	buckets;
	int	moves;
	int	max_buckets;
	int	max_moves;
	int	i;

	buckets = 0;
	max_buckets = 0;
	max_moves = 65000;
	while (++buckets < p->env->stack_size / 2)
	{
		buckets = 2;
		moves = 0;
		i = -1;
		if (moves < max_moves)
		{
			max_moves = moves;
			max_buckets = buckets;
		}
		break ;
	}
	return (max_moves);
}