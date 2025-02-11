/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:21:04 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/11 16:29:51 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	cost_to_move(t_array *src, t_array *dest, int val)
{
	int	cost;

	cost = 1;
	cost += cost_bring_to_top(src, val);
	cost += cost_to_correct_pos(dest, val);
	return (cost);
}

int	cost_bring_to_top(t_array *arr, int val)
{
	int	cost;
	int	val_pos;

	cost = 0;
	val_pos = ft_array_getpos(arr, val);
	if (val_pos == arr->head)
		return (cost);
	cost = ft_abs(ft_array_posdist(arr->head, val_pos, arr->size));
	return (cost);
}

int	cost_to_correct_pos(t_array *arr, int val)
{
	int	i;
	int	next_greater;
	int	next_pos;

	i = -1;
	next_greater = ft_array_getval(arr, arr->head, -1);
	while (++i < arr->size)
	{
		next_greater = ft_array_getval(arr, arr->head, i);
		if (next_greater > val)
			break ;
	}
	next_pos = ft_array_getpos(arr, next_greater);
	return (ft_array_posdist(arr->head, next_pos, arr->size));
}

void	jump_to_val(t_push_swap *p, t_array *arr, int val)
{
	int		path;
	void	(*move_fn)(t_push_swap *, t_array *, t_array *, t_bool);

	path = ft_array_posdist(arr->head, ft_array_getpos(arr, val), arr->size);
	move_fn = rotate;
	if (ft_sign(path) == -1)
		move_fn = reverse_rotate;
	while (ft_abs(path))
	{
		move_fn(p, arr, NULL, true);
		path -= ft_sign(path);
	}
}