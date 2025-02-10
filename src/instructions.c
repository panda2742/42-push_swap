/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:04:13 by ehosta            #+#    #+#             */
/*   Updated: 2025/02/10 16:43:03 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_array *arr1, t_array *arr2, t_bool print_move)
{
	int	i_to_swap;
	int	tmp;

	if (arr2)
	{
		ft_printf("ss\n");
		swap(arr1, NULL, false);
		swap(arr2, NULL, false);
		return ;
	}
	if (print_move)
		ft_printf("s%c\n", arr1->id);
	if (arr1->size < 2)
		return ;
	i_to_swap = arr1->head + 1;
	if (i_to_swap == arr1->size)
		i_to_swap = 0;
	tmp = ((int *)arr1->data)[arr1->head];
	((int *)arr1->data)[arr1->head] = ((int *)arr1->data)[i_to_swap];
	((int *)arr1->data)[i_to_swap] = tmp;
}


void	rotate(t_array *arr1, t_array *arr2, t_bool print_move)
{
	if (arr2)
	{
		ft_printf("rr\n");
		rotate(arr1, NULL, print_move);
		rotate(arr2, NULL, print_move);
		return ;
	}
	if (print_move)
		ft_printf("r%c\n", arr1->id);
	if (arr1->size < 2)
		return ;
	if (arr1->head == arr1->size - 1)
		arr1->head = 0;
	else
		arr1->head += 1;
}


void	reverse_rotate(t_array *arr1, t_array *arr2, t_bool print_move)
{
	if (arr2)
	{
		ft_printf("rrr\n");
		reverse_rotate(arr1, NULL, false);
		reverse_rotate(arr2, NULL, false);
		return ;
	}
	if (print_move)
		ft_printf("rr%c\n", arr1->id);
	if (arr1->size < 2)
		return ;
	if (arr1->head == 0)
		arr1->head = arr1->size - 1;
	else
		arr1->head -= 1;
}

void	push(t_array *arr1, t_array *arr2, t_bool print_move)
{
	int	elt;

	if (print_move)
		ft_printf("p%c\n", arr1->id);
	elt = ft_array_popint(arr2, arr2->head);
	ft_array_pushint(arr1, elt);
}
