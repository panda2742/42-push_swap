/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:21:04 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/13 16:13:05 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	cost_to_move(t_array *src, t_array *dest, int val)
{
	int	cost_to_top;
	int	cost_correct_pos;

	cost_to_top = cost_bring_to_top(src, val);
	cost_correct_pos = ft_abs(cost_to_correct_pos(dest, val));
	return (cost_to_top + cost_correct_pos);
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

int	correct_head(t_array *arr, int val)
{
	int	*tab;
	int	i;
	int	correct_head;
	int	previous;

	tab = ((int *)arr->data);
	i = -1;
	while (++i < arr->size)
	{
		correct_head = ft_array_getval(arr, arr->head, i);
		previous = ft_array_getval(arr, arr->head, i - 1);
		if (correct_head < val)
		{
			continue ;
		}
		else if (previous < val)
		{
			break ;
		}
	}
	return (correct_head);
}

int	cost_to_correct_pos(t_array *arr, int val)
{
	int	head;

	head = correct_head(arr, val);
	return (ft_array_posdist(arr->head, ft_array_getpos(arr, head), arr->size));
}

void	jump_to_val(t_push_swap *p, t_array *arr, int val)
{
	int		path;
	void	(*move_fn)(t_push_swap *, t_array *, t_array *, t_bool);

	if (val == ((int *)arr->data)[arr->head])
		return ;
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
