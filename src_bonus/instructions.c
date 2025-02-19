/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:04:13 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/19 16:39:29 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	swap(t_array *arr1, t_array *arr2)
{
	int	i_to_swap;
	int	tmp;

	if (arr2)
	{
		swap(arr1, NULL);
		swap(arr2, NULL);
		return ;
	}
	if (arr1->size < 2)
		return ;
	i_to_swap = arr1->head + 1;
	if (i_to_swap == arr1->size)
		i_to_swap = 0;
	tmp = ((int *)arr1->data)[arr1->head];
	((int *)arr1->data)[arr1->head] = ((int *)arr1->data)[i_to_swap];
	((int *)arr1->data)[i_to_swap] = tmp;
}

void	rotate(t_array *arr1, t_array *arr2)
{
	if (arr2)
	{
		rotate(arr1, NULL);
		rotate(arr2, NULL);
		return ;
	}
	if (arr1->size < 2)
		return ;
	if (arr1->head == arr1->size - 1)
		arr1->head = 0;
	else
		arr1->head += 1;
}

void	reverse_rotate(t_array *arr1, t_array *arr2)
{
	if (arr2)
	{
		reverse_rotate(arr1, NULL);
		reverse_rotate(arr2, NULL);
		return ;
	}
	if (arr1->size < 2)
		return ;
	if (arr1->head == 0)
		arr1->head = arr1->size - 1;
	else
		arr1->head -= 1;
}

void	push(t_array *arr1, t_array *arr2)
{
	int	elt;

	elt = ft_array_popint(arr1, arr1->head);
	ft_array_pushint(arr2, elt);
}
